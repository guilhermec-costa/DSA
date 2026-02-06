from typing import List
from random import randint


def binary_search1(lst: List[int], ele: int):
    begin = 0
    end = len(lst) - 1

    while begin <= end:
        middle_idx = (begin + end) // 2
        guess = lst[middle_idx]
        if guess == ele:
            return middle_idx

        if guess > ele:
            end = middle_idx - 1
        else:
            begin = middle_idx + 1

    return None


def binary_search2(ordered_items: List[int], ele: int):
    begin = 0
    end = len(ordered_items) - 1

    while begin <= end:
        middle_idx = (begin + end) // 2
        middle_item = ordered_items[middle_idx]

        if middle_item == ele:
            return middle_idx

        if middle_item > ele:
            end = middle_idx - 1
        else:
            begin = middle_idx + 1

    return None


def binary_search3(elements: List[int], element: int):
    start = 0
    end = len(elements) - 1

    while start <= end:
        middle_index = (start + end) // 2
        middle_item = elements[middle_index]

        if middle_item == element:
            return middle_index

        if middle_item > element:
            end = middle_index - 1
        else:
            start = middle_index + 1

    return None


def binary_search4(elements: List[int], element: int):
    start = 0
    end = len(elements) - 1

    while start <= end:
        middle_idx = (start + end) // 2
        middle_element = elements[middle_idx]

        if middle_element == element:
            return middle_idx

        if middle_element > element:
            end = middle_idx - 1

        else:
            start = middle_idx + 1

    return None


def binary_search5(elements: List[int], element: int):
    start = 0
    end = len(elements) - 1

    while start <= end:
        middle_idx = (start + end) // 2
        middle_item = elements[middle_idx]

        if middle_item == element:
            return middle_idx

        if middle_item > element:
            end = middle_idx - 1

        else:
            start = middle_idx + 1

    return None


def binary_search6(ordered_elements: List[int], element: int):
    begin = 0
    end = len(ordered_elements) - 1

    while begin <= end:
        middle_idx = (begin + end) // 2
        middle_item = ordered_elements[middle_idx]

        if middle_item == element:
            return middle_idx

        if element > middle_item:
            begin = middle_idx + 1

        else:
            end = middle_idx - 1

def binary_search(elements: List[int], target: str):
  begin = 0
  end = len(elements) - 1

  while(begin <= end):
      middle_idx = (begin + end) // 2
      middle_item = elements[middle_idx]

      if(middle_item == target):
          return middle_idx

      if(target > middle_item):
          begin = middle_idx + 1
      else:
          end = middle_idx - 1

def bin_search(elems: List[int], target: int):
    low = 0
    high = len(elems) - 1

    while low <= high:
      mid = (low + high) // 2
      mid_item = elems[mid]

      if(mid_item == target): return mid
      if(mid_item > target):
        high = mid - 1
      else: low = mid + 1
    return None

def binary_search8(vector, target):
    low = 0;
  


lst = [1, 3, 5, 7, 9, 15, 20, 25]
# print(binary_search1(lst, 5))
# print(binary_search2(lst, 5))
# print(binary_search3(lst, 5))
# print(binary_search4(lst, 5))
# print(binary_search5(lst, 5))
# print(binary_search6(lst, 5))
print(bin_search(lst, 1))
