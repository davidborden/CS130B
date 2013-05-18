//
//  LinkedList.h
//  CS130B
//
//  Created by David Borden on 5/4/13.
//
//

#ifndef __CS130B__LinkedList__
#define __CS130B__LinkedList__

using namespace std;
#include <iostream>
#include "Node.h"

class LinkedList{
    
public:
    LinkedList();
    void insert (Vertex* aVertex);
    void remove (string value);
    bool find (Vertex aVertex);
    void print ();
    void printAlist();
    Vertex traverse();
    Node *root;
    Node *tail;
};

#endif /* defined(__CS130B__LinkedList__) */
