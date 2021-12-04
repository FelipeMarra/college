from ml.naive_bayes.predict import predict
import numpy as np
import nltk
from nltk.corpus import twitter_samples  
from ml.naive_bayes.db.freqs_table.freqs_table import FreqsTable


def test_dataset():
    corpora_root = '../../corpora/twitter_samples/'

    all_positive_tweets = twitter_samples.strings(corpora_root + 'positive_tweets.json')
    all_negative_tweets = twitter_samples.strings(corpora_root + 'negative_tweets.json')

    #get ys
    pos_size = len(all_positive_tweets)
    neg_size = len(all_negative_tweets)
    ys = np.append(np.ones(pos_size), np.zeros(neg_size))

    ########################## dataset ###################################
    test_pos = all_positive_tweets[4000:]
    test_neg = all_negative_tweets[4000:]

    test_x = test_pos + test_neg

    # avoid assumptions about the length of all_positive_tweets
    test_y = np.append(np.ones(len(test_pos)), np.zeros(len(test_neg)))
    
    
    accuracy = 0  
    
    y_hats = []
    for sentence in test_x:
        probability, sentiment = predict(sentence)
        if probability > 0:
            y_hat_i = 1
        else:
            y_hat_i = 0

        y_hats.append(y_hat_i)

    error = sum(y_hats != test_y) / len(y_hats)
    
    accuracy = 1 - error
    return accuracy
