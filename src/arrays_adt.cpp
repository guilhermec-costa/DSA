#include <iostream>
#include "arrays_adt.h"

template <class T>
ArrayADT<T>::ArrayADT(int s) : _size(s)
{
  this->A = new T[s];
  this->length = 0;
};

template <class T>
ArrayADT<T>::~ArrayADT()
{
  delete A;
};

template <class T>
int ArrayADT<T>::size() { return this->_size; }

void arrays_adt()
{
  int size = 0;
  std::cout << "Size of array: " << std::endl;
  std::cin >> size;
  ArrayADT<int> arr(size);

  std::cout << arr.size() << std::endl;
  arr.display();
}

template <class T>
void ArrayADT<T>::display()
{
  for (int i = 0; i < this->length; i++)
  {
    printf("%s", this->A[i]);
  }
}