//
//  Bird.h
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#ifndef bird_h
#define bird_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "flyer.h"
#include "uiDraw.h"
#include <string>

class Bird : public Flyer
{
protected:
    int radius;
    int score;
    
public:
    virtual int hit() = 0;
    virtual string getType() = 0;
};
#endif /* Bird_h */
