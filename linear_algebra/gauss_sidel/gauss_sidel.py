class GaussSidel:
    #@param matrix: a list of lists with depth 1, ex: [[],[],[]]
    #@param n: the order of the square matrix
    def __init__(self, matrix, n):
        self.MATRIX = matrix
        self.N = n
    
    #Test Sassenfeld's criteria
    #@return: True if it was accomplished
    def test_convergence(self):
        last_beta = 1
        beta = []
        for i in range(self.N):
            sum1 = 0
            sum2 = 0
            #first sum
            for j in range(i):
                b_j = (1 if not beta else beta[j])
                sum1 = sum1 + (abs(self.MATRIX[i][j])/ abs(self.MATRIX[i][i])) * b_j
            #second sum
            for j in range(i+1,self.N):
                sum2 = sum2 + (abs(self.MATRIX[i][j]) / abs(self.MATRIX[i][i]))
            #beta_i
            current_beta = sum1 + sum2
            beta.append(current_beta)
            #criteria test
            if(current_beta > 1):
                #prints
                print("In line ", i, "the Sassenfeld criteria was not accomplished")
                print("Sum 1 was ", sum1, "And sum 2 was ", sum2)
                print("The hole line was:")
                for column in range(self.N):
                    print("[",i,",",column,"] = ", self.MATRIX[i][column])
                #end test sice the matrix failed
                return False
        print("The matrix converges")
        print("BETAS:", beta)
        return True

M = [
    [5, 1, 1],
    [3, 4, 1],
    [3, 3, 6]
]
gauzao = GaussSidel(M,3)
gauzao.test_convergence()