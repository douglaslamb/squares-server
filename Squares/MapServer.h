//
//  MapServer.h
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __Squares__MapServer__
#define __Squares__MapServer__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class MapServer {
private:
    double m_length;
    double m_width;
    sf::Color m_color;
    
public:
    
    MapServer();
    MapServer(double length, double width);
    
    double getLength() const;
    void setLength(double length);
    double getWidth() const;
    void setWidth(double width);
    sf::Color getColor() const;
    void setColor(sf::Color color);
};

sf::Packet& operator <<(sf::Packet& packet, const MapServer& player);

#endif /* defined(__Squares__MapServer__) */
