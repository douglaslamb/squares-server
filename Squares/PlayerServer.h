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
    sf::Color getColor();
    void setColor(sf::Color color);
    void move(int x, int y);
};

#endif /* defined(__Squares__PlayerServer__) */
