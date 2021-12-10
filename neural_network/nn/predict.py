from nltk import tokenize
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.preprocessing import sequence
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

def test_sentece(sentence, tokenizer):
    model = keras.models.load_model("sentiment_model")
    sequence = tokenizer.texts_to_sequences([sentence])
    padded = pad_sequences(sequence, padding='post', maxlen=280)
    prob = model.predict(padded)
    sentiment = "positive" if prob > 0.5 else "negative"
    
    return prob, sentiment