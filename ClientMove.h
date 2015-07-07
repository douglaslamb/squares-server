//
//  ClientMove.h
//  Squares
//
//  Created by rocker on 20150703.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __Squares__ClientMove__
#define __Squares__ClientMove__

#include <iostream>
#include <SFML/Network.hpp>
#include "PlayerServer.h"

class ClientMove {
    
private:
    sf::Int32 m_x;
    sf::Int32 m_y;
    sf::Int32 m_clientID;
    
public:
    ClientMove();
    ClientMove(sf::Int32 x, sf::Int32 y, sf::Int32 clientID);
    
    sf::Int32 getX();
    sf::Int32 getY();
    sf::Int32 getClientID();

    void execute(PlayerServer players[]);
};

#endif /* defined(__Squares__ClientMove__) */
