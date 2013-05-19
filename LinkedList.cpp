//
//  LinkedList.cpp
//  CS130B
//
//  Created by David Borden on 5/4/13.
//
//

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

LinkedList::LinkedList() {
    root = NULL;
    tail = NULL;
}

void LinkedList::insert(Vertex* aVertex){
    //Node* ptr1, ptr2,ptr3,ptr4;
    Node *l = new Node(aVertex);
    //Node *traverseptr = root;
    if (root == NULL || tail == NULL) {
        root = l;
        tail = l;
    }
    else {
        //cout << " l is pointing to vertex with index of: " << l->someVertex->index << endl;
       // cout << " tail is pointing to vertex with index of: " << tail->someVertex->index << endl;
        tail->next = l;
        tail = l; // Maybe have a counter.
    }
}

//bool LinkedList::find(Vertex aVertex) {
//    
//    Node * tp = root;
//    while (tp != NULL) {
//        if (aVertex.x_1 == tp->someVertex.x_1 && aVertex.y_1 == tp->someVertex.y_1){
//            return true;
//        }
//        tp = tp -> next;
//    }
//    return false;
//}


void LinkedList::remove(string value) {
    
    Node * ptr = root;
    Node * tmp = root;
    
    if (ptr->value == value){ // first one is one we want to delete
        if (ptr -> next != NULL) {// if some after 1st one
            root = ptr -> next;
        }
        else {
            root = NULL; // only one in entire list
        }
        
    }
    else { // it is not the first one we want to delete (more than 1)
        while (ptr->next != NULL) {
            tmp = tmp-> next;
            if (tmp->value == value) {
                if ( tmp -> next != NULL) { // see if there is one after deletion item
                    ptr -> next = tmp -> next;
                }
                else { // delete item is last one
                    ptr -> next = NULL;
                }
            }
            ptr = ptr -> next;
        }
    }
}

/*void LinkedList::traverse() {
    Node *ptrt = root;
    
    if (root == NULL) //this link is entire list
        cout << "empty list" << endl;
    else {
        while (ptrt != NULL){
            ptrt = ptrt -> next;
        }
        return;
    }
}*/

void LinkedList::print(){
    
    Node *ptr = root;
    
    if (root == NULL) //this link is entire list
        cout << "meow" << endl;
    else {
        while (ptr != NULL){
            cout << ptr->someVertex->index << " ";
            ptr = ptr -> next;
        }
        cout << endl;
    }
}

void LinkedList::printAlist() {
    
    Node *ptr = root;
    int count = 0;
    
            if (count == 0) {
                cout << ptr->someVertex->x_1 << " " << ptr->someVertex->y_1 << " ";
                count++;
            }
    
    if (root == NULL) //this link is entire list
        cout << "meow" << endl;
    else {
        ptr = ptr->next;
        while (ptr != NULL){
            cout << ptr->someVertex->index << " " << ptr->dist << " ";
            ptr = ptr -> next;
        }
        cout << endl;
    }
    
}
