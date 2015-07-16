//
//  ClientMove.cpp
//  Squares
//
//  Created by rocker on 20150703.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "ClientMove.h"

ClientMove::ClientMove() {
    m_clientID = 0;
    m_x = 0;
    m_y = 0;
}

ClientMove::ClientMove(sf::Int32 clientID, sf::Int32 x, sf::Int32 y) {
    m_clientID = clientID;
    m_x = x;
    m_y = y;
}

sf::Int32 ClientMove::getClientID() const {return m_clientID;}
sf::Int32 ClientMove::getX() const {return m_x;}
sf::Int32 ClientMove::getY() const {return m_y;}

void ClientMove::setClientID(sf::Int32 clientID) {
    m_clientID = clientID;
}
    
void ClientMove::setX(sf::Int32 x) {
    m_x = x;
}

void ClientMove::setY(sf::Int32 y) {
    m_y = y;
}

void ClientMove::execute(std::vector<PlayerServer*> players) {
    std::cout << "ClientMove x and y " << m_x << " " << m_y << "\n";
    std::cout << "ClientMove clientID " << m_clientID << "\n";
    players.at(m_clientID)->move(m_x, m_y);
}

sf::Packet& operator <<(sf::Packet& packet, const ClientMove& move) {
    return packet << move.getClientID() << move.getX() << move.getY();
}

sf::Packet& operator >>(sf::Packet& packet, ClientMove& move) {
    sf::Int32 clientID;
    sf::Int32 x;
    sf::Int32 y;
    packet >> clientID >> x >> y;
    move.setClientID(clientID);
    move.setX(x);
    move.setY(y);
}