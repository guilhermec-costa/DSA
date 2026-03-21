#include <iostream>
#include <vector>

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

void fn1(int n) {
  if(n > 0) {
    std::cout << "N on fn1: " << n << "\n";
    fn1(n - 1);
  }
}

int sum_of_first_n_natural_numbers(int n) {
  if(n > 0) {
    return n + sum_of_first_n_natural_numbers(n - 1);
  }
  return 0;
};

int recursion_factorial(int n) {
  if(n > 0) {
    return n * recursion_factorial(n - 1);
  }
  return 1;
}

int recursion_power(int n, int power) {
  if(power > 0) {
    return n * recursion_power(n, power - 1);
  }
  return 1;
}

int recursion_fibonacci(int n) {
  if(n <= 1) {
    return 1;
  }
  return recursion_fibonacci(n - 1) + recursion_fibonacci(n - 2);
}

// head recursion
void loop2(int n)
{
  if (n > 0)
  {
    loop2(n - 1);
    // executes at returning time
    std::cout << "Element on Loop 2: " << n << "\n";
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

static int global_variable = 0;

int increment(int n) {
  if(n > 0) {
    global_variable++;
    return increment(n - 1) + global_variable + 1;
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

int store[100];

int fibonacci(int n)
{

  if (n <= 1)
  {
    store[n] = n;
    return n;
  }

  if (store[n - 2] == -1)
    store[n - 2] = fibonacci(n - 2);
  if (store[n - 1] == -1)
    store[n - 1] = fibonacci(n - 1);

  store[n] = store[n - 2] + store[n - 1];
  return store[n];
}

int fib_loop(int n)
{
  int t0 = 0, t1 = 1, s = 0;

  if (n <= 1)
    return n;

  for (int i = 2; i <= n; i++)
  {
    s = t0 + t1;
    t0 = t1;
    t1 = s;
  }

  return s;
}

void sum_ref(int &x)
{
  x += 5;
}

int recursive_fact(int t)
{
  if (t == 0)
    return 1;

  return recursive_fact(t - 1) * t;
}

int loop_fibonacci(int e)
{
  int t0 = 0, t1 = 1, s = 0;
  if (e <= 1)
    return e;

  for (int i = 2; i <= e; i++)
  {
    s = t0 + t1;
    t0 = t1;
    t1 = s;
  }

  return s;
}

void print_evens(int n) {
  if(n >= 0) {
    int is_even = n % 2 == 0;
    print_evens(n - 1);
    if(is_even) {
      printf("Even number: %d\n", n);
    }
  }
}

void recursion()
{
  int n = 3;
  print_evens(10);
  std::cout << "-----\n";
  int incr_sum = increment(7);
  std::cout << "-----" << "Incr sum: " << incr_sum << "\n";
  std::cout << "-----\n";
  fn1(n);
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

  // int taylor_base = 5;
  // const int taylor_result = taylor_series(taylor_base);
  // std::cout << "result of taylor series for value: " << taylor_base << " = " << taylor_result << std::endl;

  for (int &ele : store)
    ele = -1;

  int fib_base = 8;
  const size_t recursive_fib_memoized = fibonacci(10);
  const size_t r_fib = fib_loop(10);
  std::cout << "Fibonacci result with recursion: " << recursive_fib_memoized << std::endl;
  std::cout << "Fibonacci result with loop: " << r_fib << std::endl;

  int b = 10;
  sum_ref(b);
  std::cout << "value of b: " << b << std::endl;

  printf("%d\n", recursive_fact(5));
  printf("loop fib: %d", loop_fibonacci(5));
  printf("-------------\n");
  printf("sum of n natural numbers: %d\n", sum_of_first_n_natural_numbers(7));
  printf("-------------\n");

  printf("recursion factorial: %d\n", recursion_factorial(5));
  printf("-------------\n");
  printf("recursion power: %d\n", recursion_power(2, 5));
  printf("-------------\n");
}
