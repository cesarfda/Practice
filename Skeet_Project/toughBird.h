//
//  toughBird.hpp
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#ifndef toughBird_h
#define toughBird_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "flyer.h"
#include "bird.h"

class toughBird: public Bird
{
private:
    int hits;
public:
    string getType()
    {
        return "Tough Bird";
    }
    toughBird(Point point);
    void draw();
    int hit();
};
#endif /* toughBird_hpp */
