//
//  AdjacencyList.h
//  CS130B
//
//  Created by David Borden on 5/12/13.
//
//

#ifndef __CS130B__AdjacencyList__
#define __CS130B__AdjacencyList__

#include <iostream>
#include "LinkedList.h"

class AdjacencyList {
    
public:
    LinkedList** AList;
    AdjacencyList(int size);
};

#endif /* defined(__CS130B__AdjacencyList__) */
