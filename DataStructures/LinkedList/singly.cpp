/*
   a list refers to the sequence of data items
   
   a linked list is a chain of nodes
      each node contains
         some piece of data that is to be stored in the sequence
         a link to next node in  the list

      
   the first node in the linked list is called head, the last node is called tail.
   each node points to the next node and last node will point to null.


   common linked list operation:
      traversal
      rewriting
      insertion
      deletion
 
*/
#include<iostream>
#include<string>
using namespace std;


struct Node {
   string data;
   Node* next;
};


int main() {
   // create a node and allocate it memory using `new`
   Node* list = new Node;
   list->data  = "node 1";
   list->next = nullptr;

   delete list;

   return 0;

}