#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nodoArbol{
    int dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

nodoArbol* inicArbol ();
nodoArbol* crearNodoArbol (int dato);
nodoArbol* agregarArbol (nodoArbol* arbol, int dato);
void preorder (nodoArbol* arbol);
void inorder (nodoArbol* arbol);
void postorder (nodoArbol* arbol);
nodoArbol* buscarDatoArbol (nodoArbol* arbol, int dato);
int cuentaNodosTerminales (nodoArbol* arbol);
int nodoHoja (nodoArbol* arbol);
int cuentaNodos (nodoArbol* arbol);
int ramaMayor (int izquierda, int derecha);
int alturaArbol (nodoArbol* arbol);
nodoArbol* nodoMasDerecha(nodoArbol *arbol);
nodoArbol* nodoMasIzquierda(nodoArbol *arbol);
nodoArbol* borrarNodoArbol(nodoArbol *arbol,int dato);

#endif // ARBOL_H_INCLUDED
