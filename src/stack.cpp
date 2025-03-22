#include <iostream>
#include "stack_adt.h"

Stack::Stack(int size)
{
  this->size = size;
  this->stack = new int[size]{0};
  this->top = -1;
}

Stack::~Stack()
{
  delete this->stack;
}

// if defined directly inside the class, it will be inline automatically
inline bool Stack::is_empty()
{
  return this->top == -1;
}

inline bool Stack::is_full()
{
  return this->top == size - 1;
}

void Stack::push(int x)
{
  if (is_full())
  {
    std::cout << "would overflow stack adding \"" << x << "\" to it" << std::endl;
    return;
    int new_size = this->size + 5;
    int *new_stack = new int[new_size]{0};
    for (int i = 0; i < size; i++)
      new_stack[i] = this->stack[i];
    delete[] this->stack;
    this->stack = new_stack;
    this->size = new_size;
  }
  this->stack[++top] = x;
}

int Stack::pop()
{
  if (is_empty())
  {
    std::cout << "would underflow stack.\n";
    return NULL;
  }
  return this->stack[top--];
}

// inverse of an array. The access to the stack items are from top to bottom
// so it is needed to access it in the position (TOP - PEEK_INDEX)
int Stack::peek(int pos)
{
  if (top - pos + 1 < 0)
  {
    std::cout << "\"" << pos << "\" is out of range of the stack\n";
    return -1;
  }

  return this->stack[top - pos + 1];
}

void Stack::view()
{
  for (int i = 0; i <= top; i++)
  {
    std::cout << this->stack[i] << " ";
  }
}

int Stack::stacktop()
{
  if (is_empty())
    return -1;
  return this->stack[this->top];
}

void stacks()
{
  int size;
  std::cout << "stack size -> ";
  std::cin >> size;
  Stack st = Stack(size);
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(10);
  st.view();
  std::cout << "\n-------------------" << std::endl;
  std::cout << "Popping item" << "\n";
  int popped = st.pop();
  st.view();
  std::cout << "\n-------------------" << std::endl;
  std::cout << "Peeking item" << "\n";
  std::cout << "Pos 0 of stack: " << st.peek(0) << std::endl;
  std::cout << "Pos 1 of stack: " << st.peek(1) << std::endl;
  std::cout << "Pos 2 of stack: " << st.peek(2) << std::endl;
}