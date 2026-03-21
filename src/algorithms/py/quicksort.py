from typing import List


def qsort_asc(elements: List[int]):
    if len(elements) < 2:
        return elements
    else:
        pivot = elements[0]
        lowest_elements = [e for e in elements[1:] if e <= pivot]
        highest_elements = [e for e in elements[1:] if e > pivot]
        return qsort_asc(lowest_elements) + [pivot] + qsort_asc(highest_elements)


def qsort_desc(elements: List[int]):
    if len(elements) < 2:
        return elements
    else:
        pivot = elements[0]
        low = [e for e in elements[1:] if e <= pivot]
        high = [e for e in elements[1:] if e > pivot]
        return qsort_desc(high) + [pivot] + qsort_desc(low)


print(qsort_asc([10, 5, 2, 3]))
print(qsort_desc([10, 5, 2, 3]))
