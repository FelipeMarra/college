# a) Construa um autômato finito determinístico (AFD) para reconhecer todos os lexemas da
# linguagem P.
# Os lexemas da linguagem P são os seguintes:
# BASICS [";",",","+","-","*","/","(",")",'\n','\t',' ']:
# ;
# ,
# +
# -
# *
# /
# (
# )

# NOT BASICS:
# <
# <=
# >
# >=
# :
# :=
# ==
# !=

# RESERVED WORDS
# program
# begin
# end
# var
# boolean
# integer
# real
# string
# if
# then
# while
# do
# print
# read
# true
# false

# [a-zA-Z]([a-zA-Z0-9_])*
# [0-9]([0-9])*
# [0-9]([0-9])*.[0-9]([0-9])*
# "[a-zA-Z0-9_,;?# ]*"

# Importacoes
import argparse
import string
import re


# command line
ap = argparse.ArgumentParser()
ap.add_argument("-f", "--file", required=True, help="name of the user")
args = vars(ap.parse_args())

# constants
reserved_words = ["program", "begin", "end", "var", "boolean", "integer", "real",
                "string", "if", "than", "while", "do", "print", "read", "true", "false"]

# Abertura do arquivo
fin = open(args["file"], 'r')

# utils


def to_str(s):
    # initialization of string to ""
    str1 = ""

    # using join function join the list s by
    # separating words by str1
    return(str1.join(s))


# AFD
state = 0  # Estado inicial do AFD
lexeme = []  # Variavel que guarda o lexema atualmente reconhecido
tokens = []  # Vetor de tokens (nome do token, lexema, linha)
line_number = 1  # Inicializa o número da linha

# AFD state functions:


def state0(char: str):
    if(char == "("):
        return "LBRACKET"
    elif(char == ")"):
        return "RBRACKET"
    elif(char == ";"):
        return "PCOMMA"
    elif(char == ","):
        return "COMMA"
    elif(char == "+"):
        return "PLUS"
    elif(char == "-"):
        return "MINUS"
    elif(char == "*"):
        return "MULT"
    elif(char == "/"):
        return "DIV"
    return None


for line in fin:  # Lê linha por linha do arquivo de entrada
    ibuf = line.rstrip('\n')
    i = 0
    print("LINE", line_number, ":", line)

    # Para cada caractere da linha, executa as regras do AFD
    while i < len(ibuf):
        char = ibuf[i]
        print("CHAR:", char, "STATE:", state)

        if state == 0:
            if state0(char):
                tokens.append((char, state0(char), line_number))
            elif char in string.digits:
                lexeme.append(char)
                state = 2
                i += 1
                continue
            elif char in string.ascii_letters:
                lexeme.append(char)
                state = 1
                i += 1
                continue
            elif char in '<':
                lexeme.append(char)
                state = 5
                i += 1
                continue
            elif char in '>':
                lexeme.append(char)
                state = 6
                i += 1
                continue
            elif char in ':':
                lexeme.append(char)
                state = 7
                i += 1
                continue
            elif char in '=':
                lexeme.append(char)
                state = 8
                i += 1
                continue
            elif char in '!':
                lexeme.append(char)
                state = 9
                i += 1
                continue
            elif char in '"':
                
                state = 10
                i += 1
                continue

        if state == 1:
            if re.match(r'[a-zA-Z]([a-zA-Z0-9_])*', char):
                lexeme.append(char)
            else:
                print("CHEGOU NO ELSE")
                if to_str(lexeme) in reserved_words:
                    tokens.append((to_str(lexeme), to_str(lexeme), line_number))
                    lexeme.clear()
                    i -= 1
                    state = 0
                else:
                    tokens.append((to_str(lexeme), 'ID', line_number))
                    lexeme.clear()
                    i -= 1
                    state = 0

        if state == 2:
            if char in string.digits:
                lexeme.append(char)

            elif char == '.':
                lexeme.append(char)
                state = 3
                i += 1
                continue
            else:
                tokens.append((to_str(lexeme), 'INTEGER_CONST', line_number))
                lexeme.clear()
                i -= 1
                state = 0

        if state == 3:
            if char in string.digits:
                lexeme.append(char)
                state = 4
                i += 1
                continue

        if state == 4:
            if char in string.digits:
                lexeme.append(char)
            else:
                tokens.append((to_str(lexeme), 'FLOAT_CONST', line_number))
                lexeme.clear()
                i -= 1
                state = 0

        if state == 5:
            if char == '=':
                lexeme.append(char)
                tokens.append((to_str(lexeme), 'LE', line_number))
                lexeme.clear()
                state = 0
            else:
                tokens.append((to_str(lexeme), 'LT', line_number))
                lexeme.clear()
                i -= 1
                state = 0

        if state == 6:
            if char == '=':
                lexeme.append(char)
                tokens.append((to_str(lexeme), 'GE', line_number))
                lexeme.clear()
                state = 0
            else:
                tokens.append((to_str(lexeme), 'GT', line_number))
                lexeme.clear()
                i -= 1
                state = 0

        if state == 7:
            if char == '=':
                lexeme.append(char)
                tokens.append((to_str(lexeme), 'ATR', line_number))
                lexeme.clear()
                state = 0
            else:
                tokens.append((to_str(lexeme), 'TWO_POINTS', line_number))
                lexeme.clear()
                i -= 1
                state = 0

        if state == 8:
            if char == '=':
                lexeme.append(char)
                tokens.append((to_str(lexeme), 'CMPR', line_number))
                lexeme.clear()
                state = 0
            else:
                i -= 1
                state = 0

        if state == 9:
            if char == '=':
                lexeme.append(char)
                tokens.append((to_str(lexeme), 'DIFF', line_number))
                lexeme.clear()
                state = 0
            else:
                i -= 1
                state = 0

        if state == 10:
            if char == '"':
                tokens.append((to_str(lexeme), 'LITERAL_STRING', line_number))
                lexeme.clear()
                state = 0
            else:
                lexeme.append(char)

        i += 1
    print("TOKENS:", tokens)
    line_number += 1
