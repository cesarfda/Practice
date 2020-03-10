//
//  toughBird.cpp
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#include "toughBird.h"
#include "uiDraw.h"

toughBird :: toughBird(Point point)
{
    this -> point = point;
    living = true;
    radius = 15;
    score = 0;
    velocity.setX(1);
    hits = 3;
    if (point.getY() < 0)
    {
        velocity.setY(1);
    }
    else
    {
        velocity.setY(-1);
    }
}

int toughBird :: hit()
{
    hits--;
    if (hits == 0)
    {
        kill();
        drawLanderFlames(point, true, true, true);
        return 3;
    }
    return 1;
}
void toughBird :: draw()
{
    drawToughBird(point, radius, hits);
}
