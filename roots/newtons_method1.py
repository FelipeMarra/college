# problem: find root of f (x) = x − x^1/3 − 2 = 0 using the newtons method

EPSOLON = 0
MAX_ITER = 10
X_ZERO = 1.5


def stop_criteria(x, k):
    print("iteration: " + str(k))
    return abs(f(x)) <= EPSOLON or k >= MAX_ITER


def f(x): return x ** 2 - x - 2


def f_line(x): return 2 * x -1


def nextX(x): return x - f(x) / f_line(x)


def newtons_method():
    k = 1
    x = X_ZERO

    while not stop_criteria(x, k):
        x = nextX(x)
        k = k+1
        print("current (x,y) = (" + str(x) + "," + str(f(x)) + ")")


newtons_method()

#ex slide 38
#f(x) == 0 na primeira iteração... número muito pequeno?