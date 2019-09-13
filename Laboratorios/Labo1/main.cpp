/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: enrique
 *
 * Created on September 6, 2019, 1:40 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */


struct complejo{
	int real=0,imag=0;
};



void contar1(int n, int i, int j){
    if(i<n){
        cout<<i;
        contar1(n,i+1,j);
    }else if(j>0){
        cout<<j;
        contar1(n,i,j-1);
    }
}


void arrayingreso(int*p, int n) {
	if (n>=0) {
		cin>>*p;
		arrayingreso(p+1,n-1);
	}
}

int funcsumar(int *p,int n,int aux) {
   
	
	if (n>=-1) {
		funcsumar(p+1,n- 1,aux+*p);
             if(n==-1){
                 return aux;
             }   
	}
       
        
}

int acotar(int r, int i, int c){
    
	
	if(i < 0){
		c=(-1)*(i);
		cout << "La conjugada es: " << r << " + " << c << "i" << endl;
	}
	else if(i>0){
		c=(-1)*(i);
		cout << "La conjugada es: " << r << c << "i " << endl;
	}
	return 0;
}

void matriz(int filas, int columnas){
    int matriz[filas][columnas];
    int valor;

for (int i=0; i<filas; i++)
{
    for (int j=0; j<columnas; j++)
    {
        cout << endl << "Posicion [ " << i << " ] [ " << j << " ]" << endl;
        cout <<  "Ingrese un valor : ";
        cin >> valor;
        if(i==0 && j==2){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==0 && j==3){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==0 && j==4){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==1 && j==3){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==1 && j==4){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==2 && j==0){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==2 && j==4){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==3 && j==0){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==3 && j==1){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==4 && j==0){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==4 && j==1){
            valor=0;
            matriz[i][j] = valor;
        }else if(i==4 && j==2){
            valor=0;
            matriz[i][j] = valor;
        }else{
            matriz[i][j] = valor;
        }   
    }
 }

for (int i=0; i<filas; i++)
{
    for (int j=0; j<columnas; j++)
    {
      
        cout<<matriz[i][j];
    }
    cout<<endl;
 }
    
}

int main(int argc, char** argv) {
    //Jose Enrique Garcia Arevalo 00093619
    //Ejercicio numero 8
    //----------------------------------------------------------------------------------------
    /*cout<<"ingrese el dato"<<endl;
    int n,i=0,j=0;
    cin>>n;
    cout<<endl;
    j=n;
    contar1(n,i,j);
    return 0;*/
    //Ejercicio numero 16
    //----------------------------------------------------------------------------------------
    /*cout<<"cuantos numeros va a ingresar"<<endl;
    int n,a[50],aux=0;
    cin>>n;
    arrayingreso(a,n-1);
    cout<<funcsumar(a,n-1,aux);*/
    
    //Ejercicio numero 22
    //----------------------------------------------------------------------------------------
    
    /*int filas=5;
int columnas=5;


matriz(filas,columnas);*/
    
    
    
    //Ejercicio numero 26
    //----------------------------------------------------------------------------------------
    
    
    int c=0,r=0,i=0;
	cout << "Ingrese la parte real: " << endl;
	cin >> r;
	cout << "Ingrese la parte imaginaria: " << endl;
	cin >> i;
        
        acotar(r,i,c);
    	
    
    
    
}


