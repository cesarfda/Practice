//
//  bullet.cpp
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#include "bullet.h"
#include "flyer.h"
#include "uiDraw.h"
#include <cmath>

#define BULLET_SPEED 10.0

Bullet :: Bullet()
{
    this -> point = point;
    living = true;
}
void Bullet :: advance()
{
    point.addX(velocity.getX());
    point.addY(velocity.getY());
}
void Bullet :: draw()
{
    drawDot(point);
}
void Bullet :: fire(Point point, float angle)
{
    this -> point = point;
    point = point;
    float x = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
    float y = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
    velocity.setX(x);
    velocity.setY(y);
}
