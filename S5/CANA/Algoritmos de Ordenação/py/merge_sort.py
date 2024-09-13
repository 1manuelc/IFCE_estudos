def merge(lst: list, start: int, middle: int, end: int) -> None:
    left: list = lst[start:middle]
    right: list = lst[middle:end]

    left_next: int = 0
    right_next: int = 0
    actual: int = start

    while left_next < len(left) and right_next < len(right):
        if left[left_next] <= right[right_next]:
            lst[actual] = left[left_next]
            left_next += 1
        else:
            lst[actual] = right[right_next]
            right_next += 1
        actual += 1

    # Copia os elementos restantes de left, se houver
    while left_next < len(left):
        lst[actual] = left[left_next]
        left_next += 1
        actual += 1

    # Copia os elementos restantes de right, se houver
    while right_next < len(right):
        lst[actual] = right[right_next]
        right_next += 1
        actual += 1


def merge_sort(lst: list, start: int = 0, end: int = None) -> list:
    if end is None:
        end = len(lst)

    if end - start > 1:
        middle = (start + end) // 2
        merge_sort(lst, start, middle)
        merge_sort(lst, middle, end)
        merge(lst, start, middle, end)

    return lst
