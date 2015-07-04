//
//  MapServer.cpp
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "MapServer.h"

MapServer::MapServer() {
    m_length = 0;
    m_width = 0;
    m_color = sf::Color(255, 255, 255);
}
MapServer::MapServer(double length, double width) {
    m_length = length;
    m_width = width;
    m_color = sf::Color(255, 255, 255);
}

sf::Color MapServer::getColor() {
    return m_color;
}
