#include <iostream>
#include <regex>
#include <string>


using namespace std;

int main() {
	
	long long suma = 0;
	string memory;
	bool ejecuta=true;
	
	while (cin>>memory){
		//nos creamos un regex que busque mul(seguido de cualquier número, y justo despues una coma, otro número y un paréntesis de cierre) o que encuentre do() o don't()
		regex todo(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
		regex r("mul\\([0-9]+,[0-9]+\\)");
		regex enable("do\\(\\)");
		regex disable("don't\\(\\)");
		smatch encuentra, encuentras;
		//buscamos el regex en la memoria tantas veces como sea necesario hasta que no haya más
		//mientras haya un match, metemos el resultado en una variable llamada suma
		while(regex_search(memory,encuentras,todo)){
			string todos = encuentras.str();
			if (regex_search(todos,encuentra,enable)) ejecuta = true;
			else if (regex_search(todos,encuentra,disable)) ejecuta = false;
			else if (regex_search(todos,encuentra, r)){
				//guardamos el match en un string
				string match = encuentra.str();
				cout<<match<<endl;
				//buscamos la posición de la coma
				int coma = match.find(",");
				//buscamos la posición del paréntesis de cierre
				int par = match.find(")");
				//guardamos en dos variables los números que hay entre la coma y el paréntesis de cierre
				int num1 = stoi(match.substr(4,coma-4));
				int num2 = stoi(match.substr(coma+1,par-coma-1));
				//calculamos el producto de los dos números
				cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
				long long resultado = num1*num2;
				//guardamos el resultado en la variable suma
				if (ejecuta) suma += resultado;
				//borramos el match de la memoria
			}
			memory = encuentras.suffix().str();
		}
	}

	cout<<suma<<endl;

	return 0;

}
