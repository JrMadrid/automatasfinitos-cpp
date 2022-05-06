#include<iostream>
#include<cctype> //libreia de deteccion de tipos de caracteres
using namespace std;

//Clase enumerada para definir todos los posibles estados
enum class Estado{INICIO,Q1,ENTERO,Q2,REAL,INVALIDO};

//definimos una funcion para analizar la cadena de texto
//que vamos a anzalizar si es entero o si es real e imprimir

void analizarEnteroReal(string str){
	
	//vamos a recorrer la cadena para analizar la char por char 
	int pos = 0;// variable para saber en que posicion de la cadena estamos
	
	//declarar una variable para contrtolar el estado donde estoy actualmente
	Estado actual = Estado::INICIO;//iniciarla con estado INICIO
	
	//recorrer la cadena
	while(pos<str.length()){
		//dependiendo del analisis para controlar el estado donde estoy actualmente
		switch(actual){
		case Estado::INICIO: //cuando actual s INICIO
			if(str[pos]=='+'||str[pos]=='-')
			actual = Estado::Q1; //Pasamos a Q1
			else
			{
				if(isdigit(str[pos]))
				actual = Estado::ENTERO; //cae al estado ENTERO
				else
				actual = Estado::INVALIDO;
			}
		break;
		
		case Estado::Q1: //cuando estamos en Q1
			if(str[pos]=='.')
				actual = Estado::Q2; //pasamos al Q2
			else{
			if(isdigit(str[pos]))
				actual = Estado::ENTERO; //pasamos al estado ENTERO
			else
				actual = Estado::INVALIDO; //NO PASA A NINGUN LADO ES INVALIDO
			}
			break;
		case Estado::ENTERO: //actualmente esta en ENTERO
			if(str[pos]=='.')
				actual = Estado::Q2; //pasamos al Q2
			else{
				if(isdigit(str[pos]))
					actual = Estado::ENTERO; //continua en ENTERO
				else 
					actual = Estado::INVALIDO;  // en caso de no pasar nada es invalido
			}
			break;
			case Estado::Q2: //estamos en Q2
			if(isdigit(str[pos]))
				actual = Estado::REAL; //pasamos el estado a Real
			else
				actual = Estado::INVALIDO; // No paso la prueba entonces es INVALIDO
			break;
			
			case Estado::REAL: //actual REAL
				if(isdigit(str[pos]))
					actual = Estado::REAL; 
				else
					actual = Estado::INVALIDO; //NO PASO LA PRUEBA ES INVALIDO
					
			default: //en cao de falla el estado sera invalido
			actual = Estado::INVALIDO;
		}
		//pasar a la siguiente posicion 
		pos++;
	} //aqui termina el while
	
	//evaluar el estado actual y ver si quedo en algun estado FINAL
	cout<<str+" ";
	if(actual == Estado::ENTERO)
		cout<<"es un numero entero"<<endl;
	else
	{
		if(actual == Estado::REAL)
			cout<<"es un numero real"<<endl;
		else
			cout<<"no es un numero entero ni tampoco un numero real"<<endl;
	}
}
int main(){
	string cadena;
	cout<<"Digite un valor"<<endl;
	cin>>cadena;
	analizarEnteroReal(cadena);
	
	
	
	return 0;
}


