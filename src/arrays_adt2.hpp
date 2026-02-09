#include <iostream>
#include <optional>

class ArrayClass {
public:
  ArrayClass(int size) : _size(size) {
    arr = new int[size]{0};
    std::cout << "Array with size " << size << " created\n";
  }

  ~ArrayClass() {
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
      increase({});
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
      increase({});
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

  static int binary_search(ArrayClass &_arr, int key) {
    int low_idx = 0;
    int high_idx = _arr._len - 1;

    while (low_idx <= high_idx) {
      int mid_idx = (high_idx + low_idx) / 2;
      int mid_ele = _arr.at(mid_idx);

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

    const int last = arr[_len - 1];
    for (int i = _len - 1; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = last;
  }

  bool is_sorted() {
    for (int i = 0; i < _len - 1; i++) {
      if (arr[i] > arr[i + 1])
        return false;
    }
    return true;
  }

  void arrange_negatives_on_left() {
    int *p1 = arr;
    int *p2 = &arr[_len - 1];
    while (p1 < p2) {
      if (*p1 < 0) {
        p1++;
      } else if (*p2 >= 0) {
        p2--;
      } else {
        int tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
      }
    }
  }

  void extend(ArrayClass &arr2) {
    if (_size < _len + arr2._len) {
      increase(_len + arr2._len);
    }
    for (int j = 0; j < arr2._len; j++) {
      arr[j + _len] = arr2.at(j);
    }
    _len += arr2.length();
  }

  // theta (m+n)
  // combine twos arrays preserving sorting state
  ArrayClass merge(ArrayClass &arr2) {
    ArrayClass merged(_len + arr2._len);
    int m = 0, n = 0;

    while (m < _len && n < arr2._len) {
      if (arr[m] < arr2.at(n)) {
        merged.append(arr[m++]);
      } else {
        merged.append(arr2.at(n++));
      }
    }

    for (; m < _len;) {
      merged.append(arr[m++]);
    }

    for (; n < arr2._len;) {
      merged.append(arr2.at(n++));
    }

    return merged;
  }

  bool contains(ArrayClass &a, int value) {
    for (int i = 0; i < a.length(); i++) {
      if (a.at(i) == value)
        return true;
    }
    return false;
  }

  ArrayClass union_non_sorted(ArrayClass &arr2) {
    ArrayClass result(_len + arr2._len);
    for (int i = 0; i < _len; i++) {
      if (!contains(result, arr[i])) {
        result.append(arr[i]);
      }
    }

    for (int i = 0; i < arr2._len; i++) {
      if (!contains(result, arr2.at(i))) {
        result.append(arr2.at(i));
      }
    }

    return result;
  }

  static ArrayClass union_sorted(ArrayClass &arr1, ArrayClass &arr2) {
    ArrayClass result(arr1.length() + arr2.length());
    int m = 0, n = 0;

    while (m < arr1.length() && n < arr2.length()) {
      if (arr1.at(m) < arr2.at(n)) {
        result.append(arr1.at(m++));
      } else if (arr2.at(n) < arr1.at(m)) {
        result.append(arr2.at(n++));
      } else {
        result.append(arr1.at(m++));
        n++;
      }
    }

    for (; m < arr1.length();)
      result.append(arr1.at(m++));

    for (; n < arr2.length();)
      result.append(arr2.at(n++));

    return result;
  }

  ArrayClass *concat(ArrayClass &arr2) {
    ArrayClass *new_array = new ArrayClass(_len + arr2._len);
    for (int i = 0; i < _len; i++)
      new_array->append(arr[i]);
    for (int i = 0; i < arr2._len; i++)
      new_array->append(arr2.at(i));
    return new_array;
  }

private:
  int *arr;
  int _size = 0;
  int _len = 0;

  void increase(std::optional<int> _s) {
    int new_size = _s.value_or(size() * 2);
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
  ArrayClass array = ArrayClass(10);
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

  ArrayClass array2 = ArrayClass(10);
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

  ArrayClass array3 = ArrayClass(10);
  array3.append(7);
  array3.append(14);
  array3.append(21);
  array3.append(28);
  std::cout << "----------\n";
  std::cout << "After right shift again\n";
  array3.right_shift();
  array3.display();
  std::cout << "----------\n";
  ArrayClass array4 = ArrayClass(10);
  array4.append(1);
  array4.append(2);
  array4.append(3);
  array4.append(4);
  array4.right_rotate();
  array4.right_rotate();
  std::cout << "After right rotate \n";
  array4.display();
  std::cout << "Is array4 sorted: " << array4.is_sorted() << "\n";
  std::cout << "----------\n";
  array4.right_rotate();
  array4.right_rotate();
  array4.display();
  std::cout << "Is array4 sorted after rotations: " << array4.is_sorted()
            << "\n";

  std::cout << "----------\n";
  ArrayClass array5 = ArrayClass(10);
  array5.append(1);
  array5.append(2);
  array5.append(-1);
  array5.append(-3);
  array5.append(-2);
  array5.append(3);
  array5.append(4);
  array5.append(-4);
  array5.display();
  std::cout << "----------\n";
  std::cout << "Rearreging negative\n";
  array5.arrange_negatives_on_left();
  array5.display();
  std::cout << "----------\n";
  ArrayClass array6 = ArrayClass(5);
  ArrayClass array7 = ArrayClass(5);
  std::cout << "----------\n";
  array6.append(1);
  array6.append(2);
  array6.append(3);
  array7.append(-1);
  array7.append(-2);
  array7.append(-3);
  array6.extend(array7);
  std::cout << "After merge\n";
  array6.display();
  std::cout << "After arrange\n";
  array6.arrange_negatives_on_left();
  array6.display();

  ArrayClass *concatenated = array6.concat(array7);
  std::cout << "----------\n";
  std::cout << "After concat\n";
  concatenated->display();

  ArrayClass merged1 = ArrayClass(3);
  merged1.append(1);
  merged1.append(3);
  merged1.append(5);
  ArrayClass merged2 = ArrayClass(3);
  merged2.append(2);
  merged2.append(3);
  merged2.append(4);
  merged2.append(6);
  merged2.append(6);
  merged2.append(7);
  ArrayClass merged = merged1.merge(merged2);
  std::cout << "----------\n";
  std::cout << "After merge\n";
  merged.display();
  std::cout << "----------\n";
  std::cout << "After union non sorted\n";
  auto unified = merged.union_non_sorted(merged);
  unified.display();
  std::cout << "----------\n";

  ArrayClass list1(3);
  ArrayClass list2(3);

  list1.append(-1);
  list1.append(-2);
  list1.append(-3);
  list2.append(-1);
  list2.append(-2);
  list2.append(-3);
  list2.append(0);
  list2.append(1);
  list2.append(3);

  std::cout << "----------\n";
  std::cout << "After union sorted\n";
  ArrayClass list3 = ArrayClass::union_sorted(list1, list2);
  list3.display();
}