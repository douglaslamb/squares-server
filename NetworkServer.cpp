//
//  NetworkServer.cpp
//  Squares
//
//  Created by rocker on 20150704.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "NetworkServer.h"

NetworkServer::NetworkServer() {
    std::cout << "default constructor";
};

NetworkServer::NetworkServer(std::vector<PlayerServer*> &players, MapServer map) : m_addresses(12) {
    std::cout << "parameterized constructor";
    m_players = &players;
    m_map = map;
    socket.bind(26000);
    socket.setBlocking(false);
    needToBroadcast = false;
}

void NetworkServer::update() {
    receivePackets();
    if (needToBroadcast) {
        broadcastUpdate();
        needToBroadcast = false;
    }
}

std::queue<ClientMove>& NetworkServer::getMoves() {
    return moves;
}

void NetworkServer::receivePackets() {
    sf::IpAddress senderAddress;
    unsigned short senderPort;
    sf::Packet packet;
    sf::Int32 opcode;
    while (socket.receive(packet, senderAddress, senderPort) != sf::Socket::NotReady) {
        packet >> opcode;
        
        // 1 - it's a connection request
        // 2 - it's a move
        
        if (opcode == 1) {
            std::cout << "received connection request\n";
            // create connection
            createConnection(senderAddress);
        } else if (opcode == 2) {
            // put move in moves queue
            ClientMove move;
            packet >> move;
            std::cout << "clientID " << move.getClientID() << "\n";
            std::cout << "x " << move.getX() << "\n";
            std::cout << "y " << move.getY() << "\n";
            moves.push(move);
            needToBroadcast = true;
        }
        packet.clear();
    }
}

void NetworkServer::createConnection(sf::IpAddress address) {
    
    // 1. find the first empty spot in players array
    // and put a new PlayerServer there
    
    sf::Int32 clientID = 0;
    
    while (m_players->at(clientID) != NULL) {
        clientID++;
    }
    
    m_players->at(clientID) = new PlayerServer();
    
    // put their ip in the ip array
    
    m_addresses.at(clientID) = address;
    
    // 2. send a packet back to client to create a new game
    // send the opcode and the map to the client
    
    // opcodes
    // 1 - create game
    // 2 - game update
    
    sf::Packet packet;
    sf::Int32 opcode = 1;
    packet << opcode << clientID;
    socket.send(packet, address, 25000);
    packet.clear();
    std::cout << "sent clientID back\n";
    broadcastUpdate();
}

void NetworkServer::broadcastUpdate() {
    sf::Int32 opcode = 2;
    sf::Packet packet;
    packet << opcode;
    
    for (int i = 0; i < 12; i++) {
        if (m_players->at(i) != NULL) {
            packet << m_players->at(i)->getX();
            packet << m_players->at(i)->getY();
            std::cout << "broadcast x and y " << m_players->at(i)->getX() << " " << m_players->at(i)->getY() << "\n";
        }
    }

    for (int i = 0; i < 12; i++) {
        if (m_addresses.at(i) != sf::IpAddress::None) {
            std::cout << "update to client " << i << "\n";
            socket.send(packet, m_addresses.at(i), 25000);
        }
    }
}