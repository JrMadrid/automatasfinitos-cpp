#include<iostream>
#include<cctype>
using namespace std;
enum class Estado{INICIO,E1,E2,VALIDO,INVALIDO};

void password(string str){
	
	int pos = 0;
	Estado actual = Estado::INICIO;
	
	if(str.length()>=6)
	{
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
					if(isupper(str[pos]))  //Debe ser una letra
						actual = Estado::E2;  //si es letra se mantiene
					else
					{
						actual = Estado::INVALIDO;
					}
				break;
							
				case Estado::E2: 
					if(isupper(str[pos]))  //Debe ser una letra
						actual = Estado::E2;  //si es letra se mantiene, debe cambiar de estado hasta que deje ser letra 
					else
					{
						if(str[pos]=='#'||str[pos]=='*')
							actual = Estado::VALIDO;
						else	
							actual = Estado::INVALIDO;
					}
				break;	
				
				default:  
					actual = Estado::INVALIDO;
				
				}  //Switch
			pos++;
		}	//while
	} //if
	else
		cout<<"La contraseña contener 6 digitos como minimo\n\t";
		
	if(actual == Estado::VALIDO)
		cout<<"True\nContraseña Valida"<<endl;
	else
		cout<<"False\nContraseña Invalida"<<endl;
}//funcion
	
	
int main(){
	string cadena = "5HOLA*";
	setlocale(LC_ALL, "spanish"); //pasa usar la Ñ
	password(cadena);
	
	return 0;
}
