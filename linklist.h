/*
  Andrew Crandall
  CSC 161
  Jeopardy #2
  04/14/2022
  Title:LinkList definition file
*/


#ifndef LINKLIST_H
#define LINKLIST_H

#include "node.h" //Node(object) of each list

#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <ctime>


template <typename T> // template prefix of T
class LinkList {
public:
    // default constructor - empty
    LinkList() { first = last = nullptr; }

    //modifiers
    void append(T dataItem);  //Add to end of list
    void prepend(T dataItem);  //Add to front of list
    bool removeByItem(T dataItem);  //Remove specific data

    T at(int count);

    //getters
    bool isEmpty() const { return first == nullptr; } //determines if list is empty
    void printBackwards(); //Prints entire list backwards
    int getSize(); //Size of list
    bool find(T itemToFind); //find specific item in list
    void free(); //Clears list
    T getRandomItem(); //Returns random data point of list

    bool readFile(std::string fileName); //allows to read from file
    bool writeFile(std::string fileName); //writes list to file


    void printQuestions(); //Output specifically for Jeopardy
    


    //copy constructor
    LinkList(const LinkList<T>& souce);
    //assignment operator
    LinkList<T>& operator=(const LinkList<T>& source);
    //destructor
    ~LinkList();

private:
    Node<T>* alloc(T dataItem); //allows for new data

    Node<T>* first; //first node of list (head)
    Node<T>* last; //last node of list (tail)

    void printBackwards(Node<T>* cursor); // print backwards 

};


#include "linklist.template" // definition file
#endif