//
//  sacredBird.hpp
//  Skeet_Project
//
//  Created by Uthaichai on 6/13/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#ifndef sacredBird_h
#define sacredBird_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "flyer.h"
#include "bird.h"

class sacredBird : public Bird
{
private:
public:
    sacredBird(Point point);
    void draw();
    int hit();
    string getType()
    {
        return "Sacred Bird";
    }
};
#endif /* sacredBird_hpp */
