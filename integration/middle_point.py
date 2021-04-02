
'''
Se pegarmos x1=-1 e x2=1 então xi=x1+x2/2 e portanto xi=0 cujo y correspondente é y=0
Seguindo para o que seria a próxima iteração, se x1=1 e x2=3 então xi=x1+x2/2, cujo y é 2
Seguindo dessa forma teremos no final calculado a área que queremos + a área de um retangulo a mais
por usarmos os pontos x=-1 e x=21, porém não precisamos nos preocupar pois o y correspondente é 0,
então a área será 0.
Assim sendo termos 11 intervalos de tamalho 2, ou seja, será 2*y_pto_médio onze vezes
'''
x0 = 0
x1 = 2
h = (x1 - x0)/2
y_vet = [0,2,3,5,4,3,5,4,3,5,0]

def calculate():
    sum_t = 0
    for i in range(len(y_vet)):
        sum_t = sum_t + 2*y_vet[i]
    return h * sum_t

print("RESULTADO:",calculate())


