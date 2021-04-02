x0 = 0
x1 = 2
h = (x1 - x0)/2
y_vet = [0,2,3,5,4,3,5,4,3,5,0]
#y_vet = [1, 1.197, 1.374, 1.503, 1.552, 1.468, 1.202] x0=0 x1=0,2 resultado: 1.6484

def calculate():
    length = len(y_vet)
    sum_t = y_vet[0] + y_vet[length-1]
    for i in range(1,length-1):
        c_i = 2 if i % 2 == 0 else 4
        sum_t = sum_t + c_i * y_vet[i]
    return (h/3) * sum_t

print("RESULTADO:",calculate())