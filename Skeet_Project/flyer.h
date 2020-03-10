//
//  flyer.h
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#ifndef flyer_h
#define flyer_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class Flyer
{
protected:
    Point point;
    Velocity velocity;
    bool living;

public:
    Point getPoint(){return point;}
    Velocity getVelocity(){return velocity;}
    bool isAlive(){return living;}
    
    void setPoint(Point point);
    void setVelocity(Velocity velocity);
    void kill(){living = false;}
    
    void advance();
    virtual void draw() = 0;
};
#endif /* flyer_h */
