import sys
sys.path.append('../')
from ml.naive_bayes.predict import predict


def test():
    tweet = "mdilson is a very nice guy"
    probability, sentiment = predict(tweet)
    print(probability, sentiment)

test()