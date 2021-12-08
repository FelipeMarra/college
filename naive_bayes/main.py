import os
import nltk
from ml.naive_bayes.predict import predict
from ml.naive_bayes.test import test_dataset

def main():
    nltk.download('stopwords')
    #menu
    option = -2
    while option != -1:
        print("########### menu #############")
        print("0 Test Sentence")
        print("1 Test Acurracy")
        print("2 Train Again")
        print("-1 Quit")

        option = int(input("Option: "))

        if option == 0:
            sentence = str(input("Your sentence: "))
            probability, sentiment = predict(sentence)
            print(probability, sentiment)

            continue
        
        if option == 1:
            print("Acurracy = ", test_dataset())
            continue

        if option == 2:
            #delete old db
            try:
                os.remove("../naive_bayes/ml/naive_bayes/db/freqs_table/db.db")
            except:
                print("db not found")
            #train
            os.system('python3 ../naive_bayes/ml/naive_bayes/train.py')
            continue

        if option == -1:
            return
        
        print("Invalid option")
        

main()