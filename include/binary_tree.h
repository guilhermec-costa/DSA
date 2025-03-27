#ifndef BINARY_TREE
#define BINARY_TREE
#include <iostream>

template <typename T>
class BinaryTreeNode
{

public:
  T data;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode(T _d) : data(_d), left(NULL), right(NULL) {};
  BinaryTreeNode(T _d, BinaryTreeNode *left, BinaryTreeNode *right) : data(_d), left(left), right(right) {};
};

#endif