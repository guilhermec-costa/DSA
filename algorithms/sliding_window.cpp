#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>

static void display(std::vector<int> &arr) {
  for (int i : arr) {
    printf("%d - ", i);
  }
}

static int max_sum_subarr_sizek(std::vector<int> &arr, int k) {
  int cur_sum, best_sum;
  cur_sum = best_sum = std::accumulate(arr.begin(), arr.begin() + k, 0);
  for(int r=k;r<arr.size();r++) {
    cur_sum = cur_sum + arr[r] - arr[r-k];
    best_sum = std::max(best_sum, cur_sum);
  }
  return best_sum;
}

void sliding_window() {
  std::vector<int> t{1, 2, 3, 4, 5};
  int sum = max_sum_subarr_sizek(t, 3);
  printf("Sum: %d", sum);
}