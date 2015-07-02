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

class PlayerServer {
private:
    double m_x;
    double m_y;
    
    sf::Color *color;
    
public:
    float getX();
    void setX(float x);
    double getY();
    void setY(float y);
    sf::Color getColor();
    void setColor(sf::Color c);
    void move(double x, double y);
    // void shoot(); leave it out for now
}

#endif /* defined(__Squares__PlayerServer__) */
