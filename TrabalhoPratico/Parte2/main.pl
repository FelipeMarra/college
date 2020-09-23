profissional(tecnico, rogerio). %fato
profissional(tecnico, ivone). %fato

profissional(engenheiro, tomas).%fato o cargo do profissional seguido de seu nome
profissional(engenheiro, ana).%fato
profissional(engenheiro, oscar).%fato
profissional(engenheiro, isabel).%fato
profissional(engenheiro, daniel).%fato

profissional(supervisorchefe, sonia).%fato
profissional(supervisor, luis).%fato
profissional(secretariaexecutiva, laura).%fato
profissional(diretor, santiago).%fato
profissional(analista, jamais).%fato

manda(engenheiro, tecnico).%fato engenheiros mandam nos tecnicos e assim por diante.
manda(supervisor, engenheiro).%fato
manda(supervisor, analista).%fato
manda(supervisorchefe, supervisor).%fato
manda(diretor, supervisorchefe).%fato
manda(diretor, secretariaexecutiva).%fato

chefiado(X,Z) :-
    manda(Y,X),profissional(Y, Z).%regra: Z chefia X

chefDoChef(W,Z) :-
    chefiado(W,X),profissional(Y,X),chefiado(Y,Z).  %regra: Z é o chefe do chefe de W
    
infoDoChef(W) :- %W chefe de quem
    profissional(X,W),chefiado(X,Y),profissional(Z,Y), %funcao que retorna por escrito o nome e o cargo do chefe de W
    format('nome: ~w', [Y]), nl,
    format('profissao: ~w', [Z]).

pessoasChefiadasPor(W) :-                  %funcao que retorna o nome e o cargo de alguem que é chefiado por W
    manda(W, X), profissional(X,Y),
    format('nome: ~w', [Y]), nl,
    format('profissao: ~w', [X]).

/*
A)  consulta: chefiado(tecnico,X). onde X representa os Chefes dos tecnicos.
    consulta: chefDoChef(tecnico,Z). onde Z representa os chefes dos chefes dos tecnicos.

B)  consulta: infoDoChef(ivone). imprime o nome e a profissao do chefe de Ivone.

C) consulta: pessoasChefiadasPor(supervisorchefe); pessoasChefiadasPor(supervisor.).
imprime o nome e a profissao das pessoas chefiadas pelo supervisor chefe ou pelo supervisor.

D) consulta: profissional(C,_), not(manda(diretor,C)). Onde o X representa os possiveis cargos de carolina.
*/