from typing import List


def array_sum(elements: List[int]):
    if len(elements) == 1:
        return elements[0]

    return elements[0] + array_sum(elements[1:])


print(array_sum([1, 2, 3, 4, 5]))
