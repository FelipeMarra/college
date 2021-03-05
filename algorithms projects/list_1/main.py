class item:
    def __init__(self, valor, peso, item_id):
        self.valor = valor
        self.peso = peso
        self.item_id = item_id

    def show(self):
        print("id: ", self.item_id, "valor: ", self.valor, "peso: ", self.peso)


class box:
    def __init__(self, itens: list, type: item):
        self.itens = itens.copy()
        self.type = type

    def show(self):
        print("BOX TYPE: ", self.type)
        for item in self.itens:
            item.show()


P_MAX = 5
V_MAX = 5

itens = [item(2, 3, 1), item(1, 1, 2), item(1, 2, 3), item(2, 2, 4),
        item(4, 2, 5), item(3, 2, 6), item(1, 2, 7), item(2, 1, 8)]


def print_solution(solution):
    for caixa in solution:
        caixa.show()
        print()


# Vetores solução
caixasValorLimitado = []
caixasPesoLimitado = []


def remove_itens(item, list1, list2):
    itens.remove(item)
    list1.remove(item)
    list2.remove(item)


def algoritmo():
    # Ordenar por peso e valor
    ordPeso = sorted(itens, key=lambda x: x.peso)
    ordValor = sorted(itens, key=lambda x: x.valor)

    # Enquanto ouverem itens a serem embalados
    while itens:
        valorCount = 0
        pesoCount = 0
        valorSelected = []
        pesoSelected = []
        itensForamAdicionados = True
        i = 0

        # Enquanto itens foram adicionados as caixas candidatas
        while itensForamAdicionados and i < len(itens):
            adicionadoEmValor = False
            adicionadoEmPeso = False

            if(valorCount + ordValor[i].valor <= V_MAX):
                valorCount = valorCount + ordValor[i].valor
                valorSelected.append(ordValor[i])
                adicionadoEmValor = True

            if(pesoCount + ordPeso[i].peso <= P_MAX):
                pesoCount = pesoCount + ordPeso[i].peso
                pesoSelected.append(ordPeso[i])
                adicionadoEmPeso = True

            itensForamAdicionados = adicionadoEmValor and adicionadoEmPeso
            i = i + 1

        # Selecionar caixa candidata, adicionar a solução e remover itens usados
        if(len(valorSelected) > len(pesoSelected)):
            caixasValorLimitado.append(box(valorSelected, "valor limitado"))
            for item in valorSelected:
                remove_itens(item, ordValor, ordPeso)
        else:
            caixasPesoLimitado.append(box(pesoSelected, "peso limitado"))
            for item in pesoSelected:
                remove_itens(item, ordValor, ordPeso)


# Prints
print("Para os itens:")
for item in itens:
    item.show()
print()
print("Peso Máximo:", P_MAX, " e ", "Valor Máximo:", V_MAX)
print()

algoritmo()

print("A solução foi")
print_solution(caixasValorLimitado)
print_solution(caixasPesoLimitado)

n_caixas = len(caixasValorLimitado) + len(caixasPesoLimitado)
print("Foram usadas ", n_caixas, " caixas e portanto o custo é  de R$", n_caixas*10)
