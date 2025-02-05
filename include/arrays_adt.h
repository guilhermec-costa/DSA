#pragma once

class ArrayADT
{
private:
  int *A;
  int _size;

public:
  ArrayADT(int size);
  ~ArrayADT();
  int size();
  void display();
  void append(int e);
  void insert(int e, int idx);
  int get(int idx);
  void set(int idx, int e);
  int remove(int idx);
  int max();
  int min();
  int sum();
  void reverse_fstmethod();
  void reverse_sndmethod();
  int length;
};

int sumArrADT(ArrayADT &arr, int n);