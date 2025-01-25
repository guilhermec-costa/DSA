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

void fnB(int n);

void fnA(int n)
{
  if (n > 0)
  {
    printf("%d\n", n);
    fnB(n - 1);
  }
}

void fnB(int n)
{
  if (n > 1)
  {
    printf("%d\n", n);
    fnA(n / 2);
  }
}

int sum_loop(int n)
{
  int s = 0;
  for (int i = 1; i < n + 1; i++)
  {
    s += i;
  }

  return s;
}

int sum_recursion(int n)
{
  if (n > 0)
  {
    return sum_recursion(n - 1) + n;
  }

  return 0;
}

int factorial_loop(int n)
{
  int total = 1;
  for (int i = n; i >= 1; i--)
  {
    std::cout << i << "\n";
    total *= i;
  }

  return total;
}

int factorial_recusion(int n)
{
  if (n <= 1)
  {
    return 1;
  }

  return factorial_recusion(n - 1) * n;
}

int exponent_recursion(int base, int exp)
{

  if (exp == 0)
  {
    return 1;
  }

  return exponent_recursion(base, exp - 1) * base;
}

int loop_exponent(int base, int exp)
{
  int r = 1;
  for (int i = 0; i < exp; i++)
  {
    r *= base;
  }

  return r;
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
  std::cout << "-----" << std::endl;

  std::cout << "-----" << std::endl;
  int u = 5;
  fnA(u);

  const int sumLoop = sum_loop(10);
  const int sumRecursion = sum_recursion(10);

  std::cout << "Sum of 10 elements with loop: " << sumLoop << std::endl;
  std::cout << "Sum of 10 elements with recursion: " << sumRecursion << std::endl;
  std::cout << "-----" << std::endl;

  int fact_loop = factorial_loop(5);
  int fact_recursion = factorial_recusion(5);
  std::cout << "Factorial of 5 with loop: " << fact_loop << std::endl;
  std::cout << "Factorial of 5 with loop: " << fact_recursion << std::endl;

  std::cout << "-----" << std::endl;

  int base = 2;
  int exponent_with_loop = loop_exponent(base, 2);
  int recursive_exponent = exponent_recursion(base, 9);
  std::cout << "5 to the power of 2 with loop: " << exponent_with_loop << std::endl;
  std::cout << "5 to the power of 2 with recursion: " << recursive_exponent << std::endl;
}