#include <iostream>
#include <vector>

/* Range sum[l, r] =  [pr] - [pl-1]
 if l = 0 (l - 1 would -1, invalid index), two options:
  1. subtract nothing
  or
  2. add an extra element at the beginning of the prefix sum array with value 0
    , and access r + 1 element. It would be something like: Range sum[l, r] =
 [pr+1] - [pl]
*/

std::vector<int> prefix_sum(std::vector<int> &nums) {
  std::vector<int> prefix(nums.size(), 0);
  prefix[0] = nums[0];

  for (int i = 1; i < prefix.size(); i++) {
    prefix[i] = nums[i] + prefix[i - 1];
  }
  return prefix;
}

std::vector<int> prefix_sum2(std::vector<int> &nums) {
  std::vector<int> prefix(nums.size() + 1, 0);

  for (int i = 1; i < prefix.size(); i++) {
    prefix[i] = prefix[i - 1] + nums[i - 1];
  }
  return prefix;
}

// The original formula: Range sum[l, r] =  [pr] - [pl-1]
// but each element is displaced by one place. So it becomes:
// Range sum[l, r] =  [pr+1] - [pl-1+1] = [pr+1] - [pl]
int range_sum(std::vector<int> &nums, int l, int r) {
  std::vector<int> prefix(nums.size() + 1, 0);
  for (int i = 1; i < prefix.size(); i++) {
    prefix[i] = prefix[i - 1] + nums[i - 1];
  }

  return prefix[r + 1] - prefix[l];
}