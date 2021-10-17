# a) Construa um autômato finito determinístico (AFD) para reconhecer todos os lexemas da
# linguagem P.
# Os lexemas da linguagem P são os seguintes: 
#0:
    # ; 
    # ,
    # + 
    # - 
    # * 
    # / 
    # ( 
    # ) 
#RESERVED WORDS
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
#DOUBLE 0
    # : 
    # := 
    # == 
    # != 
    # < 
    # <= 
    # > 
    # >= 
# [a-zA-Z]([a-zA-Z0-9_])* 
# [0-9]([0-9])* 
# [0-9]([0-9])*.[0-9]([0-9])* 
# "[a-zA-Z0-9_,;?# ]*"

# Importacoes
import argparse
import string
import re
# definicao dos pares (lexema, token)
# def get_token(token:str):
#     if(re.match('[a-zA-Z]([a-zA-Z0-9_])*', token)):
#         return "ID"
#     if(re.match('[0-9]([0-9])*', token)):
#         return "INT"
#     if(re.match('[0-9]([0-9])*.[0-9]([0-9])*', token)):
#         return "FLOAT"
#     if(re.match('"[a-zA-Z0-9_,;?# ]*"', token)):
#         return "STRING"
#     return -1
# print(get_token("aba123"))

def state0(lexema:str):
    if(lexema == "("):
        return "LBRACKET"
    elif(lexema == ")"):
        return "RBRACKET"

    elif(lexema == ";"):
        return "PCOMMA"
    elif(lexema == ","):
        return "COMMA"
    elif(lexema == "+"):
        return "PLUS"
    elif(lexema == "-"):
        return "MINUS"
    elif(lexema == "*"):
        return "MULT"
    elif(lexema == "/"):
        return "DIV"
    return None

# outras inicializacoes
ap = argparse.ArgumentParser()
ap.add_argument("-f", "--file", required=True, help="name of the user")
args = vars(ap.parse_args())
basics_vector = [";",",","+","-","*","/","(",")",'\n','\t',' ']

# python3 prog -f nome.txt
fin = open(args["file"], 'r')  # Abertura do arquivo
state = 0  # Estado inicial do AFD
lexeme = []  # Variavel que guarda o lexema atualmente reconhecido
tokens = []  # Vetor de tokens (nome do token, lexema, linha)
line_number = 1  # Inicializa o número da linha
for line in fin:  # Lê linha por linha do arquivo de entrada
    ibuf = line.rstrip('\n')
    i = 0
    print("LINE",line_number,":",line)
    while i < len(ibuf):  # Para cada caractere da linha, executa as regras do AFD
        char = ibuf[i]
        print("CHAR:",char,"STATE:",state)
        
        if state == 0:
            if state0(char):
                tokens.append((state0(char), char, line_number))
            
            elif char in string.digits:
                lexeme.append(char)
                state = 2
            elif char in string.ascii_letters:
                lexeme.append(char)
                state = 1
            elif char in '<':
                lexeme.append(char)
                state = 5
        i += 1
    print("TOKENS:",tokens)
    line_number += 1