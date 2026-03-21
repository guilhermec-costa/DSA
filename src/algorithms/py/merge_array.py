from typing import List

def merge_arrays(left: List[int], right: List[int]) -> List[int]:
  merged = []
  r_cursor = l_cursor = 0

  while(l_cursor < len(left) and r_cursor < len(right)):
    if(left[l_cursor] < right[r_cursor]):
      merged.append(left[l_cursor])
      l_cursor += 1
    else:
      merged.append(right[r_cursor])
      r_cursor += 1

  while(l_cursor < len(left)):
     merged.append(left[l_cursor])
     l_cursor += 1

  while(r_cursor < len(right)):
    merged.append(right[r_cursor])
    r_cursor += 1

  return merged

arr1 = [1, 3, 5]
arr2 = [2, 4, 6]
print(merge_arrays(arr1, arr2))