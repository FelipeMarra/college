class GaussSidel:
    # @param matrix: a list of lists with depth 1, ex: [[],[],[]]
    # @param n: the order of the coeficientes matrix
    def __init__(self, matrix, n, max_iter, epsolon):
        self.MATRIX = matrix
        self.N = n
        self.MAX_ITER = max_iter
        self.EPSOLON = epsolon

    # Test Sassenfeld's criteria
    # @return: True if it was accomplished
    def test_convergence(self):
        last_beta = 1
        beta = []
        for i in range(self.N):
            sum1 = 0
            sum2 = 0
            # first sum
            for j in range(i):
                b_j = (1 if not beta else beta[j])
                sum1 = sum1 + \
                    (abs(self.MATRIX[i][j]) / abs(self.MATRIX[i][i])) * b_j
            # second sum
            for j in range(i+1, self.N):
                sum2 = sum2 + (abs(self.MATRIX[i][j]) / abs(self.MATRIX[i][i]))
            # beta_i
            current_beta = sum1 + sum2
            beta.append(current_beta)
            # criteria test
            if(current_beta > 1):
                # prints
                print("In line ", i, "the Sassenfeld criteria was not accomplished")
                print("Sum 1 was ", sum1, "And sum 2 was ", sum2)
                print("The hole line was:")
                for column in range(self.N):
                    print("[", i, ",", column, "] = ", self.MATRIX[i][column])
                # end test sice the matrix failed
                return False
        print("The matrix converges")
        #print("BETAS:", beta)
        print()
        return True

    def stop_criteria(self, iter: int, last_x: list, x: list):
        if not last_x: return False
        numerator = [abs(a-b) for a, b in zip(x, last_x)]
        denominator = [abs(a) for a in x]
        precision = max(numerator) / max(denominator)
        if iter >= self.MAX_ITER or precision <= self.EPSOLON:
            print("Precision or Max iter achieved: precision=", precision, "iter=",iter)
            return True
        return False

    # @param X: initial solution
    def calculate(self, x):
        # make shure the matrix is valid
        if not self.test_convergence():
            return
        iter = 0
        last_x = []
        while not self.stop_criteria(iter, last_x, x):
            for i in range(self.N):
                sum1 = 0
                sum2 = 0

                b_i = self.MATRIX[i][self.N]

                for j in range(i):
                    sum1 = sum1 + self.MATRIX[i][j] * x[j]

                for j in range(i+1, self.N):
                    sum2 = sum2 + self.MATRIX[i][j] * x[j]

                x[i] = (b_i - sum1 + sum2)/self.MATRIX[i][i]
            last_x = x
        print("SOLUTION: ", x)
        return x


# M = [
#     [5, 1, 1],
#     [3, 4, 1],
#     [3, 3, 6]
# ]
M = [
    [4, 0.24, -0.08, 8],
    [0.09, 3, -0.15, 9],
    [0.04, -0.08, 4, 20],
]
gauzao = GaussSidel(M, 3, 30, 10**-3)
gauzao.calculate([0, 0, 0])