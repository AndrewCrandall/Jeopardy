/*
  Andrew Crandall
  CSC 161
  Jeopardy #2
  04/14/2022
  Title:Node definition file
*/


#ifndef NODE_H
#define NODE_H

#include "linklist.h"

template <class Type>
class Node {
    template <class T>
    friend class LinkList;
public:
    // Constructors
    // Constructors
    Node() : data(Type()), next(nullptr) {}
    Node(Type dataIn) : data(dataIn), next(nullptr) {}

private: // data members
    Type data; // information within node
    Node<Type>* next; // next node of list
};

#endif