//
//  Rectangle.cpp
//  CS130B
//
//  Created by David Borden on 5/6/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(int t_x, int t_y, int b_x, int b_y) {
        
    tl_x = t_x;
    tl_y = t_y;
    br_x = b_x;
    br_y = b_y;
    corners = new Vertex*[4];
    Vertices = new LinkedList();

}

void Rectangle::printRectangle() {
    cout << "R " << this->index << " " << this->tl_x << " " << this->tl_y << " " << this->br_x << " " << this->br_y << endl;
}

void Rectangle::printCorners() {
    for (int j = 0; j < 4; j++) {
        cout << this->corners[j]->index << " ";
        if (j == 3)
            cout << endl;
    }
}

void Rectangle::printCornerCoords() {
    for (int i = 0; i < 4; i++) {
        cout << "x1 " << this->corners[i]->x_1 << " y1 " << this->corners[i]->y_1;
    }
    cout << endl;
}
