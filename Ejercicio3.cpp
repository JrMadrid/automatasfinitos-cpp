#include<iostream>
#include<cctype>
using namespace std;
enum class Estado{INICIO,BINARIO,NOBINARIO,INVALIDO};

void numero(string str){
	
	int pos = 0;
	Estado actual = Estado::INICIO;
if(isdigit(str[pos])){
	while(pos<str.length()){
			
		switch(actual){
			case Estado::INICIO: //iniciamos en INICIO	
				if(isdigit(str[pos]))
				{  //Debe ser un numero
					if(str[pos]=='0'||str[pos]=='1')
						actual = Estado::BINARIO; 
					else
						actual = Estado::NOBINARIO;
				}			 
				else
				{
						actual = Estado::INVALIDO;
				}
			break;
			
			case Estado::BINARIO: 
				if(isdigit(str[pos]))
				{  //Debe ser un numero
					if(str[pos]=='0'||str[pos]=='1')
						actual = Estado::BINARIO; 
					else
						actual = Estado::NOBINARIO;
				}			 
				else
				{
						actual = Estado::INVALIDO;
				}
			break;
						
			case Estado::NOBINARIO: 
				if(isdigit(str[pos]))
				{  //Debe ser un numero
						actual = Estado::NOBINARIO;
				}			 
				else
				{
						actual = Estado::INVALIDO;
				}
			break;	
				
			default:  
				actual = Estado::INVALIDO;
			
			}
			pos++;
		}	
}
else 
	cout<<"Debe ingresar un numero"<<endl;
	
if(actual == Estado::BINARIO)
	cout<<"Es Binario"<<endl;
else if(actual == Estado::NOBINARIO)
	cout<<"No es Binario"<<endl;
else if(actual == Estado::INVALIDO)
	cout<<"Debe ingresar un numero"<<endl;
}


	
	
int main(){
	string cadena = "0000001";
	numero(cadena);
	
	return 0;
}
