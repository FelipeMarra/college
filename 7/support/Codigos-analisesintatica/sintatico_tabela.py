#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug 26 10:28:28 2017

@author: alexandre
"""
class Token(object):
    def __init__(self, type, value):
        self.type = type #ID, FLOAT, MAIN, ... 
        self.value = value #lexema 

    def __str__(self):
        """String representation of the class instance.

        Examples:
            Token(INTEGER_CONST, 3)
            Token(PLUS, '+')
            Token(MUL, '*')
        """
        return 'Token({type}, {value})'.format(
            type=self.type,
            value=repr(self.value)
        )

    def __repr__(self):
        return self.__str__()

"""
 A tabela de símbolos é implementada com um dicionário com os seguintes campos:
     - lexema
     - tipo
     - ponteiro para o valor
     - num da linha
"""

class Stack: #Pilha 
     def __init__(self):
         self.items = []

     def isEmpty(self):
         return self.items == []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()

     def peek(self):
         return self.items[len(self.items)-1]

     def size(self):
         return len(self.items)


EOF = -1
ID = 0
NUM = 1
LBRACKET = 2
RBRACKET = 3
PLUS = 4
MINUS = 5
MULT = 6
DIV = 7

tokenNames = {}
tokenNames[EOF] = 'EOF'
tokenNames[ID] = 'ID'
tokenNames[NUM] = 'NUM'
tokenNames[LBRACKET] = 'LBRACKET'
tokenNames[RBRACKET] = 'RBRACKET'
tokenNames[PLUS] = 'PLUS'
tokenNames[MINUS] = 'MINUS'
tokenNames[MULT] = 'MULT'
tokenNames[DIV] = 'DIV'

#Inicialização e entrada 

stack = Stack()
vetorTokens = [LBRACKET, ID, DIV, NUM, RBRACKET, MULT, NUM, EOF] #Saída do analisador léxico 

#EOF = $
#Tabela M de analise é um dicionário (outra possibilidade: definir a tabela M como uma matriz)
M = {}
M['E,LBRACKET'] =  ['T','E_']
M['E,ID'] = ['T','E_']
M['E,NUM'] = ['T','E_']
M['E,RBRACKET']= [' ']
M['E,EOF'] = [' ']
M['E_,PLUS'] = [PLUS,'T','E_']
M['E_,MINUS']= [MINUS,'T','E_']
M['E_,RBRACKET']= [' ']
M['E_,EOF']= [' ']
M['T,LBRACKET']= ['F','T_']
M['T,ID'] = ['F','T_']
M['T,NUM']= ['F','T_']
M['T_,MULT']= [MULT,'F','T_']
M['T_,DIV']= [DIV,'F','T_']
M['T_,PLUS'] = [' ']
M['T_,MINUS'] = [' ']
M['T_,RBRACKET']= [' ']
M['T_,EOF']= [' ']
M['F,LBRACKET']= [LBRACKET,'E',RBRACKET]
M['F,ID']= [ID]
M['F,NUM']= [NUM]

M['EOF,EOF'] = []
M['ID,ID'] = []
M['NUM,NUM'] = []
M['RBRACKET,RBRACKET'] = []
M['LBRACKET,LBRACKET'] = []
M['PLUS,PLUS'] = []
M['MINUS,MINUS'] = []
M['MULT,MULT'] = []
M['DIV,DIV'] = []
# ' ' (vazio)


simbolo = 'E' #Símbolo inicial no topo da pilha 
stack.push(simbolo) 
i = 0 #Índice do vetor de tokens 
token = vetorTokens[i]
erro = False
exit = False
while ((token != EOF or not stack.isEmpty()) and exit == False):
    print('pilha: '+ str(stack.items))
    print('token name: ' + tokenNames[token])
    print('simbolo: ' + str(simbolo))
    if(isinstance(simbolo,int)):
        str_simbolo = str(tokenNames[simbolo])
        #print('simbolo_str: ' + str(str_simbolo))
        key = '{},{}'.format(str_simbolo,tokenNames[token])
    else:
        key = '{},{}'.format(simbolo,tokenNames[token])
    print(str(key))
    if(key in M): #Se a chave está na tabela M 
        producao = M[key]
        if(producao):
            stack.pop() #Desempilha 
            for x in reversed(producao): #Empilha da direita para esquerda os símbolos 
                stack.push(x)
            simbolo = stack.peek()
            if(isinstance(simbolo,int)): #é um terminal
                print('token: ' + str(token))
                if(simbolo == token): #Correspondência 
                    i = i + 1 #avança 
                    print('match com token: ' + tokenNames[token])
                    if (i < len(vetorTokens)):
                        token = vetorTokens[i]
                        stack.pop() #desempilha
                        if(not stack.isEmpty()):
                            simbolo = stack.peek() #X = ...
                        else: #pilha vazia 
                            erro = True # Pilha vazia e não chegou ao final da entrada
                            exit = True
                    elif(not stack.isEmpty()):
                        erro = True # Chegou ao final da entrada e a pilha não está vazia
                        exit = True
                else:
                    erro = True
                    print('Erro sintático. Token ' + str(tokenNames[token]) + ' não reconhecido na entrada');
                    i = i + 1
                    if (i < len(vetorTokens)):
                        token = vetorTokens[i]
                    else:
                        exit = True
                    if (token == EOF):
                        exit = True
            elif(simbolo == ' '): #Regra da cadeia vazia 
                stack.pop()
                if(not stack.isEmpty()):
                    simbolo = stack.peek()
        else:
            stack.pop()
            if(not stack.isEmpty()):
                simbolo = stack.peek()
                i = i + 1
                if (i < len(vetorTokens)):
                    token = vetorTokens[i]
                else:
                    exit = True
    else:
        erro = True
        print('Erro sintático. Token ' + str(tokenNames[token]) + ' não reconhecido na entrada');
        #continua a análise para verificar outros erros
        i = i + 1
        if (i < len(vetorTokens)):
            token = vetorTokens[i]
        else:
            exit = True
        if (token == EOF):
            exit = True

print('Chegou ao fim da análise.')
if (erro):
    print('Ocorreram um ou mais erros no reconhecimento sintático.')
else:
    print('Entrada aceita');
