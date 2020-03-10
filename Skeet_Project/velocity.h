//
//  velocity.hpp
//  Moonlander
//
//  Created by Uthaichai on 5/30/18.
//  Copyright © 2018 Sam. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

#include <stdio.h>

class Velocity
{
private:
    float x;
    float y;
public:
    Velocity();
    Velocity(float x, float y);
    
    float getX() const;
    float getY() const;
    
    void setX(float x);
    void setY(float y);
    
    void addX(float x);
    void addY(float y);
    

};
#endif /* velocity_hpp */
