def merge(lst: list, start: int, middle: int, end: int) -> None:
    left: list = lst[start:middle]  # divide a lista pelos indices esq e dir
    right: list = lst[middle:end]

    # determina o proximo elemento a entrar na lista mesclada em cada sublista,
    # os menores ja estao no inicio, o indice so aumenta
    left_next: int = 0
    right_next: int = 0
    actual: int = start  # define o numero da vez a ser mesclado

    # enquanto os indice dos numeros das listas forem menores que o comprimento delas
    while left_next < len(left) and right_next < len(right):
        # decide qual numero vai ser incluido na lista final, da lista esquerda
        # ou da lista direita, e incrementa a posicao
        if left[left_next] <= right[right_next]:
            lst[actual] = left[left_next]
            left_next += 1
        else:
            lst[actual] = right[right_next]
            right_next += 1
        actual += 1  # incrementa o indice da lista final

    # os casos a seguir acontecem quando uma das listas divididas foi esvaziada,
    # a outra deve ser copiada integralmente para a lista final

    # copia os elementos restantes de left, se houverem
    while left_next < len(left):
        lst[actual] = left[left_next]
        left_next += 1
        actual += 1
    # copia os elementos restantes de right, se houverem
    while right_next < len(right):
        lst[actual] = right[right_next]
        right_next += 1
        actual += 1


def merge_sort(lst: list, start: int = 0, end: int = None) -> list:
    # somente para nao precisar passar o tamanho da lista por argumento
    if end is None:
        end = len(lst)

    # enquanto o tamanho das sublistas for > 1
    if end - start > 1:
        middle = (start + end) // 2  # calcula a posicao do meio por divisao inteira
        merge_sort(
            lst, start, middle
        )  # continua dividindo recursivamente a lista do inicio ate o meio
        merge_sort(
            lst, middle, end
        )  # continua dividindo recursivamente a lista do meio ate o fim
        merge(lst, start, middle, end)  # mescla ordenadamente as sublistas recursivas

    return lst


def partition(lst: list, left, right) -> int:
    # considera o indice do pivo atual o comeco da sublista
    partition_index = left

    # itera a lista a partir do inicio + 1
    for j in range(left + 1, right):
        # troca os numeros menores para tras e aumenta o indice do pivo
        if lst[j] < lst[left]:
            partition_index += 1
            lst[partition_index], lst[j] = lst[j], lst[partition_index]

    # troca o inicio da lista para o pivo
    lst[left], lst[partition_index] = lst[partition_index], lst[left]
    return partition_index


def quick_sort(lst: list, left: int = 0, right: int = None) -> list:
    # somente para nao precisar passar o tamanho da lista por argumento
    if right is None:
        right = len(lst)

    # enquanto o comprimento das sublistas for diferente
    if right > left:
        # determine o indice do pivo
        partition_index = partition(lst, left, right)

        # ordene as duas sublistas a esquerda e direita do pivo
        quick_sort(lst, left, partition_index - 1)
        quick_sort(lst, partition_index + 1, right)

    return lst
