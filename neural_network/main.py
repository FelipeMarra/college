import os
import nltk
from nn.predict import test_sentece
from nn.train import train

tokenizer = None

def main():
    global tokenizer

    nltk.download('stopwords')

    #menu
    option = -2
    while option != -1:
        print("########### menu #############")
        print("0 Test Sentence")
        print("1 Train Again")
        print("-1 Quit")

        option = int(input("Option: "))

        if option == 0:
            #In this version of the code the tokenizer state during training is not saved
            if tokenizer == None:
                print("\n Run the option 1 first \n")
                continue

            sentence = str(input("Your sentence: "))
            prob, sentiment = test_sentece(sentence, tokenizer)
            print("\n PROBABILIDADE = ", prob, "SENTIMENTO = ", sentiment, "\n")
            continue
        
        if option == 1:
            tokenizer = train()
            continue

        if option == -1:
            return

        print("Invalid option")

main()