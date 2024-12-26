#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>


using namespace std;

bool in(vector<int> v, int num){   //devuelve si num se encuentra en v
    for(int i = 0; i < v.size(); i++){
        if (v[i] == num)
            return true;
    }
    return false;
}

bool va_antes(int a, int b, vector<int> normas[]){  //devuelve si a va antes que b
    if(in(normas[b-10], a)){
        return true;
    }
    return false;

}

bool cumple_reglas(vector<int> input, vector<int> normas[]){ 
    for(int i = 0; i < input.size(); i++){
        for(int j = i + 1 ; j < input.size(); j++){
            if(va_antes(input[j], input[i], normas))  //si se encuentra después un número que debe ir antes es incorrecta
                return false;
        }
    }
    return true;
}


int medio(vector<int> v){ //devuelve el elemento de la mitad
    int pos = v.size()/2;
    return v[pos];
}


void merge(vector<int>& vec, int left, int mid, int right, vector<int> normas[]) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftVec(n1), rightVec(n2);

    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (va_antes(leftVec[i], rightVec[j], normas)) {  
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& vec, int left, int right, vector<int> normas[]) {
    if(left < right){
             
        int mid = left + (right - left) / 2;
  
        mergeSort(vec, left, mid, normas);
        mergeSort(vec, mid + 1, right,normas);

        merge(vec, left, mid, right,normas);
    }
}


int main() {
    vector<int> normas[90]; 
    string linea;
    
    int suma_correctos = 0;
    int suma_incorrectos = 0;

    ifstream archivo("input_dia5.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el fichero." << endl;
        return 1; 
    }

    while (getline(archivo, linea)){
        vector<int> input_line;
        if (linea[2]=='|'){
            int a = (linea[0]-'0')*10 + (linea[1]-'0');
            int b = (linea[3]-'0')*10 + (linea[4]-'0');
            normas[b-10].push_back(a);
        }
        else if (linea[2]==','){
            size_t pos;
            while ((pos=linea.find(',')) != string::npos){
                input_line.push_back(stoi(linea.substr(0,pos)));
                linea.erase(0,pos+1);
            }

            input_line.push_back(stoi(linea));

            if(cumple_reglas(input_line, normas)){
                suma_correctos+= medio(input_line);
            }else{
                mergeSort(input_line, 0, input_line.size() - 1, normas);
                suma_incorrectos += medio(input_line);
            }
        }
     }

    archivo.close(); 

    cout << "Suma de correctos: " << suma_correctos << endl;
        cout << "Suma de incorrectos ordenados: " << suma_incorrectos<< endl;

    return 0;
}

