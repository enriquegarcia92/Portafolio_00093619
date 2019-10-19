#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

struct libro
{
    string nombre;
    int NumeroPaginas;
    libro *sig;
};



class ListaSimple
{
private:
    string nombreLista;
    libro *inicio;

public:
    ListaSimple();
    libro *CrearNodo(int, string);
    void insertarInicio(int, string);
    void insertarFinal(int, string);
    void prestamo(string);
    void regreso(string);
    void mostrar();
    void BuscarElemento(string);
};
ListaSimple::ListaSimple()
{
    inicio = NULL;
   
     
}

libro *ListaSimple::CrearNodo(int dato, string nombre)
{
    
    libro *nuevo = new (libro);
    nuevo->NumeroPaginas = dato; //
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    return nuevo;
}

void ListaSimple::insertarInicio(int numeropaginas, string nombre)
{
   
    libro *nuevo = ListaSimple::CrearNodo(numeropaginas, nombre); 
    nuevo->sig = this->inicio;                                    
    this->inicio = nuevo;                                         
}






void ListaSimple::BuscarElemento(string nombre) {
	libro* s = inicio;

	while (s != NULL && s->nombre != nombre) {
		s = s->sig;
	}

	if (s != NULL)
		cout << s->nombre << " " << s->NumeroPaginas << " "<< endl;
	else
		cout << "El dato no esta en la lista." << endl;
}



int main()
{
    ListaSimple l;
    
  

  char respuesta;
  string nombre,nombreb;
	int numeropaginas;

	cout << "Desea meter un dato (s/n)? ";
	cin >> respuesta;

	while (respuesta == 's')
	{
		cout << "Digite el nombre: ";
		cin >> nombre;
                cout << "Digite las paginas: ";
                cin>>numeropaginas;
		l.insertarInicio(numeropaginas,nombre);
		
		cout << "Desea ingresar un dato (s/n)? ";
		cin >> respuesta;
	}
        
        
        
        cout<<"nombre del libro que busca:";
        cin>>nombreb;
        
l.BuscarElemento(nombreb);



   
   
    return 0;
}