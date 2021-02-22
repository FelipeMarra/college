# problem: find root of f(x) = x² − x − 2 = 0 using the fixed point method
# x in range I = [1.5, 2.5]
import math

EPSOLON = 0.1
MAX_ITER = 10
X_ZERO = 1.5


def f(x): return (x ** 2) - x - 2


def phi(x): return 1/2 * math.sqrt(x + 2)


def stop_criteria(x, k):
    print("iteration: " + str(k))
    return abs(f(x)) <= EPSOLON or k >= MAX_ITER


def custom_print(x):
    return print("current (x,y) = (" + str(x) + "," + str(f(x)) + ")")


def fixedPoint():
    k = 1
    x = X_ZERO
    print("X_ZERO = " + str(x))
    while not stop_criteria(x, k):
        x = phi(x)
        k = k + 1
        custom_print(x)
    custom_print(x)


fixedPoint()

# ex slide 21
# como manter x no intervalo I ?
# método não converge... X_ZERO errado ?
