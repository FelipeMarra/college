##############################################################################
# problema: Faça um algoritmo força bruta que determina, dado um vetor inteiro de
# n elementos, quais são os dois elementos do vetor cuja a soma é máxima. Para
# esse problema, o vetor não pode ser ordenado. Implemente e teste seu algoritmo
# em alguma linguagem de programação.
##############################################################################
import math


def smartter_way(v, biggest_elements):
    for elem in v:
        if(elem > biggest_elements[0]):
            biggest_elements[0] = elem
    for elem in v:
        if(elem < biggest_elements[0] and elem > biggest_elements[1]):
            biggest_elements[1] = elem


def brute_force(vector):
    tam = len(vector)
    som_max = 0
    i = 0
    for i in range(tam-1):
        for j in range(tam):
            if i == j:
                pass
            elif vector[i] + vector[j] > som_max:
                som_max = 0
                som_max = vector[i] + vector[j]

    return som_max


def main():
    v = []
    # coletar vetor
    print("digite o tamanho do vetor ")
    tam = int(input())
    for i in range(tam):
        print("digite o valor " + str(i))
        value = float(input())
        v.append(value)
    # biggest_elements = [v[0], v[1]]
    # find_biggest_elements(v, biggest_elements)
    #print(biggest_elements)
    print(v)
    sum_max = brute_force(v)
    print(sum_max)

main()
