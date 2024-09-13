def shell_sort(lst: list) -> list:
    length = len(lst)
    gap = length // 2

    while gap > 0:
        for i in range(gap, length):
            actual = lst[i]
            j = i
            while j >= gap and actual < lst[j - gap]:
                lst[j] = lst[j - gap]
                j -= gap
            lst[j] = actual
        gap //= 2
        
    return lst
