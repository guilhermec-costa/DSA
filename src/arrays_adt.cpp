#include <iostream>
#include "arrays_adt.h"

ArrayADT::ArrayADT(int s) : _size(s)
{
  this->A = new int[s]{};
  this->length = 0;
};

ArrayADT::~ArrayADT()
{
  delete[] this->A;
};

int ArrayADT::size() { return this->_size; }

void ArrayADT::append(int n)
{
  if (this->length < this->size())
    this->A[this->length++] = n;
}

void ArrayADT::display()
{
  for (int i = 0; i < this->length; i++)
    std::cout << this->A[i] << ", ";
}

// shift to right
void ArrayADT::insert(int e, int idx)
{
  if (idx >= 0 && idx <= this->length)
  {
    for (int i = this->length; i > idx; i--)
      this->A[i] = this->A[i - 1];

    this->A[idx] = e;
    this->length++;
  }
}

int ArrayADT::at(int idx)
{
  if (idx > this->size())
    return 0;

  return this->A[idx];
}

// shift to left
// best case: O(1) - no shift
// worst case: O(n)
int ArrayADT::remove(int idx)
{
  if (idx >= 0 && idx < this->length)
  {
    int element = this->A[idx];
    for (int i = idx; i < this->length - 1; i++)
      this->A[i] = this->A[i + 1];
    this->length--;
    return element;
  }
}

void arrays_adt()
{
  int size = 0;
  std::cout << "Size of array: ";
  std::cin >> size;
  ArrayADT arr(size);

  arr.insert(8, 2);

  std::cout << arr.at(2) << std::endl;
}