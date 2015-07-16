//
//  PlayerServer.h
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __Squares__PlayerServer__
#define __Squares__PlayerServer__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class PlayerServer {
private:
    double m_x;
    double m_y;
    double m_speed;
    
    sf::Color m_color;
    
public:
    PlayerServer();
    
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);
    double getSpeed() const;
    void setSpeed(double speed);
    sf::Color getColor() const;
    void setColor(sf::Color color);
    void move(sf::Int32 x, sf::Int32 y);
};

sf::Packet& operator <<(sf::Packet& packet, const PlayerServer& player);
sf::Packet& operator >>(sf::Packet& packet, PlayerServer& player);


#endif /* defined(__Squares__PlayerServer__) */
