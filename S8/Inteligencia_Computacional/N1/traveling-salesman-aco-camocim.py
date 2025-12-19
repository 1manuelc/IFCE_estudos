import random
from typing import Dict, List, Optional, Tuple

# ======== 1. DEFINIÇÃO DO GRAFO ======================

mapaGrafo: Dict[str, Dict[str, int]] = {
    "Camocim": {"Passagem": 34, "Granja": 24},
    "Passagem": {"Camocim": 34, "Barroquinha": 27},
    "Barroquinha": {"Passagem": 27, "Ibuguacu": 40},
    "Ibuguacu": {"Barroquinha": 40, "Vicosa do Ceara": 31},
    "Santa Terezinha": {
        "Granja": 30,
        "Campanario": 28,
        "Vicosa do Ceara": 26,
    },
    "Vicosa do Ceara": {
        "Ibuguacu": 31,
        "Santa Terezinha": 26,
        "Santa Luzia": 27,
        "Tiangua": 21,
    },
    "Tiangua": {
        "Vicosa do Ceara": 21,
        "Arapa": 16,
        "Frecheirinha": 21,
        "Ubajara": 16,
    },
    "Ubajara": {"Tiangua": 16, "Ibiapina": 8},
    "Ibiapina": {"Ubajara": 8, "Mucambo": 16, "Sao Benedito": 14},
    "Sao Benedito": {
        "Ibiapina": 14,
        "Pacuja": 19,
        "Guaraciaba do Norte": 18,
        "Carnaubal": 16,
    },
    "Carnaubal": {"Sao Benedito": 16, "Guaraciaba do Norte": 21, "Croata": 28},
    "Croata": {"Carnaubal": 28, "Guaraciaba do Norte": 32, "Ipu": 23},
    "Guaraciaba do Norte": {
        "Carnaubal": 21,
        "Sao Benedito": 18,
        "Reriutaba": 19,
        "Ipu": 18,
        "Croata": 32,
    },
    "Ipu": {
        "Guaraciaba do Norte": 18,
        "Varjota": 30,
        "Croata": 23,
    },
    "Varjota": {"Ipu": 30, "Reriutaba": 13, "Carire": 28},
    "Reriutaba": {
        "Guaraciaba do Norte": 19,
        "Pacuja": 22,
        "Carire": 24,
        "Varjota": 13,
    },
    "Carire": {
        "Mucambo": 29,
        "Aprazivel": 22,
        "Varjota": 28,
        "Reriutaba": 24,
    },
    "Pacuja": {
        "Sao Benedito": 19,
        "Mucambo": 9,
        "Reriutaba": 22,
    },
    "Mucambo": {
        "Ibiapina": 16,
        "Aprazivel": 26,
        "Carire": 29,
        "Pacuja": 9,
    },
    "Aprazivel": {
        "Frecheirinha": 28,
        "Aroeiras": 14,
        "Carire": 22,
        "Mucambo": 26,
    },
    "Frecheirinha": {"Tiangua": 21, "Aprazivel": 28},
    "Arapa": {
        "Tiangua": 16,
        "Santa Luzia": 14,
        "Coreau": 29,
    },
    "Santa Luzia": {
        "Vicosa do Ceara": 27,
        "Campanario": 20,
        "Arapa": 14,
    },
    "Campanario": {
        "Santa Terezinha": 28,
        "Granja": 29,
        "Moraujo": 13,
        "Santa Luzia": 20,
    },
    "Granja": {"Camocim": 24, "Santa Terezinha": 30, "Campanario": 29},
    "Moraujo": {"Campanario": 13, "Coreau": 10},
    "Coreau": {"Moraujo": 10, "Aroeiras": 11},
    "Aroeiras": {"Coreau": 11, "Aprazivel": 14},
}


# ======== 2. PARÂMETROS PADRÃO DO ACO ================

influenciaFeromonio = 1.0
influenciaDistancia = 4.0  # (1/distância)
taxaEvaporacaoFeromonio = 0.5  # (0.1 - 0.3 memória forte, 0.4 - 0.6 equilíbro memória/exploração, 0.7 - 0.9 exploração intensiva)
quantidadePadraoFeromonio = 100.0  # quantidade de feromônio depositado
num_formigas = 10
num_iteracoes = 100
cidade_inicial = "Croata"
cidade_final = "Camocim"
max_iteracoes_sem_melhora = 10


# ======== 3. FUNÇÕES AUXILIARES ======================


def calcular_distancia(caminho: List[str], grafo: Dict[str, Dict[str, int]]) -> float:
    # Calcula a distância total percorrida por uma formiga em sua rota, somando as distâncias entre cidades consecutivas no caminho.
    return sum(grafo[caminho[i]][caminho[i + 1]] for i in range(len(caminho) - 1))


def escolher_proxima_cidade(
    cidade_atual: str,
    visitadas: List[str],
    grafo: Dict[str, Dict[str, int]],
    feromonioNaAresta: Dict[Tuple[str, str], float],
    distanciaNaAresta: Dict[Tuple[str, str], float],
) -> Optional[str]:
    # escolhe a próxima cidade com base na regra de transição de probabilidade do ACO.

    # filtra apenas os vizinhos ainda não visitados
    vizinhos = [v for v in grafo[cidade_atual].keys() if v not in visitadas]
    if not vizinhos:
        return None

    # calcula o "peso" (atratividade) de cada cidade vizinha, onde a probabilidade de escolha é:
    # P(v) = (feromonioNaAresta_ij ^ influenciaFeromonio) * (distanciaNaAresta_ij ^ influenciaDistancia) / soma_de_todas_as_probabilidades
    probabilidades = []
    for v in vizinhos:
        p = (feromonioNaAresta[(cidade_atual, v)] ** influenciaFeromonio) * (
            distanciaNaAresta[(cidade_atual, v)] ** influenciaDistancia
        )
        probabilidades.append(p)

    # normaliza as probabilidades (para que a soma seja = 1)
    soma_probabilidades = sum(probabilidades)
    probabilidades = [p / soma_probabilidades for p in probabilidades]

    # roleta para sortear a próxima cidade com base nas probabilidades calculadas
    return random.choices(vizinhos, weights=probabilidades, k=1)[0]


# ======== 4. FUNÇÃO PRINCIPAL DO ACO ================


def executar_aco() -> Tuple[Optional[List[str]], float]:
    # ===== inicializacao de variaveis controladoras =====
    cidades = list(mapaGrafo.keys())

    # feromônio em cada aresta (inicialmente igual a 1)
    feromonioNaAresta = {(i, j): 1.0 for i in cidades for j in mapaGrafo[i].keys()}

    # heurística (1/distância) para cada aresta
    distanciaNaAresta = {
        (i, j): 1.0 / dist for i in cidades for j, dist in mapaGrafo[i].items()
    }

    melhor_rota: Optional[List[str]] = None
    melhor_distancia: float = float("inf")
    rota_passada = melhor_rota
    contador_sem_melhora: int = 0

    # ===== loop principal =====s
    for it in range(num_iteracoes):
        if contador_sem_melhora == max_iteracoes_sem_melhora:
            print(
                f"\tlimite de iteracoes sem melhora atingido ({max_iteracoes_sem_melhora})"
            )
            break

        todas_rotas = []  # rotas de todas as formigas
        todas_distancias = []  # distâncias de cada rota

        # ===== construcao das solucoes =====
        for _ in range(num_formigas):
            atual = cidade_inicial  # todas as formigas começam na cidade inicial
            visitadas = [cidade_inicial]
            rota = [cidade_inicial]

            # formiga caminha até alcançar cidade_final
            while atual != cidade_final:
                prox = escolher_proxima_cidade(
                    atual,
                    visitadas,
                    mapaGrafo,
                    feromonioNaAresta,
                    distanciaNaAresta,
                )

                if prox is None:  # caso fique sem saída
                    break

                rota.append(prox)
                visitadas.append(prox)
                atual = prox

            # ignora rotas que não chegaram ao destino
            if rota[-1] != cidade_final:
                continue

            # ===== finalizacao da solucao =====

            # calcula a distância total percorrida pela formiga
            dist_total = calcular_distancia(rota, mapaGrafo)
            todas_rotas.append(rota)
            todas_distancias.append(dist_total)

            # atualiza o melhor resultado global
            if dist_total < melhor_distancia:
                melhor_distancia = dist_total
                melhor_rota = rota

        # ===== atualizacao do feromonio =====

        # evaporação: remove uma fração do feromônio (taxaEvaporacaoFeromonio)
        for k in feromonioNaAresta.keys():
            feromonioNaAresta[k] *= 1 - taxaEvaporacaoFeromonio

        # reforço: cada formiga deposita feromônio proporcional à qualidade da rota
        for rota, L in zip(todas_rotas, todas_distancias):
            for i in range(len(rota) - 1):
                a, b = rota[i], rota[i + 1]
                feromonioNaAresta[(a, b)] += quantidadePadraoFeromonio / L

        # comparação com a rota passada para incrementar ou resetar contador_sem_melhora
        if rota_passada == melhor_rota:
            contador_sem_melhora += 1
            print(f"\tsem melhora ({contador_sem_melhora})")
        else:
            contador_sem_melhora = 0
        rota_passada = melhor_rota

        print(f"Iteração {it}: melhor distância = {melhor_distancia:.2f}")

    # ===== retorno final =====
    return melhor_rota, melhor_distancia


from typing import Dict, List

import matplotlib.pyplot as plt
import networkx as nx


def plotar_rota(
    grafo: Dict[str, Dict[str, int]],
    melhor_rota: List[str],
    titulo: str = "Caixeiro Viajante Cearense - Algoritmo Colônia de Formigas",
) -> None:
    """Plota o grafo da Romênia com o caminho destacado na posicão geografica aproximada."""

    G = nx.Graph()

    # Adiciona as arestas com pesos
    for cidade, vizinhos in grafo.items():
        for v, d in vizinhos.items():
            G.add_edge(cidade, v, weight=d)

    # Coordenadas fixas (aproximadas para refletir o mapa original)
    pos = {
        "Croata": (3.3337501671692, 0.399113138556),
        "Ipu": (4.5778959961973, 0.9527580324735),
        "Guaraciaba do Norte": (4.2855217263757, 1.9542954248411),
        "Varjota": (6.027325887015, 1.7054662590355),
        "Reriutaba": (5.2995005770336, 2.0849307368891),
        "Carnaubal": (3.1284661053796, 1.9605161539863),
        "Sao Benedito": (3.5639171455394, 2.700782922258),
        "Carire": (6.0089377493593, 3.2918933124214),
        "Pacuja": (4.6039971435813, 3.1249696760913),
        "Mucambo": (4.3675219921137, 3.528368463889),
        "Ibiapina": (3.4494419922984, 3.4309963426964),
        "Ubajara": (3.2686080529409, 3.8483054335216),
        "Aprazivel": (5.5, 4.5),
        "Frecheirinha": (3.8667510831236, 4.5020896758143),
        "Tiangua": (2.8095680530332, 4.6133721000343),
        "Aroeiras": (5.0769474465165, 5.1141430090245),
        "Coreau": (4.9169789617002, 5.7053308876934),
        "Arapa": (3.3381595680784, 5.2323805847583),
        "Santa Luzia": (3.7276480528485, 5.9835369482435),
        "Vicosa do Ceara": (2.2183801743643, 5.6010036149871),
        "Santa Terezinha": (2.8373886590882, 7.0128993722789),
        "Campanario": (4.4092529011963, 6.8598860389763),
        "Moraujo": (4.7431001738564, 6.2269672512249),
        "Ibuguacu": (1.1472868412464, 6.9224824026001),
        "Barroquinha": (1.6828335078053, 8.2787369477818),
        "Passagem": (1.9332189623004, 8.9325211900745),
        "Granja": (3.797199567986, 8.3621987659468),
        "Camocim": (3.6650516892248, 9.676722402046),
    }

    plt.figure(figsize=(6, 9))

    # Desenha todas as arestas (cinza)
    nx.draw_networkx_edges(G, pos, edge_color="lightgray", width=1)

    # Destaque da rota ótima (vermelho)
    caminho_edges = [
        (melhor_rota[i], melhor_rota[i + 1]) for i in range(len(melhor_rota) - 1)
    ]
    nx.draw_networkx_edges(G, pos, edgelist=caminho_edges, edge_color="red", width=3)

    # Nós e rótulos
    nx.draw_networkx_nodes(
        G, pos, node_size=600, node_color="skyblue", edgecolors="black"
    )
    nx.draw_networkx_labels(G, pos, font_size=9, font_weight="bold")

    # Pesos das arestas
    labels = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=7)

    plt.title(titulo, fontsize=12)
    plt.axis("off")
    plt.tight_layout()
    plt.show()


import time

print("Executando algoritmo de Colônia de Formigas (ACO)...")
print("====================================================")

inicioTimer = time.perf_counter()
melhor_rota, melhor_distancia = executar_aco()
fimTimer = time.perf_counter()
duracaoTimer = fimTimer - inicioTimer

print("====================================================")
print(f"ACO executado em {duracaoTimer:.4f} segundos")
print("====================================================")

if melhor_rota:
    print("\nMelhor rota encontrada:")
    print(" → ".join(melhor_rota))
    print(f"Distância total: {melhor_distancia:.2f} km")
    plotar_rota(mapaGrafo, melhor_rota)
else:
    print("Nenhuma rota válida encontrada.")
