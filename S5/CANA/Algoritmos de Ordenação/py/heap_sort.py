def heapify(lst, n, i) -> None:
    largest = i  # Inicializa a raiz como o maior elemento
    temp = lst[i]  # Segura o valor da raiz
    left = 2 * i + 1  # Filho esquerdo
    right = 2 * i + 2  # Filho direito

    while left < n:
        if left < n and lst[left] > temp:  # Compara com o filho esquerdo
            largest = left
        if right < n and lst[right] > lst[largest]:  # Compara com o filho direito
            largest = right

        # Se o maior elemento não é a raiz
        if largest != i:
            lst[i] = lst[largest]  # Troca apenas o valor do nó
            i = largest  # Atualiza a posição
            left = 2 * i + 1
            right = 2 * i + 2
        else:
            break  # Se a raiz já for a maior, não precisa continuar

    lst[i] = temp  # Faz a atribuição final quando a posição correta é encontrada


def heap_sort(lst) -> list:
    n = len(lst)

    # Constrói o max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(lst, n, i)

    # Extrai elementos do heap
    for i in range(n - 1, 0, -1):
        lst[i], lst[0] = lst[0], lst[i]  # Move a raiz para o final
        heapify(lst, i, 0)  # Heapifica a subárvore reduzida

    return lst
