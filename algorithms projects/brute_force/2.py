##############################################################################
#problema: Faça um algoritmo força bruta que determina, dado um vetor inteiro de 
#n elementos, quais são os dois elementos do vetor cuja a soma é máxima. Para 
#esse problema, o vetor não pode ser ordenado. Implemente e teste seu algoritmo 
# em alguma linguagem de programação.
##############################################################################
import math

def find_biggest_elements(v,biggest_elements):
    for elem in v:
        if(elem > biggest_elements[0]):
            biggest_elements[0] = elem
    for elem in v:
        if(elem < biggest_elements[0] and elem > biggest_elements[1]):
            biggest_elements[1] = elem



def main():
    v = []
    #coletar vetor
    print("digite o tamanho do vetor ")
    tam = int(input())
    for i in range(tam):
        print("digite o valor " + str(i))
        value = float(input())
        v.append(value)
    biggest_elements = [v[0],v[1]]
    find_biggest_elements(v,biggest_elements)
    print(biggest_elements)

main()