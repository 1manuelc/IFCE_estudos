import numpy as np
import matplotlib.pyplot as plt

def f(x, a, b, c):
    return a*(x**2) + b*x + c

def main():
    matrizG = np.array([[18.1],[6],[3],[4],[19],[46]])

    matrizPhi = np.array([[9,-3,1], [4,-2,1], [1,1,1], [4,2,1], [16,4,1], [49,7,1]])

    matrizPhiT = np.transpose(matrizPhi)
    matrizAtual = np.dot(matrizPhiT, matrizPhi)
    q, r = np.linalg.qr(matrizAtual)
    matrizAtual = np.linalg.inv(r).dot(q.T)
    matrizAtual = np.dot(matrizAtual, matrizPhiT)
    matrizAtual = np.dot(matrizAtual, matrizG)

    a = matrizAtual[0]
    b = matrizAtual[1]
    c = matrizAtual[2]

    print("a =", a,"b =", b,"c =", c)

    x = [-3, -2, 1, 2, 4, 7]
    y = [f(x[0],a,b,c), f(x[1],a,b,c), f(x[2],a,b,c), f(x[3],a,b,c), f(x[4],a,b,c), f(x[5],a,b,c)]
    plot(x,y)
    
def plot(x,y):
    plt.grid()
    plt.plot(x, y)
    plt.show()

main()