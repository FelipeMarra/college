# problem: find root of f (x) = x² − x − 2 = 0 using the fixed point strategy
#   I = [1.5, 2.5]
import math

EPSOLON = 0.1
MAX_ITER = 10000
X_ZERO = 1.5


def y(x): return math.pow(x, 2)-x-2


def fi(x): return 1/2*math.sqrt(x + 2)


def stop_criteria(x, k):
    print("iteration: " + str(k))
    return abs(y(x)) <= EPSOLON or k >= MAX_ITER


def fixedPoint():
    k = 1
    x = X_ZERO
    print("X_ZERO = " + str(x))
    while not stop_criteria(x, k):
        x = fi(x)
        k = k+1
        print("current (x,y) = (" + str(x) + "," + str(y(x)) + ")")


fixedPoint()

# como me manter dentro do intervalo I ?
# método não converge... X_ZERO errado ?
