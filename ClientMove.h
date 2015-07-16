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
    sf::Int32 m_clientID;
    sf::Int32 m_x;
    sf::Int32 m_y;
    
public:
    ClientMove();
    ClientMove(sf::Int32 clientID, sf::Int32 x, sf::Int32 y);
    
    sf::Int32 getClientID() const;
    sf::Int32 getX() const;
    sf::Int32 getY() const;
    
    void setClientID(sf::Int32 clientID);
    
    void setX(sf::Int32 x);
    
    void setY(sf::Int32 y);
    
    void execute(std::vector<PlayerServer*> players);
};

sf::Packet& operator <<(sf::Packet& packet, const ClientMove& move);
sf::Packet& operator >>(sf::Packet& packet, ClientMove& move);

#endif /* defined(__Squares__ClientMove__) */
