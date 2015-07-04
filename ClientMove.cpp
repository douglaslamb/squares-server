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

ClientMove::ClientMove(int x, int y, int clientID) {
    m_x = x;
    m_y = y;
    m_clientID = clientID;
}

void ClientMove::execute() {
    // probably put the array of player objects in as an argument to execute, probably?
    // because I will be calling move on one of those objects
}

