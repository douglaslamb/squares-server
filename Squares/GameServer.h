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
#include "PlayerServer.h"

class GameServer {
private:
    PlayerServer *m_players[12];
    GameClient *m_clients[12];
    MapServer m_map;
    sf::Clock m_clock;
    
    void run();
    // contains the game loop
    void update();
    // updates game logic and pushes updates to clients
    
public:
    GameServer(MapServer map);
    
}

#endif /* defined(__Squares__GameServer__) */
