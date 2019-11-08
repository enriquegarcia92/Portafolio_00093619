#include <iostream>
using namespace std;
//intente hacer los otros 2 literales pero siempre me daba 6, y hasta esta semana empezamos a ver arboles entonces no pude
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

int Sumapar(Nodo *T){
    if(T==NULL){
        return 0;
    }
    else{
        int M=0;
        if(T->dato%2==0) M = T->dato;
        return M + Sumapar(T->izq) + Sumapar(T->der);
    }
}

int SumaImpar(Nodo *T){
    if(T==NULL){
        return 0;
    }
    else{
        int M=0;
        if(T->dato%2!=0) M = T->dato;
        return M + SumaImpar(T->izq) + SumaImpar(T->der);
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



int main()
{
    system("color 4f");
    inicializarArbol();

    Nodo* n6 = inicializarNodo(-3);
    Nodo* n5 = inicializarNodo(-2);
    Nodo* n4 = inicializarNodo(-1);
    Nodo* n3 = inicializarNodo(0);
    Nodo* n2 = inicializarNodo(1);
       Nodo* n1 = inicializarNodo(6);

    T = n1; n1->izq = n2; n1->der = n3;
    n2->izq = n4; n2->der = n5; n3->izq = n6;

    mostrarArbolPreOrder(T);
    cout << "\n============================================\n";



    cout << "El total de nodos es: " << contarNodos(T)<<endl;


    cout <<"Suma Impar: " << SumaImpar(T)<<endl;
    cout <<"Suma par: " << Sumapar(T)<<endl;
    return 0;
}