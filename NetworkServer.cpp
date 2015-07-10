//
//  NetworkServer.cpp
//  Squares
//
//  Created by rocker on 20150704.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "NetworkServer.h"

NetworkServer::NetworkServer() {
};

NetworkServer::NetworkServer(PlayerServer players[12], MapServer map) {
    *m_players = players;
    m_map = map;
    socket.bind(26000);
    socket.setBlocking(false);
}

void NetworkServer::update() {
    receivePackets();
    broadcastUpdate();
}

std::queue<ClientMove>& NetworkServer::getMoves() {
    return moves;
}

void NetworkServer::receivePackets() {
    sf::IpAddress senderAddress;
    unsigned short senderPort;
    sf::Packet packet;
    sf::Int8 opcode;
    while (socket.receive(packet, senderAddress, senderPort) != sf::Socket::NotReady) {
        packet >> opcode;
        
        // 1 - it's a connection request
        // 2 - it's a move
        
        if (opcode == 1) {
            // create connection
            createConnection(senderAddress);
        } else if (opcode == 2) {
            // put move in moves queue
            ClientMove move;
            packet >> move;
            moves.push(move);
        }
    }
}

void NetworkServer::createConnection(sf::IpAddress address) {
    
    // 1. find the first empty spot in players array
    // and put a new PlayerServer there
    
    sf::Int8 clientID = 0;
    /* while (m_players[clientID] != NULL) {
        clientID++;
    }
     ill fix this but I needed to take this out to test
    */
    PlayerServer player;
    m_players[clientID] = &player;
    
    // put their ip in the ip array
    
    m_addresses[clientID] = address;
    
    // 2. send a packet back to client to create a new game
    // send the opcode and the map to the client
    
    // opcodes
    // 1 - create game
    // 2 - game update
    
    sf::Packet packet;
    sf::Int8 opcode = 1;
    packet << opcode << clientID;
    socket.send(packet, address, 26000);
}

void NetworkServer::broadcastUpdate() {
    sf::Packet packet;
    sf::Int8 opcode = 2;
    packet << opcode;
    for (int i = 0; i < 12; i++) {
        if (m_players[i] != NULL) {
            packet << m_players[i]->getX() << m_players[i]->getY();
        }
    }

    for (int i = 0; i < 12; i++) {
        if (m_addresses[i] != sf::IpAddress::None) {
            socket.send(packet, m_addresses[i], 26000);
        }
    }
}