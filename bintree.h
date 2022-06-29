#ifndef BINTREE_H
#define BINTREE_H

#include "binnode.h" //Node for tree
#include "record.h" //Data type for Jeopardy Game
#include <iostream> //Input and Output for console
#include <fstream> //file stream
#include <string> //standard string


template <typename Type> //Type as template data
class BinTree {
public:

    BinTree() : root(nullptr) {} // Default Constructor
    BinTree(const BinTree<Type>& source); //copy constructor
    ~BinTree(); //Destructor

    BinTree<Type>& operator=(const BinTree<Type>& copy); // assignment operator

    
    void inOrderTraversal(int count1, void process(Type, int&, int&)); //Used for HTML files

    void writeFile(std::string filename); //Writing tree to file
    bool readFile(std::string fileName); //Reads File


    bool isEmpty(); // checks to see if tree is emtpy
    void add(Type data); // adds new data


    void inOrder() { //sorts tree in least to greatest order
        inOrder(root);
    }
    void freeUser() { //function calling on private to clear tree completley
        freeTree(root);
    }
    void print() { //Prints all nodes
        int count = 1;
        print(root, count);
    }
    void countNodes() { //Counts all Nodes
        int count = 1;
        countNodes(root, count);
    }

private:
    BinNode<Type>* root; //first node of tree
    BinNode<Type>* alloc(Type data); //function creating new node using data

    BinNode<Type>* copyTree(BinNode<Type>* node);
    //void inOrderRecursive(BinNode<Type>* cursor, int& count1, int& count2, void process(Type, int&, int&));
    void writeFile(BinNode<Type>* cursor, std::ofstream& outFile);
    void inOrder(BinNode<Type>* cursor);
    void freeTree(BinNode<Type>* cursor);
    void print(BinNode<Type>* node, int& count);
    void countNodes(BinNode<Type>* node, int& count);

    void inOrderRecursive(BinNode<Type>* cursor, int& count1, int& count2, void process(Type, int&, int&)); //Used for HTML files

};


#include "bintree.template"
#endif

