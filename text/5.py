# Com base na gramática abaixo, faça o que se pede:
# Construa todas as funções para a implementação do método de descida recursiva. Considere
# que já foi definida uma função match(tokenesperado) que compara o token atual da entrada
# com o token esperado passado por parâmetro e avança na entrada em caso de
# correspondência.

token = ""
def match():
    pass

# Funcao → function id ( ) ComandoSeq endfunction
def Funcao():
    if(token == "function"):
        match("function")
        match("id")
        match("(")
        match(")")
        ComandoSeq()
        match("endfunction")

# ComandoSeq → Comando ; ComandoSeq | ԑ
def ComandoSeq():
    if(token == "id"):
        Comando()
        match(";")
        ComandoSeq()

# Comando → id Comando2
def Comando():
    if(token == "id"):
        match("id")
        Comando2()

# Comando2 → ( ) | = Expr
def Comando2():
    if(token == "("):
        match("(")
        match(")")
    elif(token == "="):
        match("=")
        Expr()

# Expr → [ Param_Expr ]
def Expr():
    if(token == "["):
        match("[")
        Param_Expr()
        match("]")

# Param_Expr → integer_const Param_Expr2
def Param_Expr():
    if(token == "integer_const"):
        match("integer_const")
        Param_Expr2()

# Param_Expr2 → : integer_const Param_Expr2 | ԑ
def Param_Expr2():
    if(token == "integer_const"):
        match("integer_const")
        Param_Expr2()

# Terminais = {function,id,(,),endfunction,;,=,[,],integer_const,:}