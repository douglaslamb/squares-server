//
//  NetworkServer.h
//  Squares
//
//  Created by rocker on 20150704.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __Squares__NetworkServer__
#define __Squares__NetworkServer__

#include <iostream>
#include <queue>
#include <SFML/Network.hpp>
#include "PlayerServer.h"
#include "MapServer.h"
#include "ClientMove.h"

class NetworkServer {
    
private:
    std::queue<ClientMove> moves;
    PlayerServer *m_players[12];
    sf::IpAddress m_addresses[12];
    MapServer *m_map;
    sf::UdpSocket socket;
    
    // in receive packet I receive a packet and if it is a move
    // I put it in the moved queue and if it is not
    // I create a connection with that client.
    // the createConnection method will expect the client
    // to supply a unique clientID between 0 and 12.
    
    void receivePackets();
    void createConnection(sf::IpAddress address);
    void broadcastUpdate();
    
public:
    NetworkServer(PlayerServer players[12], MapServer map);
    void update();
    std::queue<ClientMove> getMoves();

};

#endif /* defined(__Squares__NetworkServer__) */
