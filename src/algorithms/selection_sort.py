from typing import List


def find_lowest(arr: List[int]):
    lowest = arr[0]
    idx_of_lowest = 0

    for i in range(1, len(arr)):
        if arr[i] < lowest:
            lowest = arr[i]
            idx_of_lowest = i

    return idx_of_lowest


# O(n x n) exponential
def selection_sort(elements: List[int]):
    sorted_arr = []
    for i in range(len(elements)):
        lowest = find_lowest(elements)
        sorted_arr.append(elements.pop(lowest))

    return sorted_arr


def find_idx_of_greatest(elements: List[int]):
    greatest = elements[0]
    idx_of_greatest = 0

    for i in range(1, len(elements)):
        if elements[i] > greatest:
            greatest = elements[i]
            idx_of_greatest = i

    return idx_of_greatest


def selection_sort_greater(elements: List[int]):
    sorted_arr = []
    for i in range(len(elements)):
        greatest_item_idx = find_idx_of_greatest(elements)
        sorted_arr.append(elements.pop(greatest_item_idx))

    return sorted_arr


print(selection_sort([5, 3, 10, 3, 9, 7, 1]))
print(selection_sort_greater([5, 3, 10, 3, 9, 7, 1]))
