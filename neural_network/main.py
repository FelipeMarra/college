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
            sentence = str(input("Your sentence: "))
            test_sentece(sentence, tokenizer)
            continue

        if option == 1:
            tokenizer = train()
            continue

        if option == -1:
            return

        print("Invalid option")

main()