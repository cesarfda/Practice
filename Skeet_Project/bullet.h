//
//  bullet.h
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#ifndef bullet_h
#define bullet_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "flyer.h"

class Bullet : public Flyer
{
private:
    
public:
    Bullet();
    void advance();
    void draw();
    void fire(Point point, float angle);
};

#endif /* bullet_h */
