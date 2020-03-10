//
//  flyer.cpp
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#include "flyer.h"

void Flyer :: setPoint( Point point)
{
    this -> point = point;
}
void Flyer :: setVelocity(Velocity velocity)
{
    this -> velocity = velocity;
}
void Flyer :: advance()
{
    point.addX(velocity.getX());
    point.addY(velocity.getY());
}
