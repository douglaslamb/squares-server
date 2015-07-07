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
#include "ClientMove.h"

class NetworkServer {
    
private:
    std::queue<ClientMove*> moves;
    sf::UdpSocket socket;
    
    // in receive packet I receive a packet and if it is a move
    // I put it in the moved queue and if it is not
    // I create a connection with that client.
    // the createConnection method will expect the client
    // to supply a unique clientID between 0 and 12.
    
    void receivePacket();
    void createConnection(sf::Packet connection);
    void broadcastUpdate();
    
public:
    NetworkServer();
    void update();
    std::queue<ClientMove*> getMoves();

};

#endif /* defined(__Squares__NetworkServer__) */
