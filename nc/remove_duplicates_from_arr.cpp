#include <iostream>
#include <vector>

void display_vector(std::vector<int> &vec) {
  for (const int i : vec) {
    std::cout << i << " | ";
  }
  std::cout << "\n";
}

int remove_duplicates(std::vector<int> &nums) {
  if (!nums.size())
    return 0;

  int target = 0, i = 0;
  for (; i < nums.size(); i++) {
    target = nums[i];
    if (target != nums[i + 1])
      continue;
    int k = i + 1, j = i + 1;
    for (; j < nums.size(); j++) {
      if (nums[j] != target) {
        nums[k++] = nums[j];
      }
    }
  }

  int un_c = 0;
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] < nums[i + 1]) {
      un_c++;
      continue;
    }
    if (nums[i] > nums[i + 1] || nums[i] == nums[i + 1]) {
      un_c++;
      break;
    }
  }

  return un_c;
}

int remove_duplicates2(std::vector<int> &nums) {
  if (nums.empty())
    return 0;

  int k = 1;

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] != nums[i - 1]) {
      nums[k++] = nums[i];
    }
  }
  return k;
}