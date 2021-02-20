import math

EPSOLON = 0.1
MAX_ITER = 50

def equasion(x):
    return math.pow(x, 2)-x-2

def criteria(x, k):
    print("iterations: " + str(k))
    return abs(equasion(x)) > EPSOLON and k < MAX_ITER

def fi(x):
    return 1/2*math.sqrt(x + 2)

x0 = 0

def method():
    k = 1
    x = x0
    print("X0 = " + str(x0))
    while criteria(x, k):
        x = fi(x)
        k = k+1
        print("current x = " + str(x))
        print("current y = " + str(equasion(x)))

method()
