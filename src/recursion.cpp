#include <iostream>

// tail recursion
void loop(int n)
{
  if (n > 0)
  {
    // executes at calling time
    std::cout << "Element: " << n << "\n";
    loop(n - 1);
  }
}

// head recursion
void loop2(int n)
{
  if (n > 0)
  {
    loop2(n - 1);
    // executes at returning time
    std::cout << "Element: " << n << "\n";
  }
}

// tail recursion && head recursion
int fun(int n)
{
  if (n > 0)
  {
    return fun(n - 1) + n;
  }

  return 0;
}

// recursion with static variable
int fun_with_static(int n)
{
  // same with global variables
  static int s = 0;

  if (n > 0)
  {
    s++;
    return fun_with_static(n - 1) + s;
  }

  return 0;
}

void recursion()
{
  int n = 3;
  loop(n);
  std::cout << "-----\n";
  loop2(n);
  std::cout << "-----\n";

  int x = 3;
  printf("%d\n", fun(x));
  std::cout << "-----\n";

  printf("%d", fun_with_static(x));
}