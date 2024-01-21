/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void insert(Node *&head, int value);
void splitHelper(Node *in, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
  
  // Clear lists
  odds = nullptr;
  evens = nullptr;

  splitHelper(in, odds, evens);

  // Delete original list
  while(in){
    Node* clean = in;
    in = in -> next;
    delete clean;
  }

}

/* If you needed a helper function, write it here */
void splitHelper(Node *in, Node*& odds, Node*& evens){
  
  // If no input
  if (!in){
    return;
  }

  // Insert whether odd or even
  if (in->value % 2 == 0){
    insert(evens, in->value);
  }
  else{
    insert(odds, in->value);
  }

  // Call splitHelper for the next item in list
  splitHelper(in->next, odds, evens);

}

void insert(Node *&head, int value){
  Node* newNode = new Node(value, nullptr);

    // If list doesn't exist make newNode the head
    if(!head){
      head = newNode;
      return;
    }

    // If there is no next node then add the next node
    if(!head->next){
      head->next = newNode;
      return;
    }

    // Call until end of list
    insert(head->next, value);

}