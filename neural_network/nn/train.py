import numpy as np
import os
import nltk
from nltk.corpus import twitter_samples
import tensorflow as tf
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

def train():
    corpora_root = os.getcwd() + "/datasets/corpora/twitter_samples/"
    all_positive_tweets = twitter_samples.strings(
        corpora_root + 'positive_tweets.json')
    all_negative_tweets = twitter_samples.strings(
        corpora_root + 'negative_tweets.json')

    tweets = all_negative_tweets + all_negative_tweets

    # get ys
    pos_size = len(all_positive_tweets)
    neg_size = len(all_negative_tweets)
    ys = np.append(np.ones(pos_size), np.zeros(neg_size))

    ########################## train/test datasets ###################################
    test_pos = all_positive_tweets[4000:]
    train_pos = all_positive_tweets[:4000]
    test_neg = all_negative_tweets[4000:]
    train_neg = all_negative_tweets[:4000]

    train_x = train_pos + train_neg
    test_x = test_pos + test_neg

    # avoid assumptions about the length of all_positive_tweets
    train_y = np.append(np.ones(len(train_pos)), np.zeros(len(train_neg)))
    test_y = np.append(np.ones(len(test_pos)), np.zeros(len(test_neg)))

    ########################## tokenize and create dict  ###################################
    max_length = 280
    vocab_size = 6441
    tokenizer = Tokenizer(num_words=vocab_size, oov_token='<00V>')
    tokenizer.fit_on_texts(train_x)
    word_index = tokenizer.word_index

    train_sequences = tokenizer.texts_to_sequences(train_x)
    train_padded = pad_sequences(train_sequences, padding='post', maxlen=max_length,)

    test_sequences = tokenizer.texts_to_sequences(test_x)
    test_padded = pad_sequences(test_sequences, padding='post', maxlen=max_length)

    ##########################  model  ###################################
    model = tf.keras.Sequential([
        tf.keras.layers.Embedding(vocab_size, 16, input_length = max_length),
        tf.keras.layers.GlobalAveragePooling1D(),
        tf.keras.layers.Dense(24, activation='relu'),
        tf.keras.layers.Dense(1, activation='sigmoid')
    ])

    model.compile(loss='binary_crossentropy',
                optimizer='adam', metrics=['accuracy'])

    ########################## train model  ###################################
    num_epochs = 30

    history = model.fit(train_padded, train_y, epochs=num_epochs,
                        validation_data=(test_padded, test_y), verbose=2)

    model.save("sentiment_model")

    return tokenizer