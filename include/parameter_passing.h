#pragma once
#include <iostream>

void swap_params(int x, int z)
{
  int temp;
  temp = x;
  x = z;
  z = x;
}

void swap_params_ref(int &x, int &z)
{
  int temp;
  temp = x;
  x = z;
  z = temp;
}

void parameter_passing()
{
  int a = 5;
  int b = 10;

  std::cout << "\"a\" before fake swap: " << a << ".\n";
  std::cout << "\"b\" before fake swap: " << a << ".\n";

  swap_params(a, b);

  std::cout << "\"a\" after fake swap: " << a << ".\n";
  std::cout << "\"b\" after fake swap: " << a << ".\n";

  std::cout << "--------" << std::endl;
  std::cout << "\"a\" before real swap: " << a << ".\n";
  std::cout << "\"b\" before real swap: " << b << ".\n";

  swap_params_ref(a, b);
  std::cout << "\"a\" after real swap: " << a << ".\n";
  std::cout << "\"b\" after real swap: " << b << ".\n";
  std::cout << "--------" << std::endl;
}

// a pointer is received. Not the array itself
template <typename T, size_t N>
void arr_as_param(T (&arr)[N])
{
  T *ptrA = arr;

  for (T ele : arr)
  {
    std::cout << ele << std::endl;
  }
  std::cout << "---------" << std::endl;

  for (int i = 0; i < N; i++)
  {
    std::cout << ptrA[i] << std::endl;
  }
}

// a pointer is received. Not the array itself
template <typename T>
void arr_as_param_ptr(T *arr, int N)
{
  for (int i = 0; i < N; i++)
  {
    std::cout << arr[i] << std::endl;
  }
  std::cout << "---------" << std::endl;
}