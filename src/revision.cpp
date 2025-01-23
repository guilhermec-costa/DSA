#include <iostream>
#include <stdio.h>
#include "revision.h"

CL_Rectangle::CL_Rectangle(int w, int h) : width(w), heigth(h) {};
CL_Rectangle::CL_Rectangle() : width(0), heigth(0) {};
void CL_Rectangle::init(int w, int h)
{
  this->width = w;
  this->heigth = h;
}

int CL_Rectangle::area()
{
  return this->width * this->heigth;
};

template <class T>
class Calculator
{
public:
  static T add(T a, T b);
  static T multiply(T a, T b);
};

template <class T>
T Calculator<T>::add(T a, T b)
{
  return a + b;
};

template <class T>
T Calculator<T>::multiply(T a, T b)
{
  return a * b;
};

void loopthrough(int *arr, int size)
{
  const int iterations = size / sizeof(int);
  for (int i = 0; i < iterations; ++i, arr++)
  {
    std::cout << *arr << " | ";
    printf("%d\n", *arr);
    printf("--------\n");
  }
}

void references()
{
  int a = 30;
  // no new variable is created. Just an alias
  // not possible to point to another one once it is declared and initialized. Important
  int &b = a;
  std::cout << &b << " | " << &a << std::endl;
  b += 2;
  std::cout << "\"A\" value: " << a << std::endl;

  int c = 5;
  int const *ptr_c = &c;
  // *ptr_c = 10; not possible to change the value via the pointer
  int z = 10;
  int *const ptr_z = &z;
  // ptr_z = c; not possible to change where the pointer points to
  std::cout << sizeof(c) << std::endl;
}

// or int [] get_int_arr
int *get_int_arr(int n)
{
  // returning a pointer
  return new int[n];
}

void iterate(int (&arr)[5])
{
  for (const int &ele : arr)
  {
    std::cout << "Element: " << ele << std::endl;
  }
}

void _strs()
{
  const int uppercase_flag = 32;

  char name[] = {"CHURROS"};
  char *ptr_name = name;
  const int name_sz = sizeof(name) - 1;

  for (int i = 0; i < name_sz; i++, ptr_name++)
  {
    *ptr_name += 32;
  }

  for (const &cr : name)
  {
    std::cout << (char)cr;
  }
}

void revisions()
{
  // declared on the stack
  int x[4] = {1, 2, 3, 4};
  loopthrough(x, sizeof(int) * 4);
  for (int i : x)
  {
    std::cout << i << "\n";
  }

  // declaration + initialization

  struct Rect point = {20, 20};
  std::cout << point.perimeter() << std::endl;

  struct Rect const *rect_ptr = &point;
  std::cout << "Width of rect via arrow operator: " << rect_ptr->wid << std::endl;
  std::cout << "Width of rect via dot operator: " << (*rect_ptr).wid << std::endl;

  // declaration only
  struct Rect *ptr_point = new Rect{};
  ptr_point->wid = 10;
  ptr_point->hei = 10;
  std::cout << ptr_point->perimeter() << std::endl;

  struct Rect rects[] = {
      {2, 2}, {3, 3}, {4, 4}};

  std::cout << point.perimeter() << std::endl;
  ptrs();
  references();
  parameter_passing();

  int arr_nrs[] = {1, 2, 3, 4, 5};
  arr_as_param<int, sizeof(arr_nrs) / sizeof(int)>(arr_nrs);
  arr_as_param_ptr(arr_nrs, sizeof(arr_nrs) / sizeof(int));

  // get_int_arr returns a pointer. then "ptr_to_array" points to the same address as the returned pointer
  int *ptr_to_array = get_int_arr(5);

  CL_Rectangle rect;
  rect.init(20, 20);

  CL_Rectangle rect2(10, 15);

  CL_Rectangle rect3{5, 5};

  std::cout << rect.area() << std::endl;
  std::cout << rect2.area() << std::endl;
  std::cout << rect3.area() << std::endl;
  std::cout << Calculator<int>::add(5, 10) << std::endl;
  std::cout << Calculator<float>::multiply(5.5f, 10.5f) << std::endl;

  _strs();

  delete ptr_point;
  delete ptr_to_array;
}