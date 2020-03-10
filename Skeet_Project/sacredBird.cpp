//
//  sacredBird.cpp
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#include "sacredBird.h"
#include "uiDraw.h"

sacredBird :: sacredBird(Point point)
{
    this -> point = point;
    living = true;
    radius = 7.5;
    score = 0;
    velocity.setX(1);
    
    if(point.getY() < 0)
    {
        velocity.setY(1);
    }
    else
    {
        velocity.setY(-1);
    }
}
int sacredBird :: hit()
{
    kill();
    score += -10;
    return score;
}
void sacredBird :: draw()
{
    drawSacredBird(point, radius);
}

