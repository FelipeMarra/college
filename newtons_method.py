class NewtonsMethod:
    def __init__(self, EPSILON, MAX_ITER, X_ZERO):
        self.EPSILON = EPSILON
        self.MAX_ITER = MAX_ITER
        self.X_ZERO = X_ZERO

    def stop_criteria(self, f, x, k):
        #print("iteration: " + str(k))
        return abs(f(x)) <= self.EPSILON or k >= self.MAX_ITER 

    def nextX(self, f, f_prime, x): return x - f(x) / f_prime(x)

    def custom_print(self, f, x):
        return print("current (x,y) = (" + str(x) + "," + str(f(x)) + ")")

    def calculate(self, f, f_prime):
        k = 1
        x = self.X_ZERO
        print("X_ZERO = " + str(x))
        while not self.stop_criteria(f, x, k):
            x = self.nextX(f, f_prime, x)
            k = k+1
        #     self.custom_print(f, x)
        self.custom_print(f,x)
        return x