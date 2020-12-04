#include "Arbol.h"

nodoArbol* inicArbol (){
    return NULL;
}

nodoArbol* crearNodoArbol (int dato){
    nodoArbol* aux = (nodoArbol*) malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

nodoArbol* agregarArbol (nodoArbol* arbol, int dato){
    if (arbol == NULL){
        arbol = crearNodoArbol(dato);
    } else{
        if (dato > arbol->dato){
            arbol->der = agregarArbol(arbol->der, dato);
        } else {
            arbol->izq = agregarArbol(arbol->izq, dato);
        }
    }
    return arbol;
}

void preorder (nodoArbol* arbol){
    if(arbol!=NULL){
        printf("%d ", arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder (nodoArbol* arbol){
    if(arbol!=NULL){
        inorder(arbol->izq);
        printf("%d ", arbol->dato);
        inorder(arbol->der);
    }
}

void postorder (nodoArbol* arbol){
    if(arbol!=NULL){
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("%d ", arbol->dato);
    }
}

nodoArbol* buscarDatoArbol (nodoArbol* arbol, int dato){
    nodoArbol* rta = NULL;
    if (arbol){
        if (dato == arbol->dato){
            rta = arbol;
        } else if (dato > arbol->dato){
            rta = buscarDatoArbol(arbol->der, dato);
        } else {
            rta = buscarDatoArbol(arbol->izq, dato);
        }
    }
    return rta;
}

int cuentaNodos (nodoArbol* arbol){
    int cont=0;
    if (arbol){
        cont = 1 + cuentaNodos(arbol->der) + cuentaNodos(arbol->izq);
    }
    return cont;
}

int nodoHoja (nodoArbol* arbol){
    int flag = 0;
    if (!arbol->der && !arbol->izq){
        flag = 1;
    }
    return flag;
}

int cuentaNodosTerminales (nodoArbol* arbol)
{
    int cont = 0;
    if (arbol){
        if (nodoHoja(arbol)){
            cont=1;
        } else {
            cont = cuentaNodosTerminales(arbol->der) + cuentaNodosTerminales(arbol->izq);
        }

    }
    return cont;
}

int ramaMayor (int izquierda, int derecha)
{
    int rta=0;
    if (izquierda>derecha){
        rta = izquierda;
    } else {
        rta = derecha;
    }
    return rta;
}

int alturaArbol (nodoArbol* arbol)
{
    int resp = 0;
    if (arbol){
        if (nodoHoja(arbol)){
            resp = 1;
        } else {
            resp = 1 + ramaMayor(alturaArbol(arbol->izq), alturaArbol(arbol->der));
        }
    }
    return resp;
}

nodoArbol* nodoMasDerecha(nodoArbol *arbol){
   nodoArbol *aux;
   if(arbol->der==NULL){
      aux=arbol;
   }else{
      aux=nodoMasDerecha(arbol->der);
   }
   return aux;
}

nodoArbol* nodoMasIzquierda(nodoArbol *arbol){
   nodoArbol *aux;
   if(arbol->izq==NULL){
      aux=arbol;
   }else{
      aux=nodoMasIzquierda(arbol->izq);
   }
   return aux;
}

nodoArbol* borrarNodoArbol(nodoArbol *arbol,int dato)
{
   if(arbol!=NULL){
      if(dato > arbol->dato){
         arbol->der=borrarNodoArbol(arbol->der,dato);
      }else if(dato < arbol->dato){
         arbol->izq=borrarNodoArbol(arbol->izq,dato);
      }else{
         if(arbol->izq!=NULL){
            arbol->dato=(nodoMasDerecha(arbol->izq)->dato);
            arbol->izq=borrarNodoArbol(arbol->izq,arbol->dato);
         }else if(arbol->der!=NULL){
            arbol->dato=(nodoMasIzquierda(arbol->der)->dato);
            arbol->der=borrarNodoArbol(arbol->der,arbol->dato);
         }else{
            free(arbol);
            arbol=NULL;
         }
      }
   }
   return arbol;
}

