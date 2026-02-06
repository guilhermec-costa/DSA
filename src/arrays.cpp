#include <cstdlib>
#include <iostream>
#include <stdio.h>

void arrays()
{
  // char ls[] = {'g', 'u', 'i'};
  // printf("%c", 0 [ls]);
  // printf("%c\n", *(ls + 1));

  // int *nrs = new int[5]{0};
  // std::cout << nrs[0] << std::endl;

  // // array resize
  // int *arrX = new int[5]{1, 2, 3, 4, 5};
  // // é preciso um ponteiro intermediário
  // int *arrY = new int[10]{0};
  // for (int i = 0; i < 5; i++)
  //   arrY[i] = arrX[i];

  // delete[] arrX;
  // arrX = arrY;
  // arrY = nullptr;

  // std::cout << "array X: " << "\n";
  // for (int i = 0; i < 10; i++)
  //   std::cout << arrX[i] << "\n";

  // delete[] nrs;
  // delete[] arrX;

  // int _2d_arr[2][2] = {
  //     {1, 2},
  //     {3, 4}};

  // std::cout << "2d array: " << "\n";
  // for (int i = 0; i < 2; i++)
  // {
  //   for (int j = 0; j < 2; j++)
  //   {
  //     std::cout << _2d_arr[i][j] << "\n";
  //   }
  // }

  // int *B[3];
  // B[0] = new int[3];
  // B[1] = new int[3];
  // B[2] = new int[3];

  // // stack
  // int **C;
  // C = new int *[3];
  // C[0] = new int[3];
  // C[1] = new int[3];
  // C[2] = new int[3];

  // delete[] B[1];
  // delete[] B[2];
  // delete[] B[3];

  // int numbers[3][4] = {0};
  // for (int i = 0; i < 3; i++)
  // {
  //   for (int j = 0; j < 4; j++)
  //   {
  //     printf("%d ", numbers[i][j]);
  //   }
  //   printf("\n");
  // }

  // int mltD[10][10];
  // for (int i = 0; i < 10; i++)
  // {
  //   for (int j = 0; j < 10; j++)
  //   {
  //     mltD[i][j] = 0;
  //   }
  // }

  // int sngD[10 * 10];
  // for (int i = 0; i < 10; i++)
  // {
  //   for (int j = 0; j < 10; j++)
  //   {
  //     sngD[i * 10 + j] = 0;
  //   }
  // }

  size_t s = 5;
  int *p = new int[s]; 
  for(int i=0;i<s;i++) {
    p[i] = i * 2;
  }
  for(int i=0;i<s;i++) {
    std::cout << "Number at " << s << ": " << p[i] << "\n";
  };
  std::cout << "P value: " << *p << "\n";
  delete []p;
  std::cout << "P value: " << *p << "\n";
  p = NULL;
  std::cout << "P address: " << p << "\n";

  std::cout << "---------------\n";
  int *A = new int[5];
  int *B = new int[10];

  for(int i=0; i<5; i++){
    A[i] = i + 1; 
  };

  for(int i=0; i<5;i++){
    B[i] = A[i]; 
  };
  delete []A;
  A = B;
  B = NULL;

  std::cout << "---------------\n";
  for(int i=0; i<10; i++){
    std::cout << "A[]: " << A[i] << "\n"; 
  };
  delete []B;

  // partially on stack, partially on heap
  int* p_arr[3];
  p_arr[0] = new int[4];

  // full on heap
  int **P_to_P;
  P_to_P = new int*[3];
  P_to_P[1] = new int[4];
}