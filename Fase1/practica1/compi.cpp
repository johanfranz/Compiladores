#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <typeinfo>
#include <ctype.h>
#include <vector>
#include <stdio.h>


using namespace std;
//---------------------1ra practica inicio-------------------------------
void letraXletra(){
	string instruccion="";
	cout<<"escribir instruccion: ";
//	cin>> instruccion;
	getline(cin, instruccion);
	int n=instruccion.size();
	for (int i = 0; i < n; ++i)
	{
		cout<<"\t"<<instruccion[i]<<endl;
	}

}

void leerArchivo(string fichero){
	fstream ficheroEntrada;
	char letra;

	//ficheroEntrada.open ("a.txt", ios::in);
	ficheroEntrada.open (fichero, ios::in);
	if (ficheroEntrada.is_open()) {
		while (!ficheroEntrada.eof()) {
			ficheroEntrada >> letra;
			cout<< letra<<"   ";
		}
	ficheroEntrada.close();
	}
	else cout << "Fichero inexistente" << endl;
}



bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void separadorEnLine(string archivo){
	string texto;
	ifstream ifs(archivo);
	string s;
	string salida="";
	//file.open(archivo);
	while(getline(ifs,s)){
		salida=salida+s;
	}
	texto=salida;

	string aux;
	char letra;
	int n=texto.size();
	for (int i = 0; i < n; ++i){
		letra=texto[i];
		if(letra!=' '){ //poner los separadores
			aux=aux+letra;
		}
		else{
			if (is_number(aux)){
				cout<<"\t"<<"entero"<<endl; //poner los tipos
			}
			else if (aux=="+" or aux=="-" or aux=="*" or aux=="/"){
				cout<<"\t"<<"Caracter Especial"<<endl;	
			}
			else{
				cout<<"\t"<<"Palabra"<<endl;
			}
			aux="";
		} 
	}
}

void show(vector<int> v){
	int n=v.size();
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<"\t";
	}
}


void cifradoCesar(string fichero ,int posiciones){
	ifstream ifs(fichero);
	string s;
	string salida="";
	vector<int> v;
	ofstream file;
	file.open("encriptado.txt");
	while(getline(ifs,s)){
		salida=salida+s;
	}
	int n=salida.size();
	for (int i = 0; i < n; ++i){
		v.push_back(toascii(salida[i]) + posiciones);
	}
	string encriptado="";
	for (int j = 0; j < v.size(); ++j){
		file<<char(v[j]);
	}
	file.close();
}

void descifradoCesar(string fichero ,int posiciones){
	ifstream ifs(fichero);
	string s;
	string salida="";
	vector<int> v;
	ofstream file;
	file.open("DesEncriptado.txt");
	while(getline(ifs,s)){
		salida=salida+s;
	}
	int n=salida.size();
	for (int i = 0; i < n; ++i){
		v.push_back(toascii(salida[i]) - posiciones);
	}
	string encriptado="";
	for (int j = 0; j < v.size(); ++j){
		encriptado=encriptado+ char(v[j]);
		file<<char(v[j]);
	}
	file.close();
}


//---------------------1ra practica fin-------------------------------



int main(int argc, char const *argv[])
{
	letraXletra(); //pregunta 1
	leerArchivo("a.txt"); //pregunta 2

	cifradoCesar("a.txt",3); //pregunta 3
	descifradoCesar("a.txt",3); //pregunta 3
	separadorEnLine("a.txt"); //pregunta 4

	return 0;
}







/*

#include <iostream>
#include <fstream>
using namespace std;

int main () {
	 fstream ficheroEntrada;
	 char letra;

	 ficheroEntrada.open ("a.txt", ios::in);
	 if (ficheroEntrada.is_open()) {
		 while (!ficheroEntrada.eof()) {
			 ficheroEntrada >> letra;
			 cout << letra << " "<<endl;
		 }
	 ficheroEntrada.close();
	 }
	 else cout << "Fichero inexistente" << endl;
	 return 0;
}
*/