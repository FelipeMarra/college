#TODO codigo 2 e 3 não funcionam
#TODO erro sintático

from re import T
from lexic import start, run

def Define_Token(token):
    if token == "real":
        return "REAL_CONST"
    
    if token == "integer":
        return "INTEGER_CONST"
    
    if token == "string":
        return "STRING_LITERAL"
   
    if token == "boolean":
        return "TRUE"
    
    if token == "true":
        return "TRUE"

    if token == "false":
        return "FALSE"

def log_table():
    global symble_table
    f = open("log.txt", "a")
    f.write("TABELA DE SIMBOLOS: \n")
    for k,v in symble_table.items():
        f.write("Chave " + str(k) + " | ")
        f.write("Valor: " + str(v))
        f.write("\n")
    f.write("\n")
    f.close()

def log_erro_semantico(erro):
    global exp_list
    f = open("log.txt", "a")
    err = "ERR SEMANTICO: " + erro + "\n \n"
    print("################################" + err)
    print("LIST: " + str(exp_list))
    f.write(err)

fin = start()

tokens_vec = run(fin)
print("TOKENS:", tokens_vec,"\n")

exp_flag = False
exp_list = []
var_flag = False
var_count = 0
symble_table = {}

def insert_on_table(token, name):
    global var_flag, var_count, symble_table
    #print("tonken", token,"flag",var_flag,"count",var_count)
    if(token == "var"):
        var_flag = True
        print(symble_table)
        return

    if(var_flag):
        #print("IF VarFlag")
        if(token == "ID"):
            symble_table[name] = "null"
            var_count += 1
            print(symble_table)
            return
        if(token =="TWO_POINTS"):
            var_flag = False
            print(symble_table)
            return

    if(var_flag == False and var_count > 0):
        #print("Varflag false and var_count > 0")
        for k,v in symble_table.items():
            if(v == "null"):
                symble_table[k] = Define_Token(token)
                var_count -= 1
    print(symble_table)

def verify_redeclaration(token):
    global symble_table, var_flag
    if var_flag == True and symble_table.get(token) != None:
        return True
    return False

def verify_declaration(token):
    global symble_table
    if symble_table.get(token) == None:
        err = "Variavel " + str(tokens_vec[0][0]) + " nao declarada na linha " + str(tokens_vec[0][2])
        log_erro_semantico(err)
        exit()

def match(token):
    global tokens_vec
    if len(tokens_vec) == 0:
        print("match: tokens_vec is empty")
        log_table()
        return
    if(token == "ID"):
        if verify_redeclaration(tokens_vec[0][0]):
            err = "Variavel " + str(tokens_vec[0][0]) + " redeclarada na linha " + str(tokens_vec[0][2])
            log_erro_semantico(err)
            exit()
    if(token == tokens_vec[0][1]):
        print("match: token",token,"is a match with",tokens_vec[0][1], "\n")
        insert_on_table(tokens_vec[0][1], tokens_vec[0][0])
        tokens_vec.pop(0)
    else:
        print("match: token", token,"is NOT a match with",tokens_vec[0][1], "\n")

# Programa -> program ID ; Bloco
def Programa():
    if(tokens_vec[0][1] == "program"):
        match("program")
        match("ID")
        match("PCOMMA")
        Bloco()
    print("program: end of program, tokens_vec:", tokens_vec, "\n")
    log_table()

# Bloco -> DeclaracaoSeq begin ComandoSeq end
def Bloco():
    if(tokens_vec[0][1] == "var"):
        DeclaracaoSeq()
        match("begin")
        ComandoSeq()
        match("end")

# DeclaracaoSeq -> Declaracao DeclaracaoSeq
# DeclaracaoSeq -> ε
def DeclaracaoSeq():
    if(tokens_vec[0][1] == "var"):
        Declaracao()
        DeclaracaoSeq()

# Declaracao -> var VarList : Type ;
def Declaracao():
    if(tokens_vec[0][1] == "var"):
        match("var")
        VarList()
        match("TWO_POINTS")
        Type()
        match("PCOMMA")

# VarList -> ID VarList2
def VarList():
    if(tokens_vec[0][1] == "ID"):
        match("ID")
        VarList2()


# VarList2 -> , ID VarList2
# VarList2 -> ε
def VarList2():
    if(tokens_vec[0][1] == "COMMA"):
        match("COMMA")
        match("ID")
        VarList2()

# Type -> boolean
# Type -> integer
# Type -> real
# Type -> string
def Type():
    if(tokens_vec[0][1] in ["boolean", "integer", "real", "string"]):
        match(tokens_vec[0][1])

# ComandoSeq -> Comando ComandoSeq
# ComandoSeq -> ε
def ComandoSeq():
    if(tokens_vec[0][1] in ["ID", "if", "while", "print", "read"]):
        Comando()
        ComandoSeq()

# Comando -> ID := Expr ; 
# Comando -> if Expr then ComandoSeq end
# Comando -> while Expr do ComandoSeq end
# Comando -> print Expr ;
# Comando -> read ID ;
def Comando():
    if(tokens_vec[0][1] == "ID"):
        verify_declaration(tokens_vec[0][0])
        match("ID")
        match("ATR")
        Expr()
        match("PCOMMA")
    if(tokens_vec[0][1] == "if"):
        match("if")
        Expr()
        match("then")
        ComandoSeq()
        match("end")
    if(tokens_vec[0][1] == "while"):
        match("while")
        Expr()
        match("do")
        ComandoSeq()
        match("end")
    if(tokens_vec[0][1] == "print"):
        match("print")
        Expr()
        match("PCOMMA")
    if(tokens_vec[0][1] == "read"):
        match("read")
        if(tokens_vec[0][1] == "ID"):
            verify_declaration(tokens_vec[0][0])
        match("ID")
        match("PCOMMA")

# Expr -> Rel ExprOpc
def Expr():
    global exp_flag, exp_list
    if(tokens_vec[0][1] in ["ID", "INTEGER_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
        exp_flag = True
        Rel()
        ExprOpc()
        if ["TRUE", "FALSE"] in exp_list and ("REAL_CONST" in exp_list or "STRING_LITERAL" in exp_list):
            err = "Incompatible types boolean and real or string | Variavel " + str(tokens_vec[0][0]) + " na linha " + str(tokens_vec[0][2])
            log_erro_semantico(err)
            exp_flag = False
            exp_list.clear()
            return
        
        if "STRING_LITERAL" in exp_list and ("REAL_CONST" in exp_list or "INTEGER_CONST" in exp_list):
            err = "Incompatible types string and boolean, integer or real | Variavel " + str(tokens_vec[0][0]) + " na linha " + str(tokens_vec[0][2])
            log_erro_semantico(err)
            exp_flag = False
            exp_list.clear()
            return
        exp_flag = False
        exp_list.clear()


# ExprOpc -> OpIgual Rel ExprOpc
# ExprOpc -> ε
def ExprOpc():
    if(tokens_vec[0][1] in ["CMPR", "DIFF"]):
        OpIgual()
        Rel()
        ExprOpc()

# OpIgual -> ==
# OpIgual -> !=
def OpIgual():
    if(tokens_vec[0][1] in ["CMPR", "DIFF"]):
        match(tokens_vec[0][1])

# Rel -> Adicao RelOpc
def Rel():
    if(tokens_vec[0][1] in ["ID", "INTEGER_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
        Adicao()
        RelOpc()

# RelOpc -> OpRel Adicao RelOpc
# RelOpc -> ε
def RelOpc():
    if(tokens_vec[0][1] in ["LT", "LE", "GT", "GE"]):
        OpRel()
        Adicao()
        RelOpc()

# OpRel -> <
# OpRel -> <=
# OpRel -> >
# OpRel -> >=
def OpRel():
    if(tokens_vec[0][1] in ["LT", "LE", "GT", "GE"]):
        match(tokens_vec[0][1])

# Adicao -> Termo AdicaoOpc
def Adicao():
    if(tokens_vec[0][1] in ["ID", "INTEGER_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
        Termo()
        AdicaoOpc()

# AdicaoOpc -> OpAdicao Termo AdicaoOpc
# AdicaoOpc -> ε
def AdicaoOpc():
    if(tokens_vec[0][1] in ["PLUS", "MINUS"]):
        OpAdicao()
        Termo()
        AdicaoOpc()

# OpAdicao -> +
# OpAdicao -> -
def OpAdicao():
    if(tokens_vec[0][1] in ["PLUS", "MINUS"]):
        match(tokens_vec[0][1])

# Termo -> Fator TermoOpc
def Termo():
    if(tokens_vec[0][1] in ["ID", "INTEGER_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
        Fator()
        TermoOpc()

# TermoOpc -> OpMult Fator TermoOpc
# TermoOpc -> ε
def TermoOpc():
    if(tokens_vec[0][1] in ["MULT", "DIV"]):
        OpMult()
        Fator()
        TermoOpc()

# OpMult -> *
# OpMult -> /
def OpMult():
    if(tokens_vec[0][1] in ["MULT", "DIV"]):
        match(tokens_vec[0][1])

# Fator -> ID 
# Fator -> INTEGER_CONST
# Fator -> REAL_CONST
# Fator -> TRUE
# Fator -> FALSE
# Fator -> STRING_LITERAL
# Fator -> ( Expr )
def Fator():
    global exp_flag, exp_list, symble_table
    if(tokens_vec[0][1] in ["ID", "INTEGER_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL"]):
        if(tokens_vec[0][1] == "ID"):
            verify_declaration(tokens_vec[0][0])
        if exp_flag:
            if tokens_vec[0][1] == "ID":
                exp_list.append(symble_table[tokens_vec[0][0]])
                #print("###############EXP LIST APEEND", exp_list)
            else:
                exp_list.append(tokens_vec[0][1])
                #print("###############EXP LIST APEEND", exp_list)
        match(tokens_vec[0][1])
    if(tokens_vec[0][1] == "LBRACKET"):
        match("LBRACKET")
        Expr()
        match("RBRACKET")

Programa()