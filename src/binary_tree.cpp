#include "binary_tree.h"
#include <iostream>
#include <vector>

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
        throw std::out_of_range("Stack is empty");

      T popped = this->stackData[this->stackTop--];
      return popped;
    }

    void display()
    {
      std::cout << this->stackTop << std::endl;
      for (int i = 0; i <= this->stackTop; i++)
      {
        std::cout << (this->stackData[i])->data << "\n";
      }
    }

    ~Stack()
    {
      // delete[] this->stackData;
    }
  };
};

template <typename nodeDatatype>
void depthFirstValues(
    BinaryTreeNode<nodeDatatype> *rootNode,
    BinaryTrees::Stack<BinaryTreeNode<nodeDatatype> *> stack,
    std::vector<BinaryTreeNode<nodeDatatype> *> &resultVector)
{
  stack.push(rootNode);
  while (!stack.is_empty())
  {
    auto curNode = stack.pop();
    resultVector.push_back(curNode);
    if (curNode->right)
      stack.push(curNode->right);
    if (curNode->left)
      stack.push(curNode->left);
  }
};

void binary_trees()
{
  BinaryTrees::Stack<BinaryTreeNode<char *> *> binaryTreeStack = BinaryTrees::Stack<BinaryTreeNode<char *> *>(10);
  auto *DNode = new BinaryTreeNode<char *>("D Data", NULL, NULL);
  auto *FNode = new BinaryTreeNode<char *>("F Data", NULL, NULL);
  auto *CNode = new BinaryTreeNode<char *>("C Data", NULL, FNode);
  auto *ENode = new BinaryTreeNode<char *>("E Data", NULL, NULL);
  auto *BNode = new BinaryTreeNode<char *>("B Data", DNode, ENode);
  auto *rootNode = new BinaryTreeNode<char *>("Root Data", BNode, CNode);
  auto resultNodes = std::vector<BinaryTreeNode<char *> *>();

  depthFirstValues<char *>(rootNode, binaryTreeStack, resultNodes);
  for (auto v : resultNodes)
    std::cout << v->data << "\n";

  delete rootNode;
  delete BNode;
  delete CNode;
  delete DNode;
  delete ENode;
  delete FNode;
}