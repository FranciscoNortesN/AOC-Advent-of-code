#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

bool is_it_safe (vector<int> v){
	int direction = (v[1] > v[0]) ? 1 : -1;
	bool safe = true;
	for (int i = 0; i < v.size() - 1; i++) {
		int diff = v[i + 1] - v[i];
		if (std::abs(diff) < 1 || std::abs(diff) > 3) safe = false;
		if ((diff > 0 && direction < 0) || (diff < 0 && direction > 0)) safe = false; 
	}
	return safe;
}


int analisis(vector <int> &v){
	bool safe=is_it_safe(v);
	if (safe) return 1;
	else {
		for(int i=0;i<v.size();i++){
			vector<int> edge = v;
			edge.erase(edge.begin()+i);
			if (is_it_safe(edge)) return 1;
		}
	}
	return 0;
}

int main(){
	//tenemos que coger deferentes líneas de números, cada una con una cantidad diferente de números, tenemos que guarda cada línea
	
	string line;
	int cont = 0;

	while(getline(cin, line)){
		//creamos un stream de string
		istringstream ss(line);
		//creamos un vector de enteros
		vector<int> v;
		//leemos los números de la línea
		int n;
		while(ss >> n){
			v.push_back(n);
		}
		cont+=analisis(v);
	}

	cout <<cont<<endl;

	return 0;
}
