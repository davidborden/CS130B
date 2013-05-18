//
//  sortingVertices.cpp
//  CS130B
//
//  Created by David Borden on 5/10/13.
//
//

#include <iostream>
using namespace std;
#include <string>
#include "Vertex.h"

void quicksortVertices(Vertex* [], int, int);
int partitionVertices(Vertex* [], int, int, int);
int median3Vertices(Vertex* [],int,int);
void swapVertices(int &, int &);

// QUICKSORT FOR VERTICES //
void quicksortVertices(Vertex* vertices[], int left, int right)
{
    
    if (right > left)
    {
        int pivotIndex = median3Vertices(vertices,left,right);
        int pivotNewIndex = partitionVertices(vertices, left, right, pivotIndex);
        
        // Recursive call to quicksort to sort each half.
        quicksortVertices(vertices, left, pivotNewIndex-1);
        quicksortVertices(vertices, pivotNewIndex+1, right);
    }
}
// MEDIAN of 3 //
int median3Vertices(Vertex* vertices[],int left,int right)
{
    int center = (left+right)/2;
    
    // WHAT does it mean to be <, >, or = to?
    if(vertices[center]->y_1 > vertices[left]->y_1)
        swap(vertices[left],vertices[center]);
    if (vertices[center]->y_1 == vertices[left]->y_1 && vertices[center]->x_1 < vertices[left]->x_1)
        swap(vertices[left],vertices[center]);
    if(vertices[right]->y_1 > vertices[left]->y_1)
        swap(vertices[left],vertices[right]);
    if(vertices[right]->y_1 == vertices[left]->y_1 && vertices[right]->x_1 < vertices[left]->x_1)
        swap(vertices[left],vertices[right]);
    if(vertices[right]->y_1 > vertices[center]->y_1)
        swap(vertices[center],vertices[right]);
    if(vertices[right]->y_1 == vertices[center]->y_1 && vertices[right]->x_1 < vertices[center]->x_1)
        swap(vertices[center],vertices[right]);
    
    swap(vertices[center],vertices[right-1]); // why -1 eh?

    return center;
}

// This function takes an array (or one half an array) and sorts it.
// It then returns a new pivot index number back to quicksort.

int partitionVertices(Vertex* vertices[], int left, int right, int pivot)
{
    /** cout << "partition (" << arIntegers[0] << ","
     << arIntegers[1] << ","
     << arIntegers[2] << ","
     << arIntegers[3] << ","
     << arIntegers[4] << ","
     << arIntegers[5] << ","
     << arIntegers[6] << "],"
     << left << ","
     << right << ")\n";**/
    
    Vertex* pivotValue = vertices[pivot];
    
    // Swap it out all the way to the end of the array
    // So we know where it always is.
    swap(vertices[pivot], vertices[right]);
    int storeIndex = left;
    
    // Move through the array from start to finish comparing each to our
    // pivot value (not index, the value that was located at the pivot index)
    for (int i = left; i < right; i++)
    {
        if ( vertices[i]->y_1 > pivotValue->y_1 )
        {
            swap(vertices[i], vertices[storeIndex]);
            storeIndex++;
        }
        else if ( vertices[i]->y_1 == pivotValue->y_1 && vertices[i]->x_1 < pivotValue->x_1) {
            swap(vertices[i], vertices[storeIndex]);
            storeIndex++;
        }
    }
    swap(vertices[storeIndex], vertices[right]);
    return storeIndex;
}
// WHAT does it mean to swap in our case??
// Simple swap function for our in place swapping.
void swapVertices(Vertex* &val1, Vertex* &val2)
{
    Vertex* temp = val1;
    val1 = val2;
    val2 = temp;
}
