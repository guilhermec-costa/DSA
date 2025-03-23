from typing import List

def merge(left_arr: List[int], right_arr: List[int]):
  left_len = len(left_arr)
  right_len = len(right_arr)
  arr = []
  i = l = r = 0

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
  left_arr = merge_sort(elements[:middle_idx])
  right_arr = merge_sort(elements[middle_idx:])
  return merge(left_arr, right_arr)

elements = [1, 0, -10, 8, 5, 7, 15, 2]
sorted_arr = merge_sort(elements)
print(sorted_arr)