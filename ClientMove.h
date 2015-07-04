//
//  ClientMove.h
//  Squares
//
//  Created by rocker on 20150703.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __Squares__ClientMove__
#define __Squares__ClientMove__

#include <iostream>
#include <SFML/Network.hpp>

class ClientMove {
    
private:
    int m_x;
    int m_y;
    int m_clientID;
    
public:
    ClientMove();
    ClientMove(int x, int y, int clientID);

    void execute();
};

#endif /* defined(__Squares__ClientMove__) */
