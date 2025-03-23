from typing import List

# algoritmo horroroso. O^2. Quadratic
def bubble_sort(elements: List[int]):
  for i in range(0, len(elements)):
    # -1: needs to stop before the last element at the first iteration
    for j in range(0, len(elements) - i - 1):
      if elements[j] < elements[j + 1]:
        tmp = elements[j]
        elements[j] = elements[j + 1]
        elements[j+1] = tmp

  return elements


elements = [1,10, 5, 0, -1, 2, 7]
sorted_array = bubble_sort(elements)
print(sorted_array)