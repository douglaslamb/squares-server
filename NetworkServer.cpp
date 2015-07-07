//
//  NetworkServer.cpp
//  Squares
//
//  Created by rocker on 20150704.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "NetworkServer.h"

NetworkServer::NetworkServer() {
    socket.bind(26000);
}

void NetworkServer::update() {
    
}

std::queue<ClientMove*> NetworkServer::getMoves() {
    return moves;
}

void NetworkServer::receivePacket() {
    sf::IpAddress senderAddress;
    unsigned short senderPort;
    sf::Packet packet;
    socket.receive(packet, senderAddress, senderPort);
    
    // next I'm working on this function!! 20150704 
    // in receive packet I receive a packet and if it is a move
    // I put it in the moved queue and if it is not
    // I create a connection with that client.
    // the createConnection method will expect the client
    // to supply a unique clientID between 0 and 12.
    
    // ok I am still working on this function. 20150706
    // what I need to do next is to write packet sniffing code
    // if the first int in the packet...
    // 1 - it's a connection request
    // 2 - it's a move
    // I need to write code to make a clientmove and put it in the
    // queue if it's a move and I need to write code
    // to create a new playerServer and assign that playerServer
    // to a spot in the players array and then send a message back
    // telling the client to create a game and copy my gameServer on their
    // own machine but as a gameclient! wow! and I need to give the client
    // their assigned clientID back
}

sf::Packet& operator <<(sf::Packet& packet, const ClientMove& move) {
    return packet << move.m_clientID << move.
}
