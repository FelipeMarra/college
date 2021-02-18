import math
import numpy as np
import pandas as pd


def showSample(plan, df: pd.DataFrame):
    print("\n Sua amostra é:")
    if plan == 1:
        res = df.sample(tamSample)
    elif plan == 2:
        res = systematic(df)
    else:
        res = stratified(df)
    res.describe()
    print(res)
    print()


def systematic(df):
    step = math.trunc(tamPop/tamSample)
    indexes = np.arange(len(df), step=step)
    return df.iloc[indexes]


def stratified(df):
    # geting strata "manually"
    halfPop = math.ceil(tamPop/2)
    aElem = df.iloc[range(halfPop)]
    bElem = df.iloc[range(halfPop, tamPop)]
    # proportional elements sample legth
    aProp = tamSample/tamPop * len(aElem)
    bProp = tamSample/tamPop * len(bElem)
    # get sample
    sampleA = aElem.sample(math.trunc(aProp))
    sampleB = bElem.sample(math.trunc(bProp))

    return sampleA.append(sampleB, sort=True)


while True:
    tamPop = 0
    tamSample = 0
    samplingPlan = ""

    # Sampling plan
    print("Informe o plano de amostragem: \n")
    print("0 - sair \n")
    print("1 - aleatória simples \n")
    print("2 - sistemática \n")
    print("3 - estratificada \n")
    samplingPlan = int(input())

    if samplingPlan == 0:
        break
    elif samplingPlan == 3:
        print("Informe a variável estratificadora")
        stratifyingVariable = int(input())

    # population
    print("Informe o tamanho da população: ")
    tamPop = int(input())

    # sample
    print("Informe o tamanho da amostra: ")
    tamSample = int(input())

    # population DataFrame
    df = pd.DataFrame({'elements': range(tamPop)})

    print("População:")
    print(df)

    # get and show sample
    showSample(samplingPlan, df)
