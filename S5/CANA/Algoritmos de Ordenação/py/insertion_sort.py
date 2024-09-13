def insertion_sort(lst: list) -> list:
    actual: int
    j: int

    for i in range(1, len(lst)):
        actual = lst[i]
        j = i - 1

        while j >= 0 and lst[j] > actual:
            lst[j + 1] = lst[j]
            j -= 1

        lst[j + 1] = actual

    return lst
