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

double MapServer::getLength() const {
    return m_length;
}

void MapServer::setLength(double length) {
    m_length = length;
}

double MapServer::getWidth() const {
    return m_width;;
}

void MapServer::setWidth(double width) {
    m_width = width;
}

sf::Color MapServer::getColor() const {
    return m_color;
}

void MapServer::setColor(sf::Color color) {
    m_color = color;
}


