#include <vector>

int search_insert(std::vector<int> &nums, int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (low <= high) {
    int mid_idx = (low + high) / 2;
    int mid_item = nums[mid_idx];

    if (mid_item == target)
      return mid_idx;

    if (mid_item > target) {
      high = mid_idx - 1;
    } else {
      low = mid_idx + 1;
    }
  }

  return low;
}