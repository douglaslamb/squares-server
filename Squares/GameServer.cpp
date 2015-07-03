//
//  GameServer.cpp
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "GameServer.h"

GameServer::GameServer(MapServer &map) {
    m_map = &map;
    run();
}

void GameServer::run() {
    while (true) {
        sf::Time elapsed = clock.restart();
        update();
    }
}

void GameServer::update() {
    // what to do in update
    // I need to get keypresses and move all squares
    // and update positions of squares
    
}


