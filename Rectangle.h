//
//  Rectangle.h
//  CS130B
//
//  Created by David Borden on 5/6/13.
//
//

#ifndef __CS130B__Rectangle__
#define __CS130B__Rectangle__

#include <iostream>
#include "Vertex.h"
#include "LinkedList.h"
using namespace std;

class Rectangle {

public:
    Rectangle(int tl_x, int tl_y, int br_x, int br_y);
    Vertex** corners;
    int tl_x;
    int tl_y;
    int br_x;
    int br_y;
    int index;
    void printRectangle();
    void printCorners();
    void printCornerCoords();
    LinkedList* Vertices; // does this need to be a pointer?
    void printVertices();

};
#endif /* defined(__CS130B__Rectangle__) */
