#include<iostream>
#include<cctype>
using namespace std;
enum class Estado{INICIO,E1,E2,E3,E4,E5,E6,E7,E8,E9,VALIDO,INVALIDO};

void fecha(string str){
	
	int pos = 0;
	Estado actual = Estado::INICIO;

	while(pos<str.length()){
		
	switch(actual){
		case Estado::INICIO: //iniciamos en INICIO	
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E1;  //si cumple pasa a E1
			else
			{
				actual = Estado::INVALIDO;
			}
		break;
		
		case Estado::E1: 
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E2;  //si cumple pasa a E2  
			else
			{
				actual = Estado::INVALIDO;
			}
		break;
					
		case Estado::E2: 
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E3;  //si cumple pasa a E3 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;	
		
		case Estado::E3: 
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E4;  //si cumple pasa a E4 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;		
		
		case Estado::E4: 
		
			if(str[pos]=='/')  //Debe ser un slash /
			actual = Estado::E5;  //si cumple pasa a E5 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;
		
		case Estado::E5: 
				if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E6; 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;
		
		case Estado::E6: 
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E7; 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;		
		
		case Estado::E7: 
			
			if(str[pos]=='/')
			actual = Estado::E8; 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;
		
		case Estado::E8: 
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::E9; 
			else
			{
				actual = Estado::INVALIDO;
			}
		break;
		
		case Estado::E9:
			if(isdigit(str[pos]))  //Debe ser un numero
			actual = Estado::VALIDO;
			else
			actual = Estado::INVALIDO;
		break;
			
		default:  
			actual = Estado::INVALIDO;
		
		}
		pos++;
	}
if(actual == Estado::VALIDO)
	cout<<"true\nLa fecha esta bien escrita"<<endl;
else
	cout<<"false\nLa fecha esta bien escrita"<<endl;
}


	
	
int main(){
	string cadena = "0000/00/00";
	fecha(cadena);
	
	return 0;
}
