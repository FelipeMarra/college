token = ""

def match():
    pass

# Programa -> program id ; Bloco
def Programa():
    if(token == "program"):
        match("id")
        match(";")
        Bloco()

# Bloco -> DeclaracaoSeq begin ComandoSeq end
def Bloco():
    if(token == "var"):
        DeclaracaoSeq()
        match("begin")
        ComandoSeq()
        match("end")

# DeclaracaoSeq -> Declaracao DeclaracaoSeq
# DeclaracaoSeq -> ε
def DeclaracaoSeq():
    if(token == "var"):
        Declaracao()
        DeclaracaoSeq()

# Declaracao -> var VarList : Type ;
def Declaracao():
    if(token == "var"):
        match("var")
        VarList()
        match(":")
        Type()
        match(";")

# VarList -> id VarList2
def VarList():
    if(token == "id"):
        match("id")
        VarList2()


# VarList2 -> , id VarList2
# VarList2 -> ε
def VarList2():
    if(token == "id"):
        match("id")
        VarList2()

# Type -> boolean
# Type -> integer
# Type -> real
# Type -> string
def Type():
    if(token in ["boolean", "integer", "real", "string"]):
        match(token)

# ComandoSeq -> Comando ComandoSeq
# ComandoSeq -> ε
def ComandoSeq():
    if(token in ["id", "if", "while", "print", "read"]):
        Comando()
        ComandoSeq()

# Comando -> id := Expr ;
# Comando -> if Expr then ComandoSeq end
# Comando -> while Expr do ComandoSeq end
# Comando -> print Expr ;
# Comando -> read id ;
def Comando():
    if(token == "id"):
        match("id")
        match(":=")
        Expr()
        match(";")
    if(token == "if"):
        match("if")
        Expr()
        match("then")
        ComandoSeq()
        match("end")
    if(token == "while"):
        match("while")
        Expr()
        match("do")
        ComandoSeq()
        match("end")
    if(token == "print"):
        match("print")
        Expr()
        match(";")
    if(token == "read"):
        match("read")
        match("id")
        match(";")

# Expr -> Rel ExprOpc
def Expr():
    if(token in ["id", "integer_const", "real_const", "TRUE", "FALSE", "STRING_LITERAL", "("]):
        Rel()
        ExprOpc()

# ExprOpc -> OpIgual Rel ExprOpc
# ExprOpc -> ε
def ExprOpc():
    if(token in ["==", "!="]):
        OpIgual()
        Rel()
        ExprOpc()

# OpIgual -> ==
# OpIgual -> !=
def OpIgual():
    if(token in ["==", "!="]):
        match(token)

# Rel -> Adicao RelOpc
def Rel():
    if(token in ["id", "integer_const", "real_const", "TRUE", "FALSE", "STRING_LITERAL", "("]):
        Adicao()
        RelOpc()

# RelOpc -> OpRel Adicao RelOpc
# RelOpc -> ε
def RelOpc():
    if(token in ["<", "<=", ">", ">="]):
        OpRel()
        Adicao()
        RelOpc()

# OpRel -> <
# OpRel -> <=
# OpRel -> >
# OpRel -> >=
def OpRel():
    if(token in ["<", "<=", ">", ">="]):
        match(token)

# Adicao -> Termo AdicaoOpc
def Adicao():
    if(token in ["id", "integer_const", "real_const", "TRUE", "FALSE", "STRING_LITERAL", "("]):
        Termo()
        AdicaoOpc()

# AdicaoOpc -> OpAdicao Termo AdicaoOpc
# AdicaoOpc -> ε
def AdicaoOpc():
    if(token == ["+", "-"]):
        OpAdicao()
        Termo()
        OpAdicao()

# OpAdicao -> +
# OpAdicao -> -
def OpAdicao():
    if(token == ["+", "-"]):
        match(token)

# Termo -> Fator TermoOpc
def Termo():
    if(token in ["id", "integer_const", "real_const", "TRUE", "FALSE", "STRING_LITERAL", "("]):
        Fator()
        TermoOpc()

# TermoOpc -> OpMult Fator TermoOpc
# TermoOpc -> ε
def TermoOpc():
    if(token in ["*", "/"]):
        OpMult()
        Fator()
        TermoOpc()

# OpMult -> *
# OpMult -> /
def OpMult():
    if(token in ["*", "/"]):
        match("token")

# Fator -> id
# Fator -> integer_const
# Fator -> real_const
# Fator -> TRUE
# Fator -> FALSE
# Fator -> STRING_LITERAL
# Fator -> ( Expr )
def Fator():
    if(token in ["id", "integer_const", "real_const", "TRUE", "FALSE", "STRING_LITERAL", "("]):
        match(token)