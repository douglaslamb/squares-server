//
//  ClientMove.cpp
//  Squares
//
//  Created by rocker on 20150703.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "ClientMove.h"

ClientMove::ClientMove() {
    m_x = 0;
    m_y = 0;
    m_clientID = 0;
}

ClientMove::ClientMove(sf::Int32 x, sf::Int32 y, sf::Int32 clientID) {
    m_x = x;
    m_y = y;
    m_clientID = clientID;
}

sf::Int32 ClientMove::getX() {return m_x;}
sf::Int32 ClientMove::getY() {return m_y;}
sf::Int32 ClientMove::getClientID() {return m_clientID;}

void ClientMove::execute(PlayerServer players[]) {
    players[m_clientID].move(m_x, m_y);
}





