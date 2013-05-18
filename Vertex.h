//
//  Vertex.h
//  CS130B
//
//  Created by David Borden on 5/4/13.
//
//

#ifndef __CS130B__Vertex__
#define __CS130B__Vertex__

#include <iostream>

class Vertex {
    //these are private automatically
    
public:
    int x_1;
    int y_1;
    int index;
    Vertex();
    Vertex (int x, int y);
    void printVertex();
    void printIndex();
};

#endif /* defined(__CS130B__Vertex__) */
