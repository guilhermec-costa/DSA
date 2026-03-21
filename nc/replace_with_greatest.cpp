#include <vector>

using std::vector;

vector<int> replace_elements(vector<int> &arr) {
  if (arr.size() == 1) {
    arr[0] = -1;
    return arr;
  }

  for (int i = 0; i < arr.size(); i++) {
    int greatest_right = arr[i + 1];
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] > greatest_right)
        greatest_right = arr[j];
    }
    arr[i] = greatest_right;

  }

  arr[arr.size() - 1] = -1;
  return arr;
}