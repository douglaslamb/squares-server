//
//  GameServer.cpp
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "GameServer.h"

GameServer::GameServer() : m_network(m_players, m_map){
    m_map = MapServer();
}

GameServer::GameServer(MapServer map) : m_network(m_players, m_map){
    m_map = map;
}

void GameServer::run() {
    while (true) {
        sf::Time elapsed = m_clock.restart();
        update(elapsed);
    }
}

void GameServer::update(sf::Time elapsed) {
    // 1. make the network update
    m_network.update();
    
    // 2. execute pending moves
    std::queue<ClientMove> moves = m_network.getMoves();
    if (!moves.empty()) {
        moves.front().execute(m_players);
        moves.pop();
    }
}


