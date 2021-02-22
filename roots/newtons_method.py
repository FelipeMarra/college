###########################################################################
# problem: find root of f (x) = x − x^1/3 − 2 = 0 using the newtons method
###########################################################################

EPSOLON = 0
MAX_ITER = 10
X_ZERO = 3


def stop_criteria(x, k):
    print("iteration: " + str(k) + "  " + str(abs(f(x))))
    return abs(f(x)) <= EPSOLON or k >= MAX_ITER


def f(x): return x - x ** (1/3) - 2


def f_line(x): return 1 - (x ** (-2/3))/3


def nextX(x): return x - f(x) / f_line(x)


def custom_print(x):
    return print("current (x,y) = (" + str(x) + "," + str(f(x)) + ")")


def newtons_method():
    k = 1
    x = X_ZERO

    while not stop_criteria(x, k):
        x = nextX(x)
        k = k+1
        custom_print(x)
    custom_print(x)


newtons_method()
