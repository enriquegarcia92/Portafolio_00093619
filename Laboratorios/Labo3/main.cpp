/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: enrique
 *
 * Created on October 11, 2019, 5:29 PM
 */

#include <cstdlib>
#include <iostream>



using namespace std;

/*
 * 
 */


struct nodo
{
	int dato;
	nodo* sig;
};

class ListaSimple
{
private:
	nodo* pInicio;
public:
	ListaSimple(void);

	void insertar(int);
	void llamarnormal(void);
	void llamarinv(void);
	void mostrarnormal(nodo*);
	void mostrarinv(nodo*);
        void convertir(int n);
};


ListaSimple::ListaSimple(void) {
	pInicio = NULL;
}

void ListaSimple::insertar(int dato) {
	nodo* nuevo;

	nuevo = new nodo;
	nuevo->dato = dato;

	nuevo->sig = pInicio;
	pInicio = nuevo;

}


void ListaSimple::llamarinv(void) {
	mostrarinv(pInicio);
	cout << endl;
}

void ListaSimple::llamarnormal(void) {
	mostrarnormal(pInicio);
	cout << endl;
}

void ListaSimple::mostrarnormal(nodo* s) {
	if (s != NULL) {
		mostrarnormal((s->sig));
		cout << s->dato << " ";
	}
}
void ListaSimple::mostrarinv(nodo* s) {
	if (s != NULL) {
		cout << s->dato << " ";
		mostrarinv((s->sig));
	}
}

void ListaSimple::convertir(int n){
    int a=n%2;
    if(n>=2){
        
        convertir(n/2);
        insertar(a);
    }else{
        
        insertar(n);
        
    }
}

int main(int argc, char** argv) {
//Ejericio 5--------------------------------------------------------------------------------------------------------------------
	ListaSimple miLista;

	char respuesta;
	int dato;
        cout<<"Funcion recursiva que reciba una lista lineal simple y devuelva los nodos al reves";
	cout << "Desea meter un dato (s/n)? ";
	cin >> respuesta;

	while (respuesta == 's')
	{
		cout << "Digite el dato: ";
		cin >> dato;
		
		miLista.insertar(dato);

		cout << "Desea ingresar un dato (s/n)? ";
		cin >> respuesta;
	}


	miLista.llamarinv();
    
    
    
    
    
//Ejercicio 7--------------------------------------------------------------------------------------------------------
    
    
    
    /*
    ListaSimple miLista;

	char respuesta;
	int dato;
        cout<<"programa que convierte un numero base 10 a binario y lo guarda en una lista"
        cout<<"Numero que va a convertir:"<<endl;
	
		cout << "Digite el dato: "<<endl;
		cin >> dato;
		
		miLista.convertir(dato);

	

	miLista.llamarnormal();*/
	return 0;
}

