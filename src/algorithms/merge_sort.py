from typing import List

# merge algorithm
def merge(left_arr: List[int], right_arr: List[int]):
  left_len = len(left_arr)
  right_len = len(right_arr)
  arr = []
  l = r = 0

  while(l < left_len and r < right_len):
    if(left_arr[l] < right_arr[r]):
      arr.append(left_arr[l])
      l += 1
    else:
      arr.append(right_arr[r])
      r += 1

  while(l < left_len):
    arr.append(left_arr[l])
    l += 1

  while(r < right_len):
    arr.append(right_arr[r])
    r += 1

  return arr

# done recursively
# divide and conquer
def merge_sort(elements: List[int]):
  if len(elements) <= 1:
    return elements

  middle_idx = len(elements) // 2

  # divides the left array until it becomes 0 or 1 size
  left_arr = merge_sort(elements[:middle_idx])
  # divides the right array until it becomes 0 or 1 size
  right_arr = merge_sort(elements[middle_idx:])
  # merge the right and left arr, and forms a ordered array
  return merge(left_arr, right_arr)

elements = [1, 0, -10, 8, 5, 7, 15, 2]
sorted_arr = merge_sort(elements)
print(sorted_arr)