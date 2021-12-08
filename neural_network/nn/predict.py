from nltk import tokenize
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.preprocessing import sequence
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

#TODO: dar um jeito no tokenizer
def test_sentece(sentence, tokenizer):
    
    model = keras.models.load_model("sentiment_model")
    sequence = tokenizer.texts_to_sequences([sentence])
    padded = pad_sequences(sequence, padding='post', maxlen=280)
    print(model.predict(padded))
    #TODO: fazer o retorno certo