#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stdlib.h>




using namespace std;


//split que devuelve un vector de enteros en base al delimitador
vector<int> split(const string& str, char delimiter) {
    vector<int> result;
    istringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        // Eliminar espacios en blanco al inicio y al final
        token.erase(token.begin(), find_if(token.begin(), token.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));
        token.erase(find_if(token.rbegin(), token.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), token.end());
        
        try {
            result.push_back(stoi(token));
        } catch (const invalid_argument&) {
            throw runtime_error("Error: La cadena contiene elementos no convertibles a enteros.");
        }
    }

    return result;
}


void imprimirGrafo(const unordered_map<int, unordered_set<int>>& grafo) {
    for (const auto& par : grafo) {
        cout << "Clave: " << par.first << " -> ";
        for (int num : par.second) {
            cout << num << " ";
        }
        cout << endl;
    }
}




//devuelve si b debe de ir después de a según las reglas
bool a_b(int a, int b, const unordered_map<int, unordered_set<int>>& grafo){
     return find(grafo.at(a).begin(), grafo.at(a).end(), b) != grafo.at(a).end();
}
    

//devuelve si la secuencia cumple con las reglas
bool cumple_reglas(vector<int> input, const unordered_map<int, unordered_set<int>>& grafo){ 
    for(int i = input.size() - 1; i >= 0; i--){
        for(int j = 0 ; j < i; j++){
            if(a_b(input[i], input[j], grafo))  //si se encuentra una j que debe ir después de i, antes que i, la linea es incorrecta  
                return false;
        }
    }
    return true;
}

//devuelve el elemento de la mitad
int medio(vector<int> v){ 
    return v[v.size()/2];
}


//orden topológico
vector<int> sortUpdate(const vector<int> &update, const unordered_map<int, unordered_set<int>>& grafo) {
    unordered_map<int, int> inDegree;  
    unordered_map<int, vector<int>> grafo_temp;  
    
    // Construimos el grafo temporal y calculamos los grados de entrada
    for (int nodo : update) {
        inDegree[nodo] = 0;
    }
    for (const auto &regla : grafo) {
        int A = regla.first;
        for (int B : regla.second) {
            if (inDegree.count(A) && inDegree.count(B)) {
                grafo_temp[A].push_back(B);
                ++inDegree[B];
            }
        }
    }

    // Hacemos el orden topológico con el algoritmo de Kahn
    queue<int> q;
    for (const auto &entrada : inDegree) {
        if (entrada.second == 0) {
            q.push(entrada.first);   //Metemos en la cola todos los nodos con 0 entradas
        }
    }

    vector<int> ordenado;            
    while (!q.empty()) {             //procesamos los nodos mientras la cola no esté vacía
        int actual = q.front(); 
        q.pop();                     //sale el primero de la cola
        ordenado.push_back(actual);  //y lo añadimos al vector ordenado
        for (int vecino : grafo_temp[actual]) {  //decrementamos en 1 el grado de entrada de todos los nodos a los que apuntaba
            --inDegree[vecino];
            if (inDegree[vecino] == 0) {  //si se queda sin entradas lo metemos a la cola
                q.push(vecino);
            }
        }
    }
    return ordenado;
}



int main() {
    unordered_map<int, unordered_set<int>> grafo;
    unordered_map<int, int> inDegree;
    string linea;
    int suma_correctos = 0;
    int suma_incorrectos = 0;

    ifstream archivo("input_dia5.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el fichero." << endl;
        return 1; 
    }

    while (getline(archivo, linea)){
        if (linea[2]=='|'){
            
            int A = (linea[0]-'0')*10 + (linea[1]-'0');
            int B = (linea[3]-'0')*10 + (linea[4]-'0');
        
            grafo[A].insert(B);     
        }



        else if (linea[2]==','){
            vector<int> update;

           update = split(linea, ',');
            
            if(cumple_reglas(update, grafo)){
            
            suma_correctos += medio(update);
            
            }else{
                update = sortUpdate(update, grafo);
                suma_incorrectos += medio(update);
            }
        }
       
    }
    archivo.close();    


    //imprimirGrafo(grafo);
    cout << "Suma de correctos: " << suma_correctos << endl;
    cout << "Suma de incorrectos ordenados: " << suma_incorrectos<< endl;
    return 0;
}

