def selection_sort(lst: list) -> list:
    aux: int
    minIndex: int

    for i in range(0, len(lst)):
        minIndex = i

        for j in range(i + 1, len(lst)):
            if lst[j] < lst[minIndex]:
                minIndex = j

        if minIndex != i:
            aux = lst[i]
            lst[i] = lst[minIndex]
            lst[minIndex] = aux

    return lst
