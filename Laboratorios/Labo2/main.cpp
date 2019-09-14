/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: enrique
 *
 * Created on September 13, 2019, 1:38 PM
 */


#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */

void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
            cout<<"Mover el disco "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
             
    }
    else
    {
        hanoi(num-1,A,B,C);
        cout<<"mover el disco "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}

int mcd(int mayor, int menor, int div){
    
     if(menor!=0){
         div=menor;
    menor=mayor%menor;
    mayor=div; 
    
    mcd(mayor,menor,div);
     }else{
         return div;
     }
    
}


int Ncifras(int num, int contador){
    if(num/10>0)
    {
        num=num/10;
        Ncifras(num,contador+1);
    }else{
        return contador;
    }
    
}

int main(int argc, char** argv) {
    //EJERCICIO 1 GUIA 2;
    /*int mayor,menor,div=0;
    cout<<"ingrese el mayor"<<endl;
    cin>>mayor;
    cout<<"ingrese el menor"<<endl;
    cin>>menor;
    cout<<mcd(mayor,menor,div);
    */
    
    
     /*EJERCICIO 5C Torres de hanoi
      * 
      *  int n;
        char A,B,C;
 
        cout<<"Los clavijas son A B C"<<endl;
        cout<<"Numero de discos a utilizar: ";
        cin>>n;
      cout<<La resolucion del juego es:<<endl;
        hanoi(n,'A','C','B');
   */
    
    //Ejercicio 8, contar cifras
   
    
    
    
    int num,contador=1;
    cout<<"Escriba un numero"<<endl;
    cin>>num;
 
    cout<<"El numero tiene "<<Ncifras(num,contador)<<" cifras";
   

    
    
    return 0;
}

