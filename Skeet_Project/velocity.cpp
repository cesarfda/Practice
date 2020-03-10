//
//  velocity.cpp
//  Moonlander
//
//  Created by Uthaichai on 5/30/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#include "velocity.h"
Velocity :: Velocity(): x(0.0) , y(0.0){}
Velocity :: Velocity(float x, float y) : x(0.0), y(0.0)
{
    setX(x);
    setY(y);
}

float Velocity :: getX() const{return x;}
float Velocity :: getY() const{return y;}

void Velocity :: setX(float x){this -> x = x;}
void Velocity :: setY(float y){this-> y = y;}

void Velocity :: addX(float x){this -> x  += x;}
void Velocity :: addY(float y){this -> y += y;}
