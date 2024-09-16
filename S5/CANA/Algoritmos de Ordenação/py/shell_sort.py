def shell_sort(lst: list) -> list:
    length = len(lst)
    gap = length // 2  # inicializa o gap

    while gap > 0:
        for i in range(gap, length):
            actual = lst[i]
            j = i

            # compara o valor atual com os valores do gap, se for menor troca
            while j >= gap and actual < lst[j - gap]:
                lst[j] = lst[j - gap]
                j -= gap

            lst[j] = actual  # atualiza posicao do valor atual

        gap //= 2  # atualiza o gap para proxima iteracao

    return lst
