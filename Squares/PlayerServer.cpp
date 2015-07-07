//
//  PlayerServer.cpp
//  Squares
//
//  Created by rocker on 20150702.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "PlayerServer.h"

PlayerServer::PlayerServer() {
    m_x = 0;
    m_y = 0;
    m_speed = 1;
    m_color = sf::Color(100, 250, 50);
}

double PlayerServer::getX() {
    return m_x;
}

void PlayerServer::setX(double x) {
    m_x = x;
}

double PlayerServer::getY() {
    return m_y;
}

void PlayerServer::setY(double y) {
    m_y = y;
}

sf::Color PlayerServer::getColor() {
    return m_color;
}

void PlayerServer::setColor(sf::Color color) {
    m_color = color;
}

void PlayerServer::move(int x, int y) {
    m_x = m_x + (x * m_speed);
    m_y = m_y + (y * m_speed);
}


