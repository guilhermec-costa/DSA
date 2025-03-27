#include "binary_tree.h"
#include <iostream>

namespace BinaryTrees
{

  template <typename T>
  class Stack
  {
  public:
    int stackTop;
    T *stackData;
    int size;
    Stack<T>(int stackSize)
    {
      this->stackData = new T[stackSize];
      this->stackTop = -1;
      this->size = stackSize;
    };

    bool is_empty()
    {
      return this->stackTop == -1;
    }

    bool is_full()
    {
      return this->stackTop == this->size - 1;
    }

    void push(T element)
    {
      if (this->is_full())
        return;

      this->stackData[++stackTop] = element;
    }

    T pop()
    {
      if (this->is_empty())
        return nullptr;

      T popped = this->stackData[this->stackTop--];
      return popped;
    }

    ~Stack()
    {
      delete[] this->stackData;
    }
  };
};

void binary_trees()
{
  BinaryTrees::Stack<BinaryTreeNode<char *> *> binaryTreeStack = BinaryTrees::Stack<BinaryTreeNode<char *> *>(10);
  BinaryTreeNode<char *> *rootNode = new BinaryTreeNode<char *>("A");
  BinaryTreeNode<char *> *BNode = new BinaryTreeNode<char *>("B");
  BinaryTreeNode<char *> *CNode = new BinaryTreeNode<char *>("C");
  BinaryTreeNode<char *> *DNode = new BinaryTreeNode<char *>("D");
  BinaryTreeNode<char *> *ENode = new BinaryTreeNode<char *>("E");
  BinaryTreeNode<char *> *FNode = new BinaryTreeNode<char *>("F");

  rootNode->left = BNode;
  rootNode->right = CNode;
  BNode->left = DNode;
  BNode->right = ENode;
  CNode->right = FNode;

  binaryTreeStack.push(rootNode);
  BinaryTreeNode<char *> *poppedNode = binaryTreeStack.pop();
  printf("%c\n", poppedNode->data);

  delete rootNode;
  delete BNode;
  delete CNode;
  delete DNode;
  delete ENode;
  delete FNode;
}