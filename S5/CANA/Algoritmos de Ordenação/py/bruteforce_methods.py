def bubble_sort(lst: list) -> list:
    n = len(lst)

    # em toda a lista
    for i in range(n):
        swapped = False  # verifica se ja houve troca nesta iteracao

        # desconsiderando a ultima posicao n - i (maior elemento ja borbulhado)
        for j in range(n - i - 1):
            # se houver um elemento maior que o outro anterior a ele, troque
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                swapped = True  # marca que houve troca

        # se nao houve troca em toda a iteracao, a lista ja esta ordenada
        if not swapped:
            break

    return lst


def insertion_sort(lst: list) -> list:
    actual: int
    j: int

    # inicia as iteracoes em 1 (ate n) para haver elementos anteriores para comparar
    # escolhe um valor para comparar com os anteriores representados por j
    for i in range(1, len(lst)):
        actual = lst[i]
        j = i - 1

        # enquanto houver anteriores E o elemento anterior da vez for maior que o atual,
        # empurre o anterior uma posicao para frente e volte uma posicao
        while j >= 0 and lst[j] > actual:
            lst[j + 1] = lst[j]
            j -= 1

        # coloque o elemento atual uma posicao apos onde parou a iteracao
        lst[j + 1] = actual

    return lst


def selection_sort(lst: list) -> list:
    aux: int
    minIndex: int

    # itera toda a lista
    for i in range(0, len(lst)):
        # como nao sabemos qual o menor da lista ainda, supomos que esta na posicao atual
        minIndex = i

        # busca um numero menor que o do indice, atualiza se achar um
        for j in range(i + 1, len(lst)):
            if lst[j] < lst[minIndex]:
                minIndex = j

        # se o indice do menor numero foi alterado, troque ele com o numero da iteracao atual
        if minIndex != i:
            aux = lst[i]
            lst[i] = lst[minIndex]
            lst[minIndex] = aux

    return lst
