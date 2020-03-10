//
//  StandardBird.h
//  
//
//  Created by Uthaichai on 6/13/18.
//

#ifndef StandardBird_h
#define StandardBird_h
#include "point.h"
#include "velocity.h"
#include "flyer.h"
#include "bird.h"
#include <stdio.h>

class standardBird : public Bird
{
private:
    
public:
    standardBird(Point point);
    void draw();
    int hit();
    string getType()
    {
        return "Standard Bird";
    }
};
#endif /* StandardBird_h */
