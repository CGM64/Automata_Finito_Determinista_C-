#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

string cadena;
int n = 0;
int estado = 0;
int error = 0;
int c = 0;
int fin = 0;
string simbolo;
string cadena2 = "";

int SigSimbolo(){
    if(n == cadena.size()){
        fin = 1;
        
        return -1;
    }else{
        n = n + 1;
        
        //Recoore iteradamente desde la cadena anterior a la posici�n n cadena por cadena cada vez que se ejecute el m�todo
        //Recoore cadena por cadena
        simbolo = cadena.substr(n-1,1); 
        
        return 0;
    }
}

//N�meros impares de a
//ER:b*a+b*
void Reconocer1(){
	string cantA = "";
	
	SigSimbolo();
	
    cadena2 = cadena2 + simbolo;
    
    while(error == 0 && fin == 0){
        cout<<"S�mbolo: " <<simbolo <<"\tn: " <<n <<"\t" <<"Estado: " <<estado <<"\t";
        
        switch(estado){
        	//Desde qu� estado viene
            case 0:
	            if(simbolo == "a"){
	            	cantA = cantA + simbolo;
	            	
	            	//Hacia qu� estado va
		            if(cantA.length() %2 == 0){
		            	estado = 0;
		                
		            	cout<<"(q0,a)->q0" <<endl;
					}else{
						estado = 1;
		                
		            	cout<<"(q0,a)->q1" <<endl;
					}
	            }else if(simbolo == "b"){
	                estado = 0;
	                
	                cout<<"(q0,b)->q0" <<endl;
	            }else if((simbolo != "a" && simbolo != "b"  ) || (cantA.length() %2 == 0)){
	                error = 1;
	            }
            
            break;
            
            case 1:
                if(simbolo == "a"){
                	cantA = cantA + simbolo;
                	
                    if(cantA.length() %2 == 0){
		            	estado = 0;
		                
		            	cout<<"(q1,a)->q0" <<endl;
					}else{
						estado = 1;
                    
                    	cout<<"(q1,a)->q1" <<endl;
					}
                }else if(simbolo == "b"){
                    estado = 1;
                    
                    cout<<"(q1,b)->q1" <<endl;
                }else if((simbolo != "a" && simbolo != "b"  ) || (cantA.length() %2 == 0)){
                    error = 1;
                }
            break;
        }
        
        SigSimbolo();
        
        cadena2 = cadena2 + simbolo;
	}
	
	
	if(error == 0){
		//Validaci�n estado de aceptaci�n
        if(estado == 1){
            cout<<"\nLa cadena " <<cadena2 <<" es v�lida" <<endl;
        }else{
            cout<<"\nLa cadena " <<cadena2 <<" no es v�lida" <<endl;
        }
    }else{
        cout<<"\nLa cadena " <<cadena2 <<" no es v�lida" <<endl;
    }
}

int main(){
	setlocale(LC_CTYPE, "spanish");
	
	cadena2 = "";
    
    cout <<"Ingrese una cadena: ";
    cin>> cadena;
        
    cout<<"\nEl largo de la cadena: " <<cadena <<", es: " <<cadena.size() <<endl <<endl;
        
    Reconocer1();
    /*int salir = 0;
    
    do{
        system("cls");
        
        cadena2 = "";
    
        cout <<"Ingrese una cadena: ";
        cin>> cadena;
        
        cout<<"\nEl largo de la cadena: " <<cadena <<", es: " <<cadena.size() <<endl <<endl;
        
        Reconocer();
        
        cout<<"\n�Desea validar m�s cadenas? (1=s� o 0=no): ";
        cin>> salir;
    }while(salir == 1);*/
    
    return 0;
}
