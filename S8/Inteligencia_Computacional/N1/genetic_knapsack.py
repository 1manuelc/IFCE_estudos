import random


class Item:
    def __init__(self, id: int, peso: int, valor: int):
        self.id = id
        self.peso = peso
        self.valor = valor


listaItens = [
    Item(1, 10, 15),
    Item(2, 40, 90),
    Item(3, 26, 50),
    Item(4, 32, 60),
    Item(5, 8, 12),
]

CAPACIDADE = 80
MAX_GERACOES = 100
TAMANHO_POPULACAO = 10
TAXA_CRUZAMENTO = 90
TAXA_MUTACAO = 5


def calculaMetricas(listaItens, solucao):
    peso = sum([listaItens[id].peso for id, valor in enumerate(solucao) if valor == 1])
    valor = sum(
        [listaItens[id].valor for id, valor in enumerate(solucao) if valor == 1]
    )
    return peso, valor


def geraPopulacaoInicial(listaItens, CAPACIDADE):
    populacao = []
    while len(populacao) < TAMANHO_POPULACAO:
        individuo = [random.randint(0, 1) for i in range(len(listaItens))]
        if calculaMetricas(listaItens, individuo)[0] <= CAPACIDADE:
            populacao.append(individuo)
    return populacao


def selecaoTorneio(populacao, k):
    torneio = random.sample(populacao, k)
    return max(torneio, key=lambda x: calculaMetricas(listaItens, x)[1])


def cruzamento(pai, mae):
    if random.randint(0, 100) <= TAXA_CRUZAMENTO:
        ponto_corte = random.randint(0, len(pai) - 1)
        filho1 = pai[:ponto_corte] + mae[ponto_corte:]

        if calculaMetricas(listaItens, filho1)[0] > CAPACIDADE:
            filho1 = pai
        filho2 = mae[:ponto_corte] + pai[ponto_corte:]

        if calculaMetricas(listaItens, filho2)[0] > CAPACIDADE:
            filho2 = mae

        return filho1, filho2
    else:
        return pai, mae


def mutacao(individuo):
    individuo_mutado = individuo.copy()

    for i in range(len(individuo_mutado)):
        if random.randint(0, 100) <= TAXA_MUTACAO:
            individuo_mutado[i] = 1 - individuo_mutado[i]

    if calculaMetricas(listaItens, individuo_mutado)[0] > CAPACIDADE:
        return individuo

    return individuo_mutado


def algoritmoGenetico(listaItens, CAPACIDADE):
    populacao = geraPopulacaoInicial(listaItens, CAPACIDADE)

    for _ in range(MAX_GERACOES):
        novaPopulacao = []
        for _ in range(TAMANHO_POPULACAO // 2):
            pai = selecaoTorneio(populacao, 3)
            mae = selecaoTorneio(populacao, 3)

            filho1, filho2 = cruzamento(pai, mae)
            filho1 = mutacao(filho1)
            filho2 = mutacao(filho2)

            novaPopulacao.append(filho1)
            novaPopulacao.append(filho2)
        populacao = novaPopulacao
    return populacao


populacao = algoritmoGenetico(listaItens, CAPACIDADE)
print(populacao)
print(max(populacao, key=lambda x: calculaMetricas(listaItens, x)[1]))


def main():
    algoritmoGenetico(listaItens, CAPACIDADE)


main()
