//
//  GameServer.cpp
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "GameServer.h"

GameServer::GameServer() {
    m_map = MapServer();
}

GameServer::GameServer(MapServer map) {
    m_map = map;
}

void GameServer::run() {
    while (true) {
        sf::Time elapsed = m_clock.restart();
        update(elapsed);
    }
}

void GameServer::update(sf::Time elapsed) {
    // 1. execute pending commands
    // 2. accept pending connection requests and create the player object
    // 3. send updates to clients (probably do that last)
}


