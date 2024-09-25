def heapify(lst, n, i) -> None:
    largest = i  # inicializa a raiz como o maior elemento
    temp = lst[i]  # recebe o valor da raiz
    left = 2 * i + 1  # filho esquerdo
    right = 2 * i + 2  # filho direito

    while left < n:
        if left < n and lst[left] > temp:  # compara com o filho esquerdo
            largest = left
        if right < n and lst[right] > lst[largest]:  # compara com o filho direito
            largest = right

        # se o maior elemento nao corresponde a raiz
        if largest != i:
            lst[i] = lst[largest]  # troca apenas o valor do no
            i = largest  # atualiza a posição
            left = 2 * i + 1
            right = 2 * i + 2
        else:
            break  # se a raiz ja for a maior, nao precisa continuar

    lst[i] = temp  # faz a atribuicao final quando a posicao correta foi encontrada


def heap_sort(lst) -> list:
    n = len(lst)

    # constroi o max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(lst, n, i)

    # extrai elementos do heap
    for i in range(n - 1, 0, -1):
        lst[i], lst[0] = lst[0], lst[i]  # Move a raiz para o final
        heapify(lst, i, 0)  # Heapifica a sub-arvore reduzida

    return lst
