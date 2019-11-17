#include <iostream>
//Jose Enrique Garcia Arevalo 00093619
using namespace std;

struct nodo{
int info;
struct nodo *izq;
struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

struct Lista{
int info;
struct Lista *sig;
};
typedef struct Lista lista;
lista *pInicio;

Arbol crearArbol(int x){
Arbol p = new Nodo;
p->info = x;
p->izq = NULL;
p->der = NULL;
return p;
}

void asignarIzq(Arbol a, int unDato){
if(a == NULL)
cout << "Error: arbol vacio" << endl;
else if(a->izq != NULL)
cout << "Error: subarbol IZQ ya existe" << endl;
else
a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
if(a == NULL)
cout << "Error: arbol vacio" << endl;
else if(a->der != NULL)
cout << "Error: subarbol DER ya existe" << endl;
else
a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a, int numero){

Arbol p = a;

while(true){
if(numero == p->info){
cout << "Error: " << numero << " ya existe" << endl;
return;
}
else if(numero < p->info){
if(p->izq == NULL)
break;
else
p = p->izq;
}
else{
if(p->der == NULL)
break;
else
p = p->der;
}
}

if(numero < p->info)
asignarIzq(p, numero);
else
asignarDer(p, numero);
}

void preorden(Arbol a){
if(a != NULL){
cout << " " << a->info;
preorden(a->izq);
preorden(a->der);
}
}

void recorrerArbol(Arbol a){
cout << "Recorrido del arbol:"; preorden(a); cout << endl;
}

void insertarlista(int num) {
lista *nuevo = new lista;
nuevo->info = num;
nuevo->sig = NULL;

if (pInicio == NULL) {
pInicio = nuevo;
} else {
lista *p = pInicio;
lista *q = NULL;
while (p != NULL) {
q = p;
p = p->sig;
}
q->sig = nuevo;
}
}

int main(){
cout<<"Inicializando lista...\n";

int opcion = 0;
bool continuar = true;
int numero = 0;
do{
cout << "1) Agregar Numero a la lista"<<endl;
cout <<" 2)Salir "<<endl;
cin >> opcion;

switch(opcion){
case 1: cout <<"Agregar numero: "; cin >> numero;
insertarlista(numero); break;
case 2: continuar = false; break;
default: cout << "Opcion invalida";
}

}while(continuar);

Arbol arbol = crearArbol(pInicio->info);
lista *p = pInicio->sig;
while(p != NULL){
agregarNodo(arbol, p->info);
p = p->sig;
}

p = pInicio->sig;
lista *q = p->sig;

while(q != NULL && p != NULL){
delete(p);
p = q;
q = q->sig;
}

recorrerArbol(arbol);

return 0;
}