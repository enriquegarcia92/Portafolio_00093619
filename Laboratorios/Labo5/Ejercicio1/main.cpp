#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

Nodo *T;

Nodo* crearNodo(){
    Nodo* n = (Nodo*) malloc(sizeof(Nodo));
    if(n == NULL){
        cout << "I QUIT";
        exit(0);
    }
    return n;
}

void inicializarArbol(){
    T = NULL;
}

bool estaVacio(Nodo* T){
    if(T == NULL) return true;
    else return false;
}

Nodo* inicializarNodo(int n){
    Nodo* temp = crearNodo();
    temp->dato = n;
    temp->izq = temp->der = NULL;
    return temp;
}

int contarNiveles(Nodo *T){
    if(T!=NULL){
        int izq = contarNiveles(T->izq) + 1;
        int der = contarNiveles(T->der) +1;
        if(izq>der){
            return izq;
        }else{ return der;}
    }
    return -1;
}

int sumaNodos(Nodo *T){
    /*if(T!=NULL){
        return T->dato+sumaNodos(T->izq)+sumaNodos(T->der);
    }else{
    return 0;
    }*/
    if(T!=NULL){
        int raiz = T->dato;
        int izq = sumaNodos(T->izq);
        int der = sumaNodos(T->der);
        return raiz+izq+der;
    }
}

void mostrarArbolPreOrder(Nodo* T){
    if(estaVacio(T)) return;

    cout << T->dato << "   ";
    mostrarArbolPreOrder(T->izq);
    mostrarArbolPreOrder(T->der);
}



int contarNodos(Nodo* T){
    if(estaVacio(T)) return 0;
    /*int cont = 1;
    int contIzq = contarNodos(T->izq);
    int contDer = contarNodos(T->der);
    int total = cont + contIzq + contDer;
    return total;*/
    return 1 + contarNodos(T->izq) + contarNodos(T->der);
}

int contarHojas(Nodo* T){
    if(estaVacio(T)) return 0;
    if(T->izq == NULL && T->der == NULL) return 1;
    /*
    int contIzq = contarHojas(T->izq);
    int contDer = contarHojas(T->der);
    int total = contIzq + contDer;
    return total;*/
    return contarHojas(T->izq) + contarHojas(T->der);
}

int main()
{
  
    inicializarArbol();

    Nodo* n6 = inicializarNodo(1);
    Nodo* n5 = inicializarNodo(2);
    Nodo* n4 = inicializarNodo(3);
    Nodo* n3 = inicializarNodo(4);
    Nodo* n2 = inicializarNodo(5);
    Nodo* n1 = inicializarNodo(6);

    T = n1; n1->izq = n2; n1->der = n3;
    n2->izq = n4; n2->der = n5; n3->izq = n6;

    cout<<"elementos del arbol: ";
            mostrarArbolPreOrder(T);
    cout <<endl;

  
    cout << "El total de nodos es: " << contarNodos(T)<<endl;

    cout << "El total de niveles es: " << contarNiveles(T);
    cout <<endl<< "El total de sumar todos los nodos es: " << sumaNodos(T);

    return 0;
}