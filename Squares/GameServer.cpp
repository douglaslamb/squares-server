//
//  GameServer.cpp
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "GameServer.h"

GameServer::GameServer() : m_players(12), m_map(), m_network(m_players, m_map) {
    // m_players.reserve(12);
}

GameServer::GameServer(MapServer map) : m_players(12), m_network(m_players, map) {
    // m_players.reserve(12);
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
    while (!m_network.getMoves().empty()) {
        std::cout << "I execute a move\n";
        m_network.getMoves().front().execute(m_players);
        m_network.getMoves().pop();
    }
}


