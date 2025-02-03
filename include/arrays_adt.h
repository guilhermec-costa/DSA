#pragma once

class ArrayADT
{
private:
  int *A;
  int length;
  int _size;

public:
  ArrayADT(int size);
  ~ArrayADT();
  int size();
  void display();
  void append(int e);
  void insert(int e, int idx);
  int at(int idx);
  int remove(int idx);
};