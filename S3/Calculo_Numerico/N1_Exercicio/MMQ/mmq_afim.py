import numpy as np
import matplotlib.pyplot as plt

def f(x, a, b):
    return a*x + b

def main():
    matrizG = np.array([[18.1],[6],[3],[4],[19],[46]])

    matrizPhi = np.array([[-3,1], [-2,1], [1,1], [2,1], [4,1], [7,1]])

    matrizPhiT = np.transpose(matrizPhi)
    matrizAtual = np.dot(matrizPhiT, matrizPhi)
    matrizAtual = np.linalg.inv(matrizAtual)
    matrizAtual = np.dot(matrizAtual, matrizPhiT)
    matrizAtual = np.dot(matrizAtual, matrizG)

    a = matrizAtual[0]
    b = matrizAtual[1]

    print("a =", a,"b =", b)

    x = [-3, -2, 1, 2, 4, 7]
    y = [f(x[0],a,b), f(x[1],a,b), f(x[2],a,b), f(x[3],a,b), f(x[4],a,b), f(x[5],a,b)]
    plot(x,y)
    
def plot(x,y):
    plt.grid()
    plt.plot(x, y)
    plt.show()

main()