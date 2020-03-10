//
//  StandardBird.cpp
//  
//
//  Created by Uthaichai on 6/13/18.
//

#include "standardBird.h"
#include "uiDraw.h"
standardBird :: standardBird(Point point)
{
    this -> point = point;
    living = true;
    radius = 7.5;
    score = 0;
    velocity.setX(1);
    if (point.getY() < 0)
    {
        velocity.setY(1);
    }
    else
    {
        velocity.setY(-1);
    }
}
int standardBird :: hit()
{
    kill();
    score +=1;
    return score;
}
void standardBird :: draw()
{
    drawCircle(point, radius);
}
