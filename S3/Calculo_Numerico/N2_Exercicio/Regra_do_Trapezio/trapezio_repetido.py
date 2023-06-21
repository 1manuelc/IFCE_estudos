import math

def f(x):
    return (math.e ** (-x)) + math.cos(3 * x) - math.pow(x, 4)

def calcularErro(valor):
    erro = -47.9915748014691 - valor
    percentual = abs((erro * 100) / -47.9915748014691)
    percentual = '~ {:.2f}%'.format(percentual)
    return (erro, percentual)

def imprimirResultado(coordenadas, resultadoFinal, erro):
    iteracoes = []
    xi = []
    fxi = []

    for i in coordenadas:
        iteracoes.append(i[0]) #posição 0, k
        xi.append(i[1])
        fxi.append(i[2])
    
    print('\nTabela de Áreas usando Método do Trapézio Repetido\n')
    print('Iteração\t Xi\t f(Xi)')

    for i in range(0, len(iteracoes)):
        print(iteracoes[i], '\t\t', '{:.2f}'.format(xi[i]), '\t', fxi[i])

    print('\nResultado final:', resultadoFinal)
    print('Erro de', erro[0])
    print('Corresponde a', erro[1], 'do resultado-alvo (-47.9915748014691)')
    
def trapezioRepetido(a, b, n):
    intervaloH = (b - a) / n
    
    coordenadas = []
    
    i = a
    somatorio = 0
    contador = 0

    while(abs(i - b) > 1e-9):
        if(i == a): somatorio += f(i)
        else: somatorio += 2 * f(i)
        
        coordenadas.append((contador, i, somatorio))
        i += intervaloH
        contador += 1
    
    somatorio += f(b)
    coordenadas.append((contador, i, somatorio))

    somatorio *= (intervaloH / 2)
    return (somatorio, coordenadas)

resultado, coordenadas = trapezioRepetido(1, 3, 20)
valorErro = calcularErro(resultado)

imprimirResultado(coordenadas, resultado, valorErro)
