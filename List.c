/*******************************************************/
/*Create and print an example linked list.             */
/*Also print it in reverse order.                      */
/*J. Storer 2014.                                      */
/*   UNIX compile with: gcc -ansi -Wall -o List List.c */
/*   Run from a UNIX terminal window by doing: ./List  */
/*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MaxString 100

/*Define a single-linked list vertex to be a pointer to a structure "vbody"*/
/*consisting of two fields, vbody.NEXT (of type pointer to vbody)*/
/*and vbody.DATA of type char.*/
typedef struct vbody {
   struct vbody *NEXT;
   char DATA;
} *TypeVertex;

/*Define a singly-linked list to just be a pointer to its first vertex.*/
typedef TypeVertex TypeList;

/*Function to allocate memory for a new vertex.*/
TypeVertex NEWVERTEX() {
    TypeVertex p = (TypeVertex) malloc(sizeof(struct vbody));
    printf("Size of vbody is %lu, and size of TypeList is %lu \n", sizeof(struct vbody), sizeof(TypeList));
    if (p==NULL) {printf("Malloc for a new vertex failed."); exit(1);}
    return p;
}

/*Define a global variable X to be of type list, initialized to be empty.*/
TypeList X=NULL;

/*FIRST TRY AT AN INSERT FUNCTION*/
/*Function to insert into the list X after vertex v a new vertex with data c.*/
/*Giving the argument v=NULL means insert at the beginning of the list.*/
void INSERT1(char c, TypeVertex v) {
    TypeVertex w = NEWVERTEX();
    w->DATA = c;
    if (v==NULL) {
       w->NEXT = X;
       X = w;
       }
    else {
       w->NEXT = v->NEXT;
       v->NEXT = w;
       }
}

/*SECOND TRY AT AN INSERT FUNCTION*/
/*Function to insert into a list L after vertex v a new vertex with data c.*/
/*Giving the argument v=NULL means insert at the beginning of the list.*/
/*A more general function than INSERT1 because any list could be passed to it.*/
/*However, it is a bit "ugly" to have to call it with an assignment statement.*/
TypeList INSERT2(char c, TypeVertex v, TypeList L) {
    TypeVertex w = NEWVERTEX();
    w->DATA = c;

    if (v==NULL) {
       w->NEXT = L;
       L = w;
       }
    else {
       w->NEXT = v->NEXT;
       v->NEXT = w;
       }
    return L;
}

/*OUR FINAL VERSION OF AN INSERT FUNCTION*/
/*Function to insert into a list L after vertex v a new vertex with data c.*/
/*Giving the argument v=NULL means insert at the beginning of the list.*/
/*Because this function may have to modify L, it is passed a pointer to L*/
/*(i.e., *L is a pointer to a pointer).*/
/*NOTE:
   Unlike the previous second try at this function, we don't have to return anything.
   Instead, although the pointer to L that is passed to this function is a local
   variable here (and changing it will have no effect after we return),
   the thing it points to, the pointer to L, can be changed and that change will
   remain after we return.
   */
void INSERT(char c, TypeVertex v, TypeList *L) {
    TypeVertex w = NEWVERTEX();
    w->DATA = c;
    if (v==NULL) {
       w->NEXT = *L;
       *L = w;
       }
    else {
       w->NEXT = v->NEXT;
       v->NEXT = w;
       }
}

/*Function to print the items of a list, one per line.*/
void PrintList(TypeList L) {
    int i=0;
    TypeVertex v;
    for (v=L; v!=NULL; v = v->NEXT) printf("Vertex %d = \'%c\'\n",++i,v->DATA);
}

/*Function make a copy of a list in reverse order and return it.*/
/*&M is C syntax for a pointer to M.*/
/*By passing &M, the INSERT function will modify M, not a copy of M.*/
TypeList ReverseCopy(TypeList L) {
    TypeList M = NULL;
    TypeVertex v;
    for (v=L; v!=NULL; v = v->NEXT) INSERT(v->DATA,NULL,&M);
    return M;
}

/***** We have finished with global definition, now starts the main. *****/
int main() {
    TypeVertex v;

    /*Let's start by adding a vertex to X "manually", with data 'D".*/
    X = NEWVERTEX();
    (*X).NEXT = NULL;
    (*X).DATA = 'D';

    /*Now lets "manually" place another vertex at the start of X, with data item F.*/
    /*Except this time, lets use the -> notation; for example,*/
    /*X->NEXT is a shortcut for (*X).NEXT, which looks nicer in practice.*/
    v = NEWVERTEX();
    X->NEXT = v;
    v->NEXT = NULL;
    v->DATA = 'F';

    /*Let's now put C at the front of X using the INSERT1 function.*/
    INSERT1('C',NULL);

    /*Let's now put B at the front of X using the INSERT2 function.*/
    X = INSERT2('B',NULL,X);

    /*Let's now put A at the front of X using the INSERT function.*/
    INSERT('A',NULL,&X);

    /*Now find vertex D and put E after it.*/
    v = X;
    while ( (v!=NULL) && ((v->DATA)!='D') ) v = v->NEXT;
    INSERT('E',v,&X);

    /*Now walk through list X and print each vertex - A,B,C,D,E,F.*/
    printf("\nThe list X:\n");
    PrintList(X);

    /*Now make a copy of X in reverse order and print it - F,E,D,C,B,A.*/
    printf("\nThe list X reversed:\n");
    PrintList(ReverseCopy(X));
    printf("\n");

    return 0;
}
