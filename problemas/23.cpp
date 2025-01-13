#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<string>> conjuntos(vector<vector<string>> grafo, vector<string> v){
	vector<vector<string>> res;
	//vamos a recorrer el grafo y a ver si hay algún conjunto de 3 elementos que estén conectados entre sí
	for (ll i = 0; i < grafo.size(); i++){
		//si no hay 3 elementos conectados no seguimos
		if (grafo[i].size() < 3){
			continue;
		}
		
		
	}
	return res;
}

ll resolver(vector<vector<string>> grafo, vector<string> v){
	//llamamos a la función que nos devuelva los conjuntos de 3 elementos que están conectados entre sí
	vector<vector<string>> res=conjuntos(grafo, v);
	
}

int main(){
	// tenemos que coger 5 caracteres y colocarlos de tal manera que se forme un grafo
	string s;
	vector<string> v;
	vector<vector<string>> grafo; //identificamos los elementos que están conectados al nuestro mediante la primera posición del vecotor para el que está conectado y las siguientes para los que se conectan a él
	while (cin >> s){
		//nos cogemos los primeros 2 caracteres
		string aux = s.substr(0, 2);
		//y en otro nos guardamos los 2 últimos
		string aux2 = s.substr(3, 2);
		
		//comprobamos si ya están en el grafo
		ll esta = -1;
		ll esta2 = -1;
		for (ll i = 0; i < grafo.size(); i++){
			if (grafo[i].size() == 0){
				continue;
			}
			if (grafo[i][0] == aux){
				esta = i;
			}
			if (grafo[i][0] == aux2){
				esta2 = i;
			}
		}

		//si no están los añadimos
		if (esta == -1){
			vector<string> aux3;
			aux3.push_back(aux);
			grafo.push_back(aux3);
			esta = grafo.size() - 1;
		}
		if (esta2 == -1){
			vector<string> aux3;
			aux3.push_back(aux2);
			grafo.push_back(aux3);
			esta2 = grafo.size() - 1;
		}

		//y los conectamos
		grafo[esta].push_back(aux2);
		grafo[esta2].push_back(aux);

		//y guardamos los elementos en un vector si no están ya
		ll esta3 = -1;
		for (ll i = 0; i < v.size(); i++){
			if (v[i] == aux){
				esta3 = i;
			}
		}
		if (esta3 == -1){
			v.push_back(aux);
		}
		esta3 = -1;
		for (ll i = 0; i < v.size(); i++){
			if (v[i] == aux2){
				esta3 = i;
			}
		}
		if (esta3 == -1){
			v.push_back(aux2);
		}

	}

	//ahora tenemos que resolver el problema
	//el problema nos dice que tenemos que encontrar conjuntos de 3 elementos que estén conectados entre sí y que los guardemos en un vector
	//vamos a llamar a la función que nos resuelva el problema y nos devuelva el número de conjuntos dentro del vector que en alguno de los nodos posee una t.
	ll res = 0;
	res = resolver(grafo, v);

	return 0;
}
