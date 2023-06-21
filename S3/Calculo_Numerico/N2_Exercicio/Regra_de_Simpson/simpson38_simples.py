import math

def f(x):
    return (math.e ** (-x)) + math.cos(3 * x) - math.pow(x, 4)

def calcularErro(valor):
    erro = -47.9915748014691 - valor
    percentual = abs((erro * 100) / -47.9915748014691)
    percentual = '~ {:.2f}%'.format(percentual)
    return (erro, percentual)

def imprimirResultados(resultadoFinal, erro):
    print('\nMétodo de 3/8 de Simpson Simples\nResultado final:', resultadoFinal)
    print('Erro de', erro[0])
    print('Corresponde a', erro[1], 'do resultado-alvo (-47.9915748014691)')

def simpson38Simples(a, b):
    intervaloH = (b - a) / 3

    i = a
    somatorio = 0

    while(abs(i - b) > 1e-9):
        if(i == a): somatorio += f(i)
        else: somatorio += 3 * f(i)
        i += intervaloH
        
    somatorio += f(b)
        
    somatorio *= (3 * intervaloH) / 8

    return somatorio


resultado = simpson38Simples(1, 3)
erro = calcularErro(resultado)

imprimirResultados(resultado, erro)