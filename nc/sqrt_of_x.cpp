int sqrt_of_x(int x) {
  int low = 0, high = x, l = 0;
  while (low <= high) {
    int root_idx = (low + high) / 2;
    int root = root_idx;

    long long result = 1LL * root * root;
    if (result == x)
      return root;

    if (result > x)
      high = root_idx - 1;
    else
      low = root_idx + 1;
  }
  return low - 1;
}