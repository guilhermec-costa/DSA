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
      std::cout << "popping: " << popped->data << "\n";
      return popped;
    }

    void display()
    {
      for (int i = 0; i < this->stackTop; i++)
      {
        std::cout << (this->stackData[i])->data << "\n";
      }
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
  auto *rootNode = new BinaryTreeNode<char *>("A");
  auto *BNode = new BinaryTreeNode<char *>("B");
  auto *CNode = new BinaryTreeNode<char *>("C");
  auto *DNode = new BinaryTreeNode<char *>("D");
  auto *ENode = new BinaryTreeNode<char *>("E");
  auto *FNode = new BinaryTreeNode<char *>("F");
  rootNode->data = "Root Data";
  BNode->data = "B data";
  CNode->data = "C data";
  DNode->data = "D data";
  ENode->data = "E data";
  FNode->data = "F data";

  rootNode->left = BNode;
  rootNode->right = CNode;
  BNode->left = DNode;
  BNode->right = ENode;
  CNode->right = FNode;

  binaryTreeStack.push(rootNode);
  binaryTreeStack.push(BNode);
  binaryTreeStack.push(CNode);
  binaryTreeStack.push(DNode);
  binaryTreeStack.push(ENode);
  binaryTreeStack.push(FNode);

  while (!binaryTreeStack.is_empty())
  {
    auto curNode = binaryTreeStack.pop();
    printf("Current Node Data: %s\n", curNode->data);
    delete curNode;
  }
}