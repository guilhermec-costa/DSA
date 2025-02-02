#pragma once

template <class T>
class ArrayADT
{
private:
  T *A;
  int length;
  int _size;

public:
  ArrayADT(int size);
  ~ArrayADT();
  int size();
  void display();
};