#include <iostream>
#include "arrays_adt.h"

ArrayADT::ArrayADT(int size)
{
  this->A = new int[size]{0};
  this->length = 0;
  this->_size = size;
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
  if (idx >= 0 && idx <= this->size())
  {
    for (int i = this->length; i > idx; i--)
      this->A[i] = this->A[i - 1];

    this->A[idx] = e;
    this->length++;
  }
}

int ArrayADT::get(int idx)
{
  if (idx >= 0 && idx <= this->length)
  {
    return this->A[idx];
  }
}

void ArrayADT::set(int idx, int ele)
{
  if (idx >= 0 && idx <= this->length)
  {
    this->A[idx] = ele;
  }
}

int ArrayADT::max()
{
  int maximum = this->A[0];
  for (int i = 0; i < this->length; i++)
  {
    if (this->A[i] > maximum)
    {
      maximum = this->A[i];
    }
  }

  return maximum;
}

int ArrayADT::min()
{
  int minimum = this->A[0];
  for (int i = 0; i < this->length; i++)
  {
    if (this->A[i] < minimum)
    {
      minimum = this->A[i];
    }
  }

  return minimum;
}

int sumArrADT(ArrayADT &arr, int idx)
{
  if (idx == 0)
  {
    return arr.get(0);
  }

  return sumArrADT(arr, idx - 1) + arr.get(idx);
}

void ArrayADT::reverse_fstmethod()
{
  int l = this->length;
  int a[l];

  for (int i = 0; i < this->length; i++)
  {
    a[i] = this->A[length - 1 - i];
  }

  for (int i = 0; i < this->length; i++)
  {
    this->A[i] = a[i];
  }
}

void ArrayADT::reverse_sndmethod()
{
  int *ptr_begin = this->A;
  int *ptr_end = &(this->A[this->length - 1]);

  while (ptr_begin < ptr_end)
  {
    int tmp = *ptr_begin;
    *ptr_begin = *ptr_end;
    *ptr_end = tmp;

    ptr_begin++;
    ptr_end--;
  }
}

int ArrayADT::sum()
{
  // int sum = 0;                           // 1
  // for (int i = 0; i < this->length; i++) // 1 + n + (n + 1)
  // {
  //   sum += this->A[i]; // n
  // }

  // return sum; // 1
  // total: 1 + 1 + n + n + 1 + n + 1 = 4 + 3n -> O(n)

  return sumArrADT(*this, this->length - 1);
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

  return -1;
}

void arrays_adt()
{
  ArrayADT arr(10);

  arr.append(5);
  arr.append(2);
  arr.append(10);
  arr.display();
  std::cout << std::endl;

  arr.insert(15, 2);
  arr.display();
  arr.remove(1);
  std::cout << std::endl;
  arr.display();
  std::cout << "\nsum of array: " << arr.sum() << std::endl;
  arr.reverse_fstmethod();
  std::cout << "reversed array: ";
  arr.display();

  arr.reverse_sndmethod();
  std::cout << "reversed array ( pointer method ): ";
  arr.display();
}
