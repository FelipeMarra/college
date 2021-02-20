'''
    @param n: tam do conj (nxn)
    @param r: tam da combinação
    @param x: vator elems do conj
    @param next: inicia com 0, contador de iterações
    @param k: inicia com 0, contador até r
'''


def simple_combination(n, r, x, next, k):
    i = 0
    #qunado chegarmos ao tamanho da combinação
    if k == r:
        for i in range(r-1):
            print(x[i]+1 / n)
    else:
        i = next
        for i in range(n-1):
            x[k] = i
            simple_combination(n,r,x,i+1,k+1)
