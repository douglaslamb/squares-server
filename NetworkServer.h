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
    std::vector<PlayerServer*> *m_players;
    std::vector<sf::IpAddress> m_addresses;
    MapServer m_map;
    sf::UdpSocket socket;
    bool needToBroadcast;
    
    void receivePackets();
    void createConnection(sf::IpAddress address);
    void broadcastUpdate();
    
public:
    NetworkServer();
    NetworkServer(std::vector<PlayerServer*> &players, MapServer map);
    void update();
    std::queue<ClientMove>& getMoves();

};

#endif /* defined(__Squares__NetworkServer__) */
