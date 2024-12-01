#include <iostream>
#include <vector>

using namespace std;

long long memoria[100000];

template <typename T>
int Partition(std::vector<T> &v, int ini, int fin){
	T x=v[fin];
	int i=ini;
	for (int j=ini;j<fin;j++){
		if(v[j]<=x){
			T aux=v[j];
			v[j]=v[i];
			v[i]=aux;
			i++;
		}
	}
	T aux=v[i];
	v[i]=v[fin];
	v[fin]=aux;
	return i;
}

template <typename T>
void QuickSort(std::vector<T> &v, int ini, int fin){
	//std::cout<<"ini: "<<ini<<", fin: "<<fin<<std::endl;
	if(ini<fin){
		int pivot = Partition(v, ini, fin);
		QuickSort(v, ini, pivot-1);
		QuickSort(v, pivot+1, fin);
	}
}

long long veces (long long num, vector<long long> v){
	if(memoria[num]!=-1){
		return memoria[num];
	}
	int cont=0;
	for(int i=0; i<v.size();i++){
		if(v[i]==num){
			cont++;
		}
	}
	memoria[num]=cont;
	return cont;
}

int main(){
	long long a, b; 
	long long suma=0;
	vector<long long> v1, v2;

	while (cin>>a>>b){
		v1.push_back(a);
		v2.push_back(b);
	}

	QuickSort(v1,0,v1.size()-1);
	QuickSort(v2,0,v2.size()-1);

	for (int i=0;i<100000;i++){
		memoria[i]=-1;
	}

	for (int i=0;i<v1.size();i++){
		suma+=(v1[i]*veces(v1[i],v2));
	}

	cout << suma;

	return 0;
}
