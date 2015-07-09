//
//  GameServer.h
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __Squares__GameServer__
#define __Squares__GameServer__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MapServer.h"
#include "PlayerServer.h"
#include "GameClient.h"

class GameServer {
    
private:
    PlayerServer m_players[12];
    MapServer m_map;
    sf::Clock m_clock;
    
    void update(sf::Time elapsed);
    // updates game logic and pushes updates to clients
    
public:
    GameServer();
    GameServer(MapServer map);
    
    void run();
    // contains the game loop
    
};

#endif /* defined(__Squares__GameServer__) */
