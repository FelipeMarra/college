import math
import random

HASHTAG = "########## "

# problema: Existe um conjunto C de R pessoas escolhidas de P tal que qualquer
# par de pessoas de C se conhecem?


def generate_matrix(n):
    matrix = []
    for row in range(n):
        row = []
        for collum in range(n):
            row.append(random.randint(0, 1))
        matrix.append(row)
    return matrix


'''
    @param n: tam do conj (nxn)
    @param r: tam da combinação
    @param x: vator elems do conj
    @param next: inicia com 0, contador de iterações
    @param k: inicia com 0, contador até r
'''


def simple_combination(candidates, n, r, x, next, k):
    # qunado chegarmos ao tamanho da combinação
    if k == r:
        solution = []
        for i2 in range(r):
            solution.append(x[i2] + 1)
        candidates.append(solution)
    else:
        for i1 in range(next, n):
            x[k] = i1
            simple_combination(candidates, n, r, x, i1+1, k+1)


def get_valid_solutions(candidates, matrix):
    print()


def menu():
    n = -1
    r = -1
    while True:
        # menu
        print("entre com 0 e 0 para sair")
        print("entre como  valor de n: ")
        n = int(input())
        print("entre como  valor de r: ")
        r = int(input())
        if(n == 0 and r == 0):
            break
        # call to function
        print(HASHTAG + "COMB " + str(n) + " ELEMEN " + str(r) + " A " + str(r))

        print(HASHTAG + "POSSIBLE SOLUTIONS: ")
        comb = math.comb(n, r)
        print(comb)

        print(HASHTAG + "CANDIDATES")
        x = [None] * r
        next = 0
        k = 0
        candidates = []
        simple_combination(candidates, n, r, x, next, k)
        print(candidates)

        print(HASHTAG + "THE MATRIX")
        matrix = generate_matrix(n)
        print(matrix)

        print(HASHTAG + "VALID SOLUTIONS")
        valid_solutions = get_valid_solutions(candidates, matrix)
        print(valid_solutions)

        print()


menu()
