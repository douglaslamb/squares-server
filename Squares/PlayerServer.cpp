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

double PlayerServer::getX()  {
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

double PlayerServer::getSpeed() const {
    return m_speed;
}

void PlayerServer::setSpeed(double speed) {
    m_speed = speed;
}

sf::Color PlayerServer::getColor() const {
    return m_color;
}

void PlayerServer::setColor(sf::Color color) {
    m_color = color;
}

void PlayerServer::move(sf::Int32 x, sf::Int32 y) {
    std::cout << "playerserver x and y " << m_x << " " << m_y << "\n";
    m_x = m_x + (x * m_speed);
    m_y = m_y + (y * m_speed);
}

/*
sf::Packet& operator <<(sf::Packet& packet, const PlayerServer& player) {
    return packet << player.getX() << player.getY() << player.getSpeed() << player.getColor().r << player.getColor().g << player.getColor().b;
}

sf::Packet& operator >>(sf::Packet& packet, PlayerServer& player) {
    double x;
    double y;
    double speed;
    sf::Uint8 r;
    sf::Uint8 g;
    sf::Uint8 b;
    
    packet >> x >> y >> speed >> r >> g >> b;
    player.setX(x);
    player.setY(y);
    player.setSpeed(speed);
    player.setColor(sf::Color(r, g, b));
}
*/