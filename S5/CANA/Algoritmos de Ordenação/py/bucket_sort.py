from selection_sort import *


def bucket_sort(originalList: list) -> list:
    # Definir o número de buckets
    bucket_count = len(originalList)
    max_value = max(originalList)
    min_value = min(originalList)

    # Criar buckets vazios
    buckets: list = [[] for _ in range(bucket_count)]

    # Colocar os elementos nos buckets adequados
    for num in originalList:
        index = int((num - min_value) / (max_value - min_value + 1) * bucket_count)
        buckets[index].append(num)

    # Ordenar cada bucket individualmente
    for i in range(bucket_count):
        buckets[i] = selection_sort(buckets[i])

    # Concatenar todos os buckets em uma lista final ordenada
    sortedList = []
    for bucket in buckets:
        sortedList.extend(bucket)

    return sortedList
