def counting_sort_radix(originalList: list, exp: int) -> list:
    length = len(originalList)
    sortedList = [0 for _ in range(length)]
    countingList = [0 for _ in range(10)]  # Contagem para cada dígito (0-9)

    # Contar ocorrências dos dígitos (considerando o exp atual)
    for i in range(length):
        index = (originalList[i] // exp) % 10
        countingList[index] += 1

    # Atualizar a contagem para ter as posições corretas
    for j in range(1, 10):
        countingList[j] += countingList[j - 1]

    # Construir a lista ordenada
    for k in range(length - 1, -1, -1):
        index = (originalList[k] // exp) % 10
        sortedList[countingList[index] - 1] = originalList[k]
        countingList[index] -= 1

    return sortedList


def radix_sort(lst: list) -> list:
    # Encontrar o maior número para saber quantos dígitos são necessários
    maxValue = max(lst)

    # Aplicar counting sort para cada dígito
    exp = 1
    while maxValue // exp > 0:
        lst = counting_sort_radix(lst, exp)
        exp *= 10

    return lst
