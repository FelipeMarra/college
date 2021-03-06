def min_caixas():
    itens = [[2,1,1,2,4,3,1,2],[3,1,2,2,2,2,2,1]]
    numero_de_caixas_V = 1
    numero_de_caixas_P = 1
    V_max = 5
    P_max = 5
    peso_temp = 0
    valor_temp = 0
    numero_de_itens = 8
    
    itens_V = 0
    itens_P = 0


    z = 0
    total_gasto = 20

    caixaV = []
    caixasV = []
    
    caixaP = []
    caixasP = []


    while z < numero_de_itens:
        print(itens[1][z])
        print(itens[0][z])
        if itens[1][z] > itens[0][z]:
            if itens_P < 3 and itens[0][z] + peso_temp <= P_max:
                caixaP.append(z)
                itens_P = itens_P + 1
                peso_temp = peso_temp + itens[0][z]

            else:
                caixasP.append(caixaP)
                itens_P = 0
                peso_temp = 0
                numero_de_caixas_P = numero_de_caixas_P + 1
                total_gasto = total_gasto + 10
                caixaP = []
                caixaP.append(z)
        
        else:
            if itens_V < 3 and itens[1][z] + valor_temp <= V_max:
                caixaV.append(z)
                itens_V = itens_V + 1
                valor_temp = valor_temp + itens[1][z]

            else:
                caixasV.append(caixaV)
                itens_V = 0
                valor_temp = 0
                numero_de_caixas_V = numero_de_caixas_V + 1
                total_gasto = total_gasto + 10
                caixaV = []
                caixaV.append(z)

        z = z + 1


    caixasP.append(caixaP)
    caixasV.append(caixaV)


    print("Numero de caixa com valor limitado: ", numero_de_caixas_V)
    print("Numero de caixa com peso limitado: ", numero_de_caixas_P)
    
    print("CAIXAS COM VALOR LIMITADO: ", caixasV)
    
    print("CAIXAS COM PESO LIMITADO: ", caixasP)
    
    print("Valor Gasto:", total_gasto)

min_caixas()