//
//  Node.h
//  CS130B
//
//  Created by David Borden on 5/4/13.
//
//

#ifndef __CS130B__Node__
#define __CS130B__Node__

#include <iostream>
#include <string>
#include "Vertex.h"
using namespace std;

class Node
{
public:
    //Node();
    Node(Vertex* aVertex);
    string value;
    Node *next;
    int dist;
    Vertex* someVertex;

private:
    string something;
};


#endif /* defined(__CS130B__Node__) */
