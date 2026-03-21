#include <algorithm>
#include <unordered_map>
#include <vector>

int majority_element(std::vector<int> &nums) {

  std::unordered_map<int, int> m;

  std::for_each(nums.begin(), nums.end(), [&m](int n) { m[n]++; });

  int max = 0;
  int key = 0;
  for (const auto &[k, v] : m) {
    if (v > max) {
      max = v;
      key = k;
    }
  }

  return key;
}