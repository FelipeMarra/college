%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* Os comentários que antecedem os predicados explicam seu funcionamento.
    A) O predicado addToEnd(L1,L2,X) realiza esta operacao
    B) O predicado insertInPosition(L1,L2,Position,X,Counter) realiza esta operacao
    C) O predicado removeFromPosition(L1,L2,Position,Counter) realiza esta operacao
    D) O predicado intersection(L1,L2,L3) realiza esta operacao
    E) O predicado swaping(L1,L2) verifica se os elementos de L1 estao contidos em L2 independente da ordem, utilizando um algoritimo de troca ou "swap" entre os elementos e verificando um por um.
    F) O predicado biggestValue(L,X,0) realiza esta operacao
    G) O predicado sort(L,Result) retorna Result como a lista ja ordenada.
    H) O predicado additionN(N,Result) retorna Result como a soma dos numeros de 0 até N.
    I)
    J) O predicado acomoda([],L) recebe uma lista e retorna em L a lista "Acomodada"
*/
%A)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*Adding an element to the end by passing your list,  an element, and a variable.
The element will be that variable's head, and the list will the Tail'
Ex: addToEnd([a,b,c],[d], L)  ==> L = [a,b,c,d]*/
addToEnd([], L, L).
addToEnd(L, [], L).
addToEnd(L, X, [L|X]).

/*Get the first element of the list by passing your list to the 1 parameter and
maintaining the others as variables.
Here we basically do an inverted addToEnd*/
getHeadTail([Head|Tail], Head, Tail).

%B)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*L1 = Your List, L2 = auxiliar variable, Position = Index to insert X,
%X = Element you want to insert, Counter aways have to be 0
Ex: insertInPosition([a,b,c],L2,2,d,0) ==> YOUR LIST IS  [[a|d],b,c]
In the first call when the counter is 0*/

%While the counter doesen't hit the Position value
insertInPosition(L1,L2,Position,X,Counter) :-
    format('Counter = ~w, Position = ~w', [Counter,Position]),nl,
    Counter < Position,%just checking if Counter is realy smaller than the Postion
    CounterAux is Counter+1,%if it is we have to increment the counter
    getHeadTail(L1,Head,Tail),
    addToEnd(L2,Head,L3),%put the current Head of L1 into the end of L2, the result goes to L3
    insertInPosition(Tail,L3,Position,X,CounterAux).%And send L1 Tail's and etc back to
% insertInPosition

%When the Cunter is iqual to the position value
insertInPosition(L1,L2,Position,X,Position) :-
    addToEnd(L2,X,L3),%We add X to the current position
    addToEnd(L3,L1,FinalList),%And then add the remaining elements
    format('YOUR LIST IS  ~w',[FinalList]),nl.

%C)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*Assuming that the postion exists on the list*/
removeFromPosition(L1,L2,Position,Counter) :-
    Counter < Position,%just check if Counter is realy smaller than the Postion
    CounterAux is Counter+1,%if it is we have to increment the counter
    getHeadTail(L1, Head, Tail),
    addToEnd(L2,Head,L3),%put the current Head of L1 into the end of L2, the result goes to L3
    removeFromPosition(Tail,L3,Position,CounterAux).%And send L1 Tail's and etc back to
% removeFromPosition

%When the Cunter is iqual to the position value
removeFromPosition(L1,L2,Position,Position) :-
    getHeadTail(L1, Head, Tail),
    addToEnd(L2,Tail,FinalList),%put the tail into L2 and discard the head
    format('YOUR LIST IS  ~w',[FinalList]),nl.

%D)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*L1 and L2 are lists, L3 = the intersection between L1 and L2 and must*/
intersection([],L2,L3) :-
    format('Intersection ~w',[L3]),!.

intersection(L1,[],L3) :-
    format('Intersection ~w',[L3]),!.

intersection(L1,L2,L3) :-
    isNotEmpty(L2),
    isNotEmpty(L2),
    getHeadTail(L1,H1,T1),%get L1 head
    getHeadTail(L2,H2,T2),%and L2 head
    isInL(H1,H2,T1,L2,L2,L3).%look for L1 head into L2

isInL(X,X,L1,L2,L2B,L3) :- %if their equal
    addToEnd(L3,X,L4),%We put it into the interection list
    format('~w = ~w',[X,X]),nl,
    intersection(L1,L2B,L4).

isInL(X,H,L1,[],L2B,L3) :- %if L2 is empty
    intersection(L1,L2B,L3).%Send back to intersection to verify the rest of the elements

isInL(X,H,L1,L2,L2B,L3) :- %If X != H
    isNotEmpty(L2),
    getHeadTail(L2,H2,T2),
    isInL(X,H2,L1,T2,L2B,L3).%Call the function again to compare with the other L2 elements

isNotEmpty(L) :-
    not(L = []).

%E)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Swaping the element and checking if they exist in 2 diferent lists, the position of them dont matter.
%Check if X exist in the list Z
check(X, [X|Tale], Tale).
check(X, [Head|Tale], [Head|Y]):-
    check(X, Tale, Y).
%Swaping and checking until the list are done, returning True or False
swaping([], []).
swaping([Head|Tale], Z):-
    swaping(Tale, X), check(Head, Z, X).

%F)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%L = Your List, X = a variable that represents the biggest element
%And the last parameter is a flag and have to begin as 0

biggestValue([],X,1) :- %If the list is empty, we just print that X is the biggest element
    format('The bigger is ~w',[X]),nl.

biggestValue(L,X,0) :- %This will exec first
    getHeadTail(L,H,T),
    biggestValue(T,H,1).%we just put the list head into X, and change the fla to 1

biggestValue(L,X,1) :- %now that x have a value
    format('The bigger till now is ~w',[X]),nl,
    isNotEmpty(L),
    getHeadTail(L,H,T),
    not(isXBiggerThenH(X,H,T)),%We see if X isnt bigger than the next value on the list
    biggestValue(T,X,1).%If it isnt we maintain X as the biggest


isXBiggerThenH(X, H, T) :-
    H > X,%But if H is bigger
    biggestValue(T,H,1).%We call the function passing H as the biggest

%G)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sort([L1|L2], Result) :-
    sort(L2, X), insert(L1, X, Result).% "X" is a variable with the sort Tale
sort([], []).

insert(L1, [L2|L3], [L2|L4]) :-
    L1 @> L2, !, insert(L1, L3, L4).% Check if L1 is higher than L2
insert(L1, L3, [L1|L3]).

%H)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
additionN(N,Result) :- addition(N,0,Result).
%It goes from N to 0
addition(0,R,R).
%While N > 0
addition(N,Amount,Result) :-
    N > 0 ,
    Amount_next is Amount + N ,
%Amount is the total, and Amount_next saves the next step
    N_next is N-1 ,
addition(N_next,Amount_next,Result).
%N_next is almost the same as Amount_next, it saves the decreasing of the chosen number.

%I)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%J)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
acomoda([],[]).
acomoda([Head|Tale],L) :-
	acomoda(Head,L1),
	acomoda(Tale,L2),
    join(L1,L2,L).

%When its empy
acomoda(Head,[Head]) :-
        Head \= [],
        Head \= [_|_].

%Joining them all
join([],L,L).
join([Head|Tale],L2,[Head|Tale2]) :-
    join(Head,L2,Tale2).