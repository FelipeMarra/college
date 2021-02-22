###########################################################################
# problem: find root of f(x) √x − 5e^−x = 0 using the secant method
###########################################################################

import math

EPSOLON = 0
MAX_ITER = 10
X_ZERO = 1.4
X_ONE = 1.5


def stop_criteria(x, k):
    print("iteration: " + str(k))
    return abs(f(x)) <= EPSOLON or k >= MAX_ITER


def f(x): return (x**0.5) - (5*(math.e**-x))


def f_line_aprox(x, lastX): return (f(x) - f(lastX)) / (x - lastX)


def nextX(x, lastX): return x - f(x) / f_line_aprox(x, lastX)

def custom_print(x):
    return print("current (x,y) = (" + str(x) + "," + str(f(x)) + ")")

def secant_method():
    k = 2
    lastX = X_ZERO
    x = X_ONE

    while not stop_criteria(x, k):
        backX = x
        x = nextX(x, lastX)
        lastX = backX
        k = k+1
        custom_print(x)
    custom_print(x)

secant_method()


