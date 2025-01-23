#ifndef POINTER_H
#define POINTER_H

#include <iostream>
#include <memory>
#include <stdio.h>

void ptrs()
{

  int stack_nr = 10;

  // pointer is stacked on the stack
  int *ptr_nr = &stack_nr;
  int *ptr_to_heap = new int(5);

  int numbers[] = {1, 2, 3, 4, 5};
  int *ptr_to_numbers = numbers;
  int *ptr_to_numberspt2 = &(numbers[0]);

  std::cout << ptr_to_numbers << std::endl;
  std::cout << ptr_to_numberspt2 << std::endl;

  delete ptr_to_heap;

  for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i)
  {
    std::cout << "Element: " << ptr_to_numbers[i] << std::endl;
  }
}

#endif