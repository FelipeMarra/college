from lexic import start, run

fin = start()

tokens_vec = run(fin)
print("TOKENS:", tokens_vec,"\n")

def match(token):
    global tokens_vec
    if len(tokens_vec) == 0:
        print("match: tokens_vec is empty")
        return
    if(token == tokens_vec[0][1]):
        print("match: token",token,"is a match with",tokens_vec[0][1], "\n")
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
        match("ID")
        match("PCOMMA")

# Expr -> Rel ExprOpc
def Expr():
    if(tokens_vec[0][1] in ["ID", "INTEGET_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
        Rel()
        ExprOpc()

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
    if(tokens_vec[0][1] in ["ID", "INTEGET_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
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
    if(tokens_vec[0][1] in ["ID", "INTEGET_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
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
    if(tokens_vec[0][1] in ["ID", "INTEGET_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL", "LBRACKET"]):
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
# Fator -> INTEGET_CONST
# Fator -> REAL_CONST
# Fator -> TRUE
# Fator -> FALSE
# Fator -> STRING_LITERAL
# Fator -> ( Expr )
def Fator():
    if(tokens_vec[0][1] in ["ID", "INTEGET_CONST", "REAL_CONST", "TRUE", "FALSE", "STRING_LITERAL"]):
        match(tokens_vec[0][1])
    if(tokens_vec[0][1] == "LBRACKET"):
        match("LBRACKET")
        Expr()
        match("RBRACKET")

Programa()