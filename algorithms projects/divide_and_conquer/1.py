# O problema da subsequência de soma máxima consiste em, dada uma
# sequência de valores inteiros, encontrar uma subsequência cuja
# soma é máxima.
# Formulação do problema:
# Entrada
# A = (a1, a2, … , aN) um vetor de inteiros
# Saída
# Indices i e j tais que a soma ai + ai+1 + … + aj é máxima

def divisao_e_conquista(a, left, right, soma_max, limite_inferior, limite_superior, candidates):
    if left == right:
        if a[left] > 0:
            soma_max = a[left]

        else:
            soma_max = 0

        return soma_max

    else:
        meio = (left + right) // 2
        soma_max_bordEsq = 0
        soma = 0
        k = meio

        while k >= left:
            soma = soma + a[k]
            if soma > soma_max_bordEsq:
                limite_inferior = k
                soma_max_bordEsq = soma
            k = k - 1

        soma_max_bordDir = 0
        soma = 0
        k = meio + 1
        while k <= right:
            soma = soma + a[k]
            if soma > soma_max_bordDir:
                limite_superior = k
                soma_max_bordDir = soma
            k = k + 1

        soma_max = max(divisao_e_conquista(a, left, meio, soma_max, limite_inferior, limite_superior, candidates),
                    divisao_e_conquista(a, meio + 1, right, soma_max, limite_inferior, limite_superior, candidates))
        soma_max = max(soma_max, soma_max_bordEsq + soma_max_bordDir)

        candidates.append({"soma_max": soma_max,"i": limite_inferior, "j": limite_superior})

        return soma_max

def print_soma_max(candidates):
    best = candidates[0]

    for candidate in candidates:
        if candidate['soma_max'] > best['soma_max']:
            best = candidate

    print("soma máxima =", best['soma_max'],", no subintervalo: [",best['i'],",",best['j'],"]")

def main():
    #a = [1, -2, 7, -11, 9, 5, -10]
    a = [1, -2, 12, -11, 9, 5, -10]
    soma_max = 0
    limite_inferior = 0
    limite_superior = 0
    candidates = []
    divisao_e_conquista(a, 0, 6, soma_max, limite_inferior,limite_superior, candidates)

    print_soma_max(candidates)

main()
