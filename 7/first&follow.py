################################## FIRST ##################################
#=> Programa -> program id ; Bloco
#First(Programa) -> program

#=> Bloco -> DeclaracaoSeq begin ComandoSeq end
#First(Bloco) -> First(DeclaracaoSeq) -> First(Declaracao) -> var
#{var, begin} #se declaração sec for vazio é o begin

#=> DeclaracaoSeq -> Declaracao DeclaracaoSeq
#=> DeclaracaoSeq -> ε
#First(DeclaracaoSeq) -> First(Declaracao) -> var

# Declaracao -> var VarList : Type ;
#First(Declaracao) -> var


#=> VarList -> id VarList2
#First(VarList) -> id

#=> VarList2 -> , id VarList2
#=> VarList2 -> ε
#First(VarList2) -> id

#=> Type -> boolean
#=> Type -> integer
#=> Type -> real
#=> Type -> string
#First(Type) -> {boolean, integer, real, string}

#=> ComandoSeq -> Comando ComandoSeq
#=> ComandoSeq -> ε
#First(ComandoSeq) -> First(Comando) -> {id, if, while, print, read}


#=> Comando -> id := Expr ;
#=> Comando -> if Expr then ComandoSeq end
#=> Comando -> while Expr do ComandoSeq end
#=> Comando -> print Expr ;
#=> Comando -> read id ;
#First(Comando) -> {id, if, while, print, read}


#=> Expr -> Rel ExprOpc
#First(Expr) -> First(Rel) -> First(Adição) -> First(Termo) -> First(Fator) -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> ExprOpc -> OpIgual Rel ExprOpc
#=> ExprOpc -> ε
#First(ExprOpc) -> First(OpIgual) -> {==, !=}


#=> OpIgual -> ==
#=> OpIgual -> !=
#First(OpIgual) -> {==, !=}


#=> Rel -> Adicao RelOpc
#First(Rel) -> First(Adição) -> First(Termo) -> First(Fator) -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}


#=> RelOpc -> OpRel Adicao RelOpc
#=> RelOpc -> ε
#First(RelOpc) -> First(OpRel) -> {<, <=, >, >=}

#=> OpRel -> <
#=> OpRel -> <=
#=> OpRel -> >
#=> OpRel -> >=
#First(OpRel) -> {<, <=, >, >=}

#=> Adicao -> Termo AdicaoOpc
#First(Adicao) -> First(Termo) -> First(Fator) -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> AdicaoOpc -> OpAdicao Termo AdicaoOpc
#=> AdicaoOpc -> ε
#First(AdicaoOpc) -> First(OpAdicao) -> {+, -}

#=> OpAdicao -> +
#=> OpAdicao -> -
#First(OpAdicao) -> {+, -}

#=> Termo -> Fator TermoOpc
#First(Termo) -> First(Fator) -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> TermoOpc -> OpMult Fator TermoOpc
#=> TermoOpc -> ε
#First(TermoOpc) -> First(OpMult) -> {*, /}

#=> OpMult -> *
#=> OpMult -> /
#First(OpMult) -> {*, /}

#=> Fator -> id
#=> Fator -> integer_const
#=> Fator -> real_const
#=> Fator -> TRUE
#=> Fator -> FALSE
#=> Fator -> STRING_LITERAL
#=> Fator -> ( Expr )
#First(Fator) -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

################################## FOLLOW ##################################
#=> Programa -> program id ; Bloco
#Follow(Programa) -> {}

#=> Bloco -> DeclaracaoSeq begin ComandoSeq end
#Follow(Bloco) -> {Follow(Programa)} -> {}

#=> DeclaracaoSeq -> Declaracao DeclaracaoSeq
#=> DeclaracaoSeq -> ε
#Follow(DeclaracaoSeq) -> {begin}

# Declaracao -> var VarList : Type ;
#Follow(Declaracao) -> {First(DeclaracaoSeq), Follow(DeclaracaoSeq)} -> {var, begin}


#=> VarList -> id VarList2
#Follow(VarList) -> {:}

#=> VarList2 -> , id VarList2
#=> VarList2 -> ε
#Follow(VarList2) -> {Follow(VarList)} -> {:, id}

#=> Type -> boolean
#=> Type -> integer
#=> Type -> real
#=> Type -> string
#Follow(Type) -> {;}

#=> ComandoSeq -> Comando ComandoSeq
#=> ComandoSeq -> ε
#Follow(ComandoSeq) -> {end}


#=> Comando -> id := Expr ;
#=> Comando -> if Expr then ComandoSeq end
#=> Comando -> while Expr do ComandoSeq end
#=> Comando -> print Expr ;
#=> Comando -> read id ;
#Follow(Comando) -> {First(ComandoSeq), Follow(ComandoSeq)} -> {id, if, while, print, read, end}


#=> Expr -> Rel ExprOpc
#Follow(Expr) -> {; then do )}

#=> ExprOpc -> OpIgual Rel ExprOpc
#=> ExprOpc -> ε
#Follow(ExprOpc) -> {Follow(Expr)} -> {; then do )}


#=> OpIgual -> ==
#=> OpIgual -> !=
#Follow(OpIgual) -> {First(Rel)} -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}


#=> Rel -> Adicao RelOpc
#Follow(Rel) -> {First(ExprOpc) Follow(Expr) Follow(ExprOpc)} -> {==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (} 


#=> RelOpc -> OpRel Adicao RelOpc
#=> RelOpc -> ε
#Follow(RelOpc) -> {Follow(Rel) First(Adicao)} -> {==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> OpRel -> <
#=> OpRel -> <=
#=> OpRel -> >
#=> OpRel -> >=
#Follow(OpRel) -> {First(Adicao)} -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> Adicao -> Termo AdicaoOpc
#Follow(Adicao) -> {First(RelOpc) Follow(Rel) Follow(RelOpc)} -> {<, <=, >, >= ==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> AdicaoOpc -> OpAdicao Termo AdicaoOpc
#=> AdicaoOpc -> ε
#Follow(AdicaoOpc) -> {Follow(Adicao) First(Termo)} -> {<, <=, >, >= ==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> OpAdicao -> +
#=> OpAdicao -> -
#Follow(OpAdicao) -> {First(Termo)} -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> Termo -> Fator TermoOpc
#Follow(Termo) -> {First(AdicaoOpc) Follow(Adicao) Follow(AdicaoOpc)} -> {+, - <, <=, >, >= ==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> TermoOpc -> OpMult Fator TermoOpc
#=> TermoOpc -> ε
#Follow(TermoOpc) -> {Follow(Termo)} -> {+, - <, <=, >, >= ==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> OpMult -> *
#=> OpMult -> /
#Follow(OpMult) -> {First(Fator)} -> {id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}

#=> Fator -> id
#=> Fator -> integer_const
#=> Fator -> real_const
#=> Fator -> TRUE
#=> Fator -> FALSE
#=> Fator -> STRING_LITERAL
#=> Fator -> ( Expr )
#Follow(Fator) -> {First(TermoOpc) Follow(Termo)} ->  {*, / +, - <, <=, >, >= ==, != ; then do ) id, integer_const, real_const, TRUE, FALSE, STRING_LITERAL, (}