#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"


int sumaArbol (nodoArbol* arbol);

int main()
{
    int arregloEnteros[8] = {3,7,2, 10, 1, 12, 15,6};
    int suma =0;
    nodoArbol* arbol = inicArbol();
    nodoArbol* arbolaBuscar = inicArbol();

    for (int i=0; i<8; i++){
        arbol = agregarArbol(arbol, arregloEnteros[i]);
    }

    suma = sumaArbol(arbol);
    printf("suma arbol: %d", suma);

    printf("\nPREORDER: \n");
    preorder(arbol);
    printf("\nINORDER: \n");
    inorder(arbol);
    printf("\nPOSTORDER: \n");
    postorder(arbol);

    arbolaBuscar = buscarDatoArbol(arbol, 9);
    if (arbolaBuscar){
        printf("\n El arbol buscado existe y es: %d", 12);
    } else {
        printf("\nNo existe el arbol");
    }

    printf("\nLa cantidad de nodos terminales es de %d\n", cuentaNodosTerminales(arbol));

    printf("\nLa cantidad de nodos es de %d\n", cuentaNodos(arbol));

    printf("\nLa cantidad de niveles de este arbol es de: %d\n", alturaArbol(arbol));

    printf("\nSe borro el dato 10\n");
    arbol = borrarNodoArbol(arbol, 10);
    preorder(arbol);

    return 0;
}



int sumaArbol (nodoArbol* arbol){
    int suma=0;
    if (arbol){
        suma = arbol->dato + sumaArbol(arbol->der) + sumaArbol(arbol->izq);
    }
    return suma;
}
