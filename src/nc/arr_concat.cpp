#include <iostream>
#include <vector>

void array_concatenation(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> ans(n*2);
  for (int i = 0; i < n; i++) {
    ans[i] = nums[i];
    ans[i + n] = nums[i];
  }

  for(int num: ans) {
    std::cout << "Number: " << num << "\n";
  }
}