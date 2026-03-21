from typing import List

# compares elements to the left of the current element, shifting to right those who are greater than the element
# then the current element is placed right after the next lower value in comparison to it
# 
# Quadratic time complexity. Bad algorithm
# best case scenario, is O(N)
def insertion_sort(elements: List[int]):
  for i in range(1, len(elements)):
    tmp_value = elements[i]
    j = i - 1

    while(j >= 0 and elements[j] > tmp_value):
      elements[j + 1] = elements[j]
      j -= 1

    # position after the next lower value
    elements[j + 1] = tmp_value
  return elements

elements = [-1, 10, 5, 7, -20, 8, 9]
sorted_arr = insertion_sort(elements)
print(sorted_arr)
