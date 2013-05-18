//
//  main.cpp
//  CS130B
//
//  Created by David Borden on 5/4/13.
//
#include <sstream>
#include <iostream>
#include "Rectangle.h"
#include "Vertex.h"
#include "LinkedList.h"
#include "Node.h"
#include "AdjacencyList.h"
using namespace std;

int main(int argc, const char * argv[])
{
    void quicksort(Rectangle* [], int, int);
    int partition(Rectangle* [], int, int, int);
    int median3(Rectangle* [],int,int);
    void swap(int &, int &);
    
    void quicksortVertices(Vertex* [], int, int);
    int partitionVertices(Vertex* [], int, int, int);
    int median3Vertices(Vertex* [],int,int);
    void swapVertices(int &, int &);

/**sort and renumber all corener points
 an edge can not contain another vertice
the weight of an edge is the Euclidian distance
the value of k tells us the number of vertices on the boundary of the rectangle
    // starting from the lop left
 if(output_format == 1)
        text
else
    do the SAMBA
     I will actually be outputting SAMBA commands to draw the graph
     - the graph is an adjacency list
        - vertex object contains pointer to adjacency list (which represents it's adjacent vertices and their coord's)
     - each node in adjacency list contains: (but not limited to)
            1) an adjacent vertex
            2) the length of the edge to that neighbor
            3) and a pointer to the next node in the list.
    - memory must be allocated dynamically     
     for each vertex I must:
     - print out it's index, it's coord's, it's neighbors, and it's neighbors weights
    **/
    /**
     to do:
     - put vertices in adjacency list with neighbors and distance between them along with each vertex's coords
     UPDATE:
     - Adjacency List is a go, WOOOT!
     - now I need to work on the distances part
     - I should create function that computes Euclidian distance between two points and returns int. (int one, int two)
     - I have to output neighbors in decreasing order hmm...
        - since we know there is a max of 4, just print last one first then second to last?
     **/
    
    string m, rectanglex, rectangley;
    string val1, val2, val3, val4;
    int i1, i2, i3, i4;
    int numLine = 0;
    int vertexCounter = 0;
    int oneFound = -1, twoFound = -1, threeFound = -1, fourFound = -1;
    
    cin >> m;
    cin >> rectanglex;
    cin >> rectangley;
    
    int numRectangles;
    istringstream ( m ) >> numRectangles;
    
    Rectangle* myarray[numRectangles];
    Vertex* newVertexArray[numRectangles*4];
    
    cin >> val1;
    istringstream (val1) >> i1;
    cin >> val2;
    istringstream (val2) >> i2;
    cin >> val3;
    istringstream (val3) >> i3;
    cin >> val4;
    istringstream (val4) >> i4;
    
        if ( numLine == 0 ) {
            
            myarray[numLine] = new Rectangle(i1, i2, i3, i4);
            
            Vertex *oneVertex = new Vertex(i1, i2);
            myarray[numLine]->corners[0] = oneVertex;
            newVertexArray[0] = oneVertex;
                
            Vertex *twoVertex = new Vertex(i3, i2);
            myarray[numLine]->corners[1] = twoVertex;
                newVertexArray[1] = twoVertex;
            
            Vertex *threeVertex = new Vertex(i3, i4);
            myarray[numLine]->corners[2] = threeVertex;
                newVertexArray[2] = threeVertex;
            
            Vertex *fourVertex = new Vertex(i1, i4);
            myarray[numLine]->corners[3] = fourVertex;
                newVertexArray[3] = fourVertex;
                
            vertexCounter += 4;
            numLine++;
        }

    while (numLine < numRectangles) {
       
        //Reading stuff in for the second time
        cin >> val1;
        istringstream (val1) >> i1;
        cin >> val2;
        istringstream (val2) >> i2;
        cin >> val3;
        istringstream (val3) >> i3;
        cin >> val4;
        istringstream (val4) >> i4;
        
        myarray[numLine] = new Rectangle(i1, i2, i3, i4);

        // LOOP ONE //
         for (int i = 0; i < numLine; i++) {
            if (myarray[i]->corners[0]->x_1 == i1 &&  myarray[i]->corners[0]->y_1 == i2){ //MATCH: Vertex already exists, don't create it
                myarray[numLine]->corners[0] = myarray[i]->corners[0];
                oneFound++; 
            }
             if (myarray[i]->corners[1]->x_1 == i1 &&  myarray[i]->corners[1]->y_1 == i2){ //MATCH: Vertex already exists, don't create it
                 myarray[numLine]->corners[0] = myarray[i]->corners[1];
                 oneFound++;
             }
             if (myarray[i]->corners[2]->x_1 == i1 &&  myarray[i]->corners[2]->y_1 == i2){ //MATCH: Vertex already exists, don't create it
                 myarray[numLine]->corners[0] = myarray[i]->corners[2];
                 oneFound++; 
             }
             if (myarray[i]->corners[3]->x_1 == i1 &&  myarray[i]->corners[3]->y_1 == i2){ //MATCH: Vertex already exists, don't create it
                 myarray[numLine]->corners[0] = myarray[i]->corners[3];
                 oneFound++; 
             }
         }
        if (oneFound == -1) {
                Vertex *oneVertex = new Vertex(i1, i2);
                myarray[numLine]->corners[0] = oneVertex;
                newVertexArray[vertexCounter] = oneVertex;
                vertexCounter++;
             }
        // LOOP TWO //
        for (int i = 0; i < numLine; i++) {
            if (myarray[i]->corners[0]->x_1 == i3 &&  myarray[i]->corners[0]->y_1 == i2){ //Vertex already exists, don't create it
                myarray[numLine]->corners[1] = myarray[i]->corners[0];
                twoFound++;
            }
            if (myarray[i]->corners[1]->x_1 == i3 &&  myarray[i]->corners[1]->y_1 == i2){ //Vertex already exists, don't create it
                myarray[numLine]->corners[1] = myarray[i]->corners[1];
                twoFound++;                
            }
            if (myarray[i]->corners[2]->x_1 == i3 &&  myarray[i]->corners[2]->y_1 == i2){ //Vertex already exists, don't create it
                myarray[numLine]->corners[1] = myarray[i]->corners[2];
                twoFound++;                
            }
            if (myarray[i]->corners[3]->x_1 == i3 &&  myarray[i]->corners[3]->y_1 == i2){ //Vertex already exists, don't create it
                myarray[numLine]->corners[1] = myarray[i]->corners[3];
                twoFound++;                
            }
        }
        if (twoFound == -1) {
                Vertex *twoVertex = new Vertex(i3, i2);
                myarray[numLine]->corners[1] = twoVertex;
                newVertexArray[vertexCounter] = twoVertex;
                vertexCounter++;
            }
        // LOOP THREE //
        for (int i = 0; i < numLine; i++) {
            if (myarray[i]->corners[0]->x_1 == i3 &&  myarray[i]->corners[0]->y_1 == i4){ //Vertex already exists, don't create it
                myarray[numLine]->corners[2] = myarray[i]->corners[0];
                threeFound++;
            }
            if (myarray[i]->corners[1]->x_1 == i3 &&  myarray[i]->corners[1]->y_1 == i4){ //Vertex already exists, don't create it
                myarray[numLine]->corners[2] = myarray[i]->corners[1];
                threeFound++;                
            }
            if (myarray[i]->corners[2]->x_1 == i3 &&  myarray[i]->corners[2]->y_1 == i4){ //Vertex already exists, don't create it
                myarray[numLine]->corners[2] = myarray[i]->corners[2];
                threeFound++;                
            }
            if (myarray[i]->corners[3]->x_1 == i3 &&  myarray[i]->corners[3]->y_1 == i4){ //Vertex already exists, don't create it
                myarray[numLine]->corners[2] = myarray[i]->corners[3];
                threeFound++;        
            }
        }
        if (threeFound == -1)    {
                Vertex *threeVertex = new Vertex(i3, i4);
                myarray[numLine]->corners[2] = threeVertex;
                newVertexArray[vertexCounter] = threeVertex;
                vertexCounter++;
            }
        // LOOP FOUR //
        for (int i = 0; i < numLine; i++) {
            if (myarray[i]->corners[0]->x_1 == i1 &&  myarray[i]->corners[0]->y_1 == i4){ 
                myarray[numLine]->corners[3] = myarray[i]->corners[0];
                fourFound++;
            }
            if (myarray[i]->corners[1]->x_1 == i1 &&  myarray[i]->corners[1]->y_1 == i4){ 
                myarray[numLine]->corners[3] = myarray[i]->corners[1];
                fourFound++;                
            }
            if (myarray[i]->corners[2]->x_1 == i1 &&  myarray[i]->corners[2]->y_1 == i4){ 
                myarray[numLine]->corners[3] = myarray[i]->corners[2];
                fourFound++;                
            }
            if (myarray[i]->corners[3]->x_1 == i1 &&  myarray[i]->corners[3]->y_1 == i4){
                myarray[numLine]->corners[3] = myarray[i]->corners[3];
                fourFound++;                
            }
        }
            if ( fourFound == -1) {
                Vertex *fourVertex = new Vertex(i1, i4);
                myarray[numLine]->corners[3] = fourVertex;
                newVertexArray[vertexCounter] = fourVertex;
                vertexCounter++;
            }
        
        // RESET VALUES
        oneFound = -1, twoFound = -1, threeFound = -1, fourFound = -1;
        numLine++;
    }
    
    AdjacencyList *neighbs = new AdjacencyList(vertexCounter);
    //Node* ptr1, ptr2,ptr3,ptr4;

    quicksortVertices(newVertexArray, 0, vertexCounter-1);
    
    // VERTEX INDEX //
    for (int i = 0; i < vertexCounter; i++)
        newVertexArray[i]->index = i+1;
    
    //cout << "printing stuffs OUT " << endl;
    // now that Vertices are sorted, let's put em in the adjacency list (the array part)
    for (int i = 1; i <= vertexCounter; i++) { // NOTE: i = 1, THUS we want to have <= vertexCounter
        neighbs->AList[i] = new LinkedList();
        neighbs->AList[i]->insert(newVertexArray[i-1]);
    }        
    
    quicksort(myarray, 0, numRectangles-1);
    
    // INDEX RECTANGLES//
    for (int i = 0; i < numRectangles; i++)
        myarray[i]->index = i+1;
    

        // CREATING LINKED LIST FOR EACH RECTANGLE
    
    // for each direction, it is not checking the borders because we only check between each corner.
    // if it matches 1st line coords do extra check
    
    for (int i = 0; i < numRectangles; i++) // go through each rectangle and add vertices to it's LL by looking at it's corners
    {
        for (int j = myarray[i]->corners[0]->index-1; j < myarray[i]->corners[1]->index; j++) {
            myarray[i]->Vertices->insert(newVertexArray[j]); // includes corner [0] & [1]
            //myarray[i]->Vertices->print();
            if (myarray[i]->corners[1]->index != j+1) { // attempt at making sure we aren't adding right neighbors to top right corner
                //cout << " add " << (newVertexArray[j+1]->index) << " as neighbor of " << j+1 << endl;
                neighbs->AList[j+1]->insert(newVertexArray[j+1]);
                cout << " just inserted: " << newVertexArray[j+1]->index << " as neighbor of " << j+1 << endl;
             //   neighbs->AList[j+1]->print();//print function does not work on this
                //cout << " THIS " << endl;
               // neighbs->AList[j+1]->printAlist();
                //cout << j+1 << " & " << neighbs->AList[j+1]->tail->someVertex->index << endl; // root doesn't have anything, tail is latest
            }
        }
        
        int AListInsert = myarray[i]->corners[1]->index;

        // vertices between corners [1] & [2]
        for ( int k = myarray[i]->corners[1]->index; k < myarray[i]->corners[2]->index; k++) {
            //need to check if they lie on the same y-axis
            if (myarray[i]->corners[2]->x_1 == newVertexArray[k]->x_1) {// if this Rectangle's x matches any of these Vertices x, insert
                myarray[i]->Vertices->insert(newVertexArray[k]); // includes corner [2]
                // as long as we aren't on the bottom right corner, add it's neighbor
                if (myarray[i]->corners[2]->index != k) {// attempt at making sure we aren't adding bottom neighbor
                    neighbs->AList[AListInsert]->insert(newVertexArray[k]);
                    //cout << AListInsert << " ^ " << newVertexArray[k]->index << " or " << neighbs->AList[AListInsert]->tail->someVertex->index <<  endl;
                    AListInsert = k+1;
                }
            }
        }
        // this loop below adds (going backward) from corner3 to corner4 everything in betrween since they share a y-axis
        // to-do: we can just follow it's lead and as long as we check that we aren't at corner4 to add it's left neighbor.
        for ( int n = (myarray[i]->corners[2]->index)-2; n >= myarray[i]->corners[3]->index-1; n--) {
            myarray[i]->Vertices->insert(newVertexArray[n]); // includes corner [3]
            if ((myarray[i]->corners[3]->index)-2 != n) {
                neighbs->AList[n+2]->insert(newVertexArray[n]);
                //cout << n+2 << " * " << newVertexArray[n]->index << " or " << neighbs->AList[AListInsert]->tail->someVertex->index << endl;
            }
            if ( newVertexArray[n]->y_1 == 0) {// if it is in the bottom row
                //cout << " n's: " << n << " x == 0" << endl;
                neighbs->AList[n+2]->insert(newVertexArray[n]);
            }
        }
        int anInsert = myarray[i]->corners[3]->index;
        for ( int p = myarray[i]->corners[3]->index-2; p >= (myarray[i]->corners[0]->index)-1; p--) { // while corner3 (array-1) > corner0
            if (myarray[i]->corners[3]->x_1 == newVertexArray[p]->x_1) {// if corner3's x is the same as vertex's x
               if (p != (myarray[i]->corners[0]->index-1)) // hack to not add corner[0] to LL of vertices
                   myarray[i]->Vertices->insert(newVertexArray[p]);
                if ((myarray[i]->corners[0]->index)-1 != p-1) { //off by a few, not checking corner[0]
                    neighbs->AList[anInsert]->insert(newVertexArray[p]);
                    //cout << anInsert << " and " << newVertexArray[p]->index << " or " << neighbs->AList[AListInsert]->tail->someVertex->index << endl;
                    anInsert = p+1;
                }
            }
        }
        
    }
    
//    for (int i = 0; i < vertexCounter; i++) {
//        if (newVertexArray[i]->y_1 == 0) { //add the next one over to it's neighbor LL
//            neighbs->AList[i+1]->insert(newVertexArray[i+1]);
//        }
//    }
//    cout << "printing neighbs: " << endl;


    // PRINTING EACH RECTANGLES VERTICES //
 //   cout << "PRINTING VERTICES" << endl;
    for (int i = 0; i < numRectangles; i++) {
         myarray[i]->Vertices->print();
    }
    
    // PRINT CORNERS//
  //  cout << "PRINTING CORNERS" << endl;
    for (int i = 0; i < numRectangles; i++)
    {
        myarray[i]->printCorners();
    }
    
     for (int i = 1; i <+ vertexCounter; i++) {
        cout << i << " ";
        neighbs->AList[i]->printAlist();
    }   
    /**
     10 5000 5000
     2000 3000 2500 2000
     4000 2750 5000 2000
     0 5000 2500 3000
     2500 5000 4000 2000
     4000 5000 5000 2750
     2000 2000 3750 0
     3750 2000 5000 1250
     3750 1250 5000 0
     0 500 2000 0
     0 3000 2000 500
     **/
            
    return 0;
};

