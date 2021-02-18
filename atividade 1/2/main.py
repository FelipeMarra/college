import pandas as pd

#frame with the means, meadians and stds of the samples
finalFrame = pd.DataFrame([], columns=["mean", "median", "std"])

#get smaple size
print("Informe o tamanho da amostra")
tam = int(input())

# colect sample
initialSample = []

print("Informe os valores da amostra")
for i in range(tam):
    initialSample.append(int(input()))

initialDataFrame = pd.DataFrame({"elements": initialSample})

# New samples
print("Informe a quantidade de reamostragens")
reSampleTimes = int(input())

for i in range(reSampleTimes):
    print("\n Reamostragem número " + str(i))
    newDataFrame = initialDataFrame.sample(len(initialDataFrame), replace=True)
    #get measures
    mean = newDataFrame["elements"].mean()
    median = newDataFrame["elements"].median()
    std = newDataFrame["elements"].std()
    #adding to final frame
    finalFrame.loc[-1] = [mean, median, std]
    finalFrame.index = finalFrame.index + 1
    finalFrame = finalFrame.sort_index()
    #print final frame
    print(finalFrame)
    print()

#finalFrame means
print("Média das médias das reamostragens: " + str(finalFrame["mean"].mean()))
print("Média das medianas das reamostragens: " + str(finalFrame["median"].mean()))
print("Média dos desvios-padrões das reamostragens: " + str(finalFrame["std"].mean()))