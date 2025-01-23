#ifndef REVISION_H
#define REVISION_H

#include <iostream>
#include <stdio.h>
#include "pointers.h"
#include "parameter_passing.h"
#include "structs.h"

// Classe CL_Rectangle
class CL_Rectangle
{
private:
  int width, heigth;

public:
  CL_Rectangle(int w, int h);
  CL_Rectangle();

  void init(int w, int h);
  int area();
};

void loopthrough(int *arr, int size);
int *get_int_arr(int n);
void references();
void iterate(int (&arr)[5]);
void _strs();

#endif // REVISION_H
