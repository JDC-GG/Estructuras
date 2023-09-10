#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
using namespace std;

bool palindroma_pilas(string word){
	bool pal=true;
	stack<char> palabra_en_pila;
	for(char a : word){
		if(a != ' '){
			palabra_en_pila.push(a);
		}
	}
	stack<char> compara = palabra_en_pila;
	stack<char> compara1;
	while (!palabra_en_pila.empty()) {
        char b = palabra_en_pila.top();
        palabra_en_pila.pop();
        compara1.push(b);
    }
	while(!compara.empty()){
		if(compara.top()!= compara1.top()){
			pal=false;
			break;
		}
		else{
			compara.pop();
			compara1.pop();
		}
	}
	return pal;
}

bool palindroma_normal (string word){
  bool pal=true;
	vector<char> palabra;
	int tam=0;
	for (char x : word) {
        if (x != ' ') {
            palabra.push_back(x);
            tam+=1;
        }
    }
	int aux=tam-1;
	for (int i = 0; i < tam && pal; i++) {
        if (palabra[i] != palabra[aux]) {
            pal = false;
        }
        aux -= 1;
    }
    return pal;
	}

int main(){
	
	string word;
  int method;
  do{
    cout<<"Ingrese de que forma desea saber si su palabra/numero es palindroma/capicua, ingrese unicamente el numero:"<<endl;
    cout<<"1. Por medio de pilas"<<endl;
    cout<<"2. Por medio de un vector simple"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>method;
    cin.ignore();
    
    
	switch (method){
    case 1:
      cout<<"Ingrese la frase/palabra para identificar si es palindroma"<<endl;
	    getline(cin, word);
      if(palindroma_pilas(word)==true){
        cout<<"Es palindroma/capicua"<<endl;
      }
      else{
        cout<<"no es palindroma/capicua"<<endl;
      }
      
    break;

    case 2:
      cout<<"Ingrese la frase/palabra para identificar si es palindroma"<<endl;
	    getline(cin, word);
    if(palindroma_normal(word)==true){
        cout<<"Es palindroma=capicua"<<endl;
      }
      else{
        cout<<"no es palindroma/capicua"<<endl;
      }
    break;

    case 0:
      cout<<"Gracias por ingresar al sistema"<<endl;
    break;

    default:
      cout<<"Eligio una opcion invalida"<<endl;
    break;
    
  }
  }while(method!=0);

	return 0;
}
