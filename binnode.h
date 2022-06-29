#ifndef BINNODE_H
#define BINNODE_H

template <typename T>
class BinNode{

  template <typename Type>
  friend class BinTree; 
// BinTree has access to left and right pointers as well as data

public:
  //default constructor
  BinNode() : data(T()), left(nullptr), right(nullptr) {}

  BinNode(T dataInit) : data(dataInit), left(nullptr), right(nullptr) {}


private:

  T data;
  BinNode<T>* left;
  BinNode<T>* right;

};

#endif