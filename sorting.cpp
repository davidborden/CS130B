//
//  sorting.cpp
//  CS130B
//
//  Created by David Borden on 5/7/13.
//
//

#include <iostream>
using namespace std;
#include <string>
#include "Rectangle.h"

void quicksort(Rectangle* [], int, int);
int partition(Rectangle* [], int, int, int);
int median3(Rectangle* [],int,int);
void swap(int &, int &);

// QUICKSORT FOR RECTANGLES //
void quicksort(Rectangle* rects[], int left, int right)
{
    
    if (right > left)
    {
        int pivotIndex = median3(rects,left,right);
        int pivotNewIndex = partition(rects, left, right, pivotIndex);
        
        // Recursive call to quicksort to sort each half.
        quicksort(rects, left, pivotNewIndex-1);
        quicksort(rects, pivotNewIndex+1, right);
    }
}
// MEDIAN of 3 //
int median3(Rectangle* rects[],int left,int right)
{
    int center = (left+right)/2;
    
    // WHAT does it mean to be <, >, or = to?
    if(rects[center]->tl_y > rects[left]->tl_y)
        swap(rects[left],rects[center]);
    if (rects[center]->tl_y == rects[left]->tl_y && rects[center]->tl_x < rects[left]->tl_x)
        swap(rects[left],rects[center]);
    if(rects[right]->tl_y > rects[left]->tl_y)
        swap(rects[left],rects[right]);
    if(rects[right]->tl_y == rects[left]->tl_y && rects[right]->tl_x < rects[left]->tl_x)
        swap(rects[left],rects[right]);
    if(rects[right]->tl_y > rects[center]->tl_y)
        swap(rects[center],rects[right]);
    if(rects[right]->tl_y == rects[center]->tl_y && rects[right]->tl_x < rects[center]->tl_x)
        swap(rects[center],rects[right]);
    
    swap(rects[center],rects[right-1]);
    
    return center;
}

// This function takes an array (or one half an array) and sorts it.
// It then returns a new pivot index number back to quicksort.

int partition(Rectangle* rects[], int left, int right, int pivot)
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
    
    Rectangle* pivotValue = rects[pivot];
    
    // Swap it out all the way to the end of the array
    // So we know where it always is.
    swap(rects[pivot], rects[right]);
    int storeIndex = left;
    
    // Move through the array from start to finish comparing each to our
    // pivot value (not index, the value that was located at the pivot index)
    for (int i = left; i < right; i++)
    {
        if ( (rects[i]->tl_y > pivotValue->tl_y))
        {
            swap(rects[i], rects[storeIndex]);
            storeIndex++;
        }
        else if ( rects[i]->tl_y == pivotValue->tl_y && rects[i]->tl_x < pivotValue->tl_x) {
            swap(rects[i], rects[storeIndex]);
            storeIndex++;
        }
    }
    swap(rects[storeIndex], rects[right]);
    return storeIndex;
}
// WHAT does it mean to swap in our case??
// Simple swap function for our in place swapping.
void swap(Rectangle* &val1, Rectangle* &val2)
{
    Rectangle* temp = val1;
    val1 = val2;
    val2 = temp;
}