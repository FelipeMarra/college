###############################################################################
# Livro Cálculo Numerico - Neide: http://files.blog-da-engenharia-1-semestre.webnode.com/200000006-29d802ad1e/Livro_Neide.pdf
# pg 109, questão 3.14
###############################################################################
import matplotlib.pyplot as plt
from .newtons_method import NewtonsMethod

# algorithm constants
EPSILON = 10 ** -6
MAX_ITER = 10000

# equasion constants
K_TO_C = 273.15
RZAO = 0.082
A_ZERO = 2.2769
B_ZERO = 0.05587
AZINHO = 0.01855
BZINHO = -0.01587
CZINHO = 12.83 * 10 ** 4

# equasion parameters
def beta(t):
    return (RZAO * t * B_ZERO) - A_ZERO - (RZAO * CZINHO/t**2)


def gamma(t):
    return (-RZAO * t * B_ZERO * BZINHO) + (A_ZERO * AZINHO) - (RZAO*CZINHO*B_ZERO/t**2)


def delta(t):
    return (RZAO * B_ZERO * BZINHO * CZINHO) / t ** 2

# the equasion
def get_equasion(p, t, v, beta, gamma, delta):
    return (RZAO * t * v ** -1) + (beta * v ** -2) + (gamma * v ** -3) + (delta * v ** -4) - p

# its derivative
def get_equasion_prime(p, t, v, beta, gamma, delta):
    return ((RZAO * t) * (-v ** -2)) + (beta * (-2 * v ** -3)) + (gamma * (-3 * v ** -4)) + (delta * (-4 * v ** -5))

# V0
def initial_v(t, p):
    return RZAO*t/p

# z
def get_compressiblility(p, v, t):
    return (p*v) / (RZAO*t)


def main():
    temperatures = [0, 200]
    # convert to kelvin
    temperatures = [t + K_TO_C for t in temperatures]
    pressions = [1, 2, 5, 20, 40, 60, 80, 120, 140, 160, 180, 200]

    # points of compressiblility and pression for each temperature to generate the graphic
    points = {}

    for t in temperatures:
        print("PARA T = " + str(t))
        beta_value = beta(t)
        gamma_value = gamma(t)
        delta_value = delta(t)
        points[t] = {}
        points[t]["p"] = []
        points[t]["z"] = []
        for p in pressions:
            print("PARA PRESSAO = " + str(p))
            newton = NewtonsMethod(EPSILON, MAX_ITER, initial_v(t, p))

            f = lambda v: get_equasion(p, t, v, beta_value, gamma_value, delta_value)

            f_prime = lambda v: get_equasion_prime(p, t, v, beta_value, gamma_value, delta_value)

            volume = newton.calculate(f, f_prime)

            print("O VOLUME: ", str(volume))

            compressiblility = get_compressiblility(p, volume, t)

            points[t]["p"].append(p)
            points[t]["z"].append(compressiblility)

            print("O FATOR DE COMPRESSIBILIDADE " + str(compressiblility))
            print()

    # graphic plot
    for t in temperatures:
        plt.plot(points[t]["p"], points[t]["z"])
    plt.ylabel("z (compressiblility)", loc="top")
    plt.xlabel("P (pression)", loc="right")
    plt.grid()
    plt.show()


main()
