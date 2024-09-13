def bubble_sort(lst: list) -> list:
    n = len(lst)

    for i in range(n):
        swapped = False  # verifica se ja houve troca nesta iteracao

        for j in range(n - i - 1):
            if lst[j] > lst[j + 1]:
                # Troca os elementos
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                swapped = True  # Marca que houve troca

        # se nao houve troca, a lista ja esta ordenada
        if not swapped:
            break

    return lst
