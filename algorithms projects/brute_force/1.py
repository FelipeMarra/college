##############################################################################
# problema: Existe um conjunto C de R pessoas escolhidas de P tal que qualquer
# par de pessoas de C se conhecem?
##############################################################################

import math
import random

HASHTAG = "########## "


def generate_matrix(n):
    matrix = []
    #generate matrix of 0s
    for row in range(n):
        row = []
        for collum in range(n):
            row.append(0)
        matrix.append(row)
    for i in range(n):
        j = i+1
        while j < n:
            if(random.randint(0,1) == 1):
                matrix[i][j] = 1
                matrix[j][i] = 1
            j = j + 1
        
    return matrix


'''
    @param n: tam do conj (nxn)
    @param r: tam da combinação
    @param x: vator elems do conj
    @param next: inicia com 0, contador de iterações
    @param k: inicia com 0, contador até r
'''


def simple_combination(candidates, n, r, x, next, k):
    # quando chegarmos ao tamanho da combinação
    if k == r:
        solution = []
        for i2 in range(r):
            solution.append(x[i2])
        candidates.append(solution)
    else:
        for i1 in range(next, n):
            x[k] = i1
            simple_combination(candidates, n, r, x, i1+1, k+1)


def knows(i, j, matrix): return matrix[i][j] == 1

def candidate_is_valid(candidate, matrix):
    #print("CANDINDATE IS VALID")
    length = len(candidate)
    for i in range(length-1):
        #print("I FOR DO CANDINDATE IS VALID = " + str(i))
        j = i+1
        #print("J FOR DO CANDINDATE IS VALID = " + str(j))
        while j < length:
            person1 = candidate[i]
            person2 = candidate[j]
            #print(str(person1) + " knows " + str(person2) + " = " + str(knows(person1,person2,matrix)))
            if(not knows(person1,person2,matrix)):
                return False
            j = j + 1
    return True

def get_valid_solutions(candidates, matrix):
    valid_solutions = []
    for candidate in candidates:
        if(candidate_is_valid(candidate,matrix)):
            valid_solutions.append(candidate)
    return valid_solutions

def print_matrix(matrix):
    for array in range(len(matrix)):
        print(matrix[array])
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
        print_matrix(candidates)

        print(HASHTAG + "THE MATRIX")
        matrix = generate_matrix(n)
        print_matrix(matrix)

        print(HASHTAG + "VALID SOLUTIONS")
        valid_solutions = get_valid_solutions(candidates, matrix)
        print_matrix(valid_solutions)

        print()


menu()
