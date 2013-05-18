//
//  Vertex.cpp
//  CS130B
//
//  Created by David Borden on 5/4/13.
//
//

#include "Vertex.h"
using namespace std;

Vertex::Vertex() {
    x_1 = -1;
    y_1 = -1;
}

Vertex::Vertex(int x, int y) {
    this->x_1 = x;
    this->y_1 = y;
}

void Vertex::printVertex() {
    cout << this->index << " x: " << this->x_1 << "y: " << this->y_1 << endl;
}

void Vertex::printIndex() {
    cout << this->index << endl;
}