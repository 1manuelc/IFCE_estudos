def counting_sort(originalList: list) -> list:
    listLength = len(originalList)

    # recebe o maior valor da lista para max de digitos
    greater: int = max(originalList)

    # inicializa uma lista de ordenados e a lista de contagem de ocorrencias
    sortedList: list = [0 for _ in range(listLength)]
    countingList: list = [0 for _ in range(greater + 1)]

    # atualiza a lista de contagem
    for i in range(0, listLength):
        countingList[originalList[i]] += 1

    # atualiza as posicoes corretas da lista de contagem
    for j in range(1, greater + 1):
        countingList[j] += countingList[j - 1]

    # monta a lista ordenada com base na de contagem
    for k in range(listLength - 1, 0, -1):
        sortedList[countingList[originalList[k]] - 1] = originalList[k]
        countingList[originalList[k]] -= 1

    return sortedList

def counting_sort_radix(originalList: list, exp: int) -> list:
    length = len(originalList)
    sortedList = [0 for _ in range(length)]
    countingList = [0 for _ in range(10)]  # contagem para cada digito (0-9)

    # conta ocorrencias dos digitos (considerando o exp atual)
    for i in range(length):
        index = (originalList[i] // exp) % 10
        countingList[index] += 1

    # atualiza a contagem para ter as posicoes corretas
    for j in range(1, 10):
        countingList[j] += countingList[j - 1]

    # constroi a lista ordenada
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

from bruteforce_methods import selection_sort


def bucket_sort(originalList: list) -> list:
    # define o numero de baldes
    bucket_count = len(originalList)
    max_value = max(originalList)
    min_value = min(originalList)

    # cria baldes vazios
    buckets: list = [[] for _ in range(bucket_count)]

    # coloca os elementos nos baldes adequados
    for num in originalList:
        index = int((num - min_value) / (max_value - min_value + 1) * bucket_count)
        buckets[index].append(num)

    # ordena cada balde individualmente
    for i in range(bucket_count):
        buckets[i] = selection_sort(buckets[i])

    # concatena todos os baldes em uma lista final ordenada
    sortedList = []
    for bucket in buckets:
        sortedList.extend(bucket)

    return sortedList
