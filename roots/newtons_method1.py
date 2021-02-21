# problem: find root of f (x) = x² − x − 2 = 0 using the newton's method

EPSOLON = 0
MAX_ITER = 10
X_ZERO = 1.5  # X_ZERO = 1.5 => y = 2; X_ZERO = 0 => y = -1;


def stop_criteria(x, k):
    print("iteration: " + str(k))
    return abs(f(x)) <= EPSOLON or k >= MAX_ITER


def f(x): return x ** 2 - x - 2


def f_line(x): return 2 * x - 1


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
