#include <iostream>

class MyArrayADT {
public:
  MyArrayADT(int size) : _size(size) {
    arr = new int[size]{0};
    std::cout << "Array with size " << size << " created\n";
  }

  ~MyArrayADT() {
    delete[] arr;
    std::cout << "Array with size " << _size << " deleted\n";
  }

  int size() { return this->_size; }

  int length() { return this->_len; }

  // O(1)
  int at(int idx) {
    if (idx < 0 || idx >= _len) {
      std::cout << "Invalid index\n";
      return 0;
    }
    return this->arr[idx];
  }

  // O(n)
  void display() {
    for (int i = 0; i < _len; i++) {
      std::cout << "Element in index " << i << ": " << at(i) << "\n";
    }
  }

  // O(1)
  void append(int element) {
    if (_len == _size) {
      increase();
    }
    arr[_len++] = element;
  }

  // best case: O(1) - no shift
  // worst case: O(n) - shift all elements
  void insert(int idx, int element) {
    if (idx < 0 || idx > _len) {
      std::cout << "Invalid index\n";
      return;
    }
    if (_len == _size) {
      increase();
    }
    // _len is the next free space
    for (int i = _len; i > idx; i--) {
      arr[i] = arr[i - 1];
    }
    arr[idx] = element;
    _len++;
  }

  // best case: O(1) - no shift
  // worst case: O(n) - shift all elements
  int remove(int idx) {
    if (idx < 0 || idx >= _len) {
      std::cout << "Invalid index\n";
      return 0;
    }
    // from index to penultimate item (i < _len - 1 or i <= len - 2)
    int _x = arr[idx];
    for (int i = idx; i < _len - 1; i++) {
      arr[i] = arr[i + 1];
    }
    _len--;
    return _x;
  }

  // best case: O(1) - first element
  // worst case: O(n) - last element
  int linear_search(int key) {
    for (int i = 0; i < _len; i++) {
      if (arr[i] == key) {
        return i;
      }
    }
    return -1;
  }

  int binary_search(int key) {
    int low_idx = 0;
    int high_idx = _len - 1;

    while (low_idx <= high_idx) {
      int mid_idx = (high_idx + low_idx) / 2;
      int mid_ele = arr[mid_idx];

      if (mid_ele == key)
        return mid_idx;
      if (mid_ele > key) {
        high_idx = mid_idx - 1;
      } else {
        low_idx = mid_idx + 1;
      }
    }

    return -1;
  }

  int recursive_binary_search(int key, int low, int high) {
    // base case 1
    if (low > high)
      return -1;

    const int mid_idx = (low + high) / 2;
    const int mid_ele = arr[mid_idx];

    // base case 2
    if (mid_ele == key)
      return mid_idx;

    if (mid_ele > key) {
      return recursive_binary_search(key, low, mid_idx - 1);
    } else {
      return recursive_binary_search(key, mid_idx + 1, high);
    }
  }

  void set(int idx, int key) {
    if (idx < 0 || idx >= _len) {
      std::cout << "Invalid index\n";
      return;
    }
    arr[idx] = key;
  }

  // O(n)
  int max() {
    int max = arr[0];
    for (int i = 1; i < _len; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }

  // O(n)
  int min() {
    int min = arr[0];
    for (int i = 1; i < _len; i++) {
      if (arr[i] < min) {
        min = arr[i];
      }
    }
    return min;
  }

  // O(n)
  int sum() {
    int _sum = 0; // 1
    for (int i = 0; i < _len; i++) {
      // 1        // n + 1   n
      _sum += arr[i]; // n
    }
    return _sum; // 1
    // n + n + 1 + 1 + 1 = 2n + 3 = O(n)
  }

  int recursive_sum(int idx) {
    if (idx == _len)
      return 0;
    return arr[idx] + recursive_sum(idx + 1);
  }

  int avg() {
    const int _s = recursive_sum(0);
    return _s / _len;
  }

  void reverse() {
    int *p1 = arr;
    int *p2 = &arr[_len - 1];

    // swap algorithm
    while (p1 < p2) {
      int tmp = *p1;
      *p1 = *p2;
      *p2 = tmp;
      p1++;
      p2--;
    }
  }

  void reverse_shit() {
    int *tmp = new int[_size];
    for (int i = _len - 1, j = 0; i >= 0;) {
      tmp[j++] = arr[i--];
    }
    delete[] arr;
    arr = tmp;
  }

  void left_shift() {
    if (_len == 0)
      return;

    for (int i = 0; i < _len - 1; i++) {
      arr[i] = arr[i + 1];
    }
    arr[_len - 1] = 0;
    --_len;
  }

  void left_rotate() {
    if (_len == 0)
      return;

    const int first = arr[0];
    for (int i = 0; i < _len - 1; i++) {
      arr[i] = arr[i + 1];
    }
    arr[_len - 1] = first;
  }

  void right_shift() {
    if (_len == 0)
      return;
    for (int i = _len - 1; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = 0;
    --_len;
  }

  void right_rotate() {
    if (_len == 0)
      return;

    const int last = arr[_len-1];
    for (int i = _len - 1; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = last;
  }

private:
  int *arr;
  int _size = 0;
  int _len = 0;

  void increase() {
    int new_size = size() * 2;
    int *new_arr = new int[new_size]{0};
    for (int i = 0; i < length(); i++) {
      new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    new_arr = NULL;
    _size = new_size;
  };
};

void arrays_adt2() {
  MyArrayADT array = MyArrayADT(10);
  std::cout << "Size of the array: " << array.size() << "\n";
  array.append(5);
  array.append(10);
  array.append(15);
  array.append(20);
  array.insert(0, 2);
  array.insert(0, 100);
  array.display();
  std::cout << "----------\n";
  array.remove(2);
  array.display();
  array.remove(2);
  std::cout << "----------\n";
  array.display();
  std::cout << "----------\n";
  std::cout << "Position of 15: " << array.linear_search(15) << "\n";
  std::cout << "----------\n";
  std::cout << "Testing binary search\n";

  MyArrayADT array2 = MyArrayADT(10);
  array2.append(100);
  array2.append(150);
  array2.append(200);
  array2.append(250);
  array2.append(300);
  std::cout << "----------\n";
  array2.display();
  std::cout << "Position of 300: " << array2.binary_search(300) << "\n";
  std::cout << "Position of 300: " << array2.recursive_binary_search(150, 0, 4)
            << "\n";

  std::cout << "Sum with loop: " << array2.sum() << "\n";
  std::cout << "Sum with recursion: " << array2.recursive_sum(0) << "\n";
  std::cout << "Avg: " << array2.avg() << "\n";
  std::cout << "----------\n";
  std::cout << "Before reverse\n";
  array2.display();
  std::cout << "After reverse\n";
  array2.reverse();
  array2.display();
  std::cout << "After reverse shit\n";
  array2.reverse_shit();
  array2.display();
  std::cout << "After left shift\n";
  array2.left_shift();
  array2.display();
  std::cout << "After left shift again\n";
  array2.left_shift();
  array2.display();

  MyArrayADT array3 = MyArrayADT(10);
  array3.append(7);
  array3.append(14);
  array3.append(21);
  array3.append(28);
  std::cout << "----------\n";
  std::cout << "After right shift again\n";
  array3.right_shift();
  array3.display();
  std::cout << "----------\n";
  MyArrayADT array4 = MyArrayADT(10);
  array4.append(1);
  array4.append(2);
  array4.append(3);
  array4.append(4);
  array4.right_rotate();
  array4.right_rotate();
  std::cout << "After right rotate \n";
  array4.display();
}
