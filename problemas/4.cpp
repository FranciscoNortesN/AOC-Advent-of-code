#include <iostream>
#include <vector>

using namespace std;

int is_it_xmas(vector<vector<char>> v2, int i, int j) {
	int x = 0;
	if (v2[i][j] == 'X') {
		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (v2[i+k][j+l] == 'M') {
					if (v2[i+2*k][j+2*l] == 'A') {
						if (v2[i+3*k][j+3*l] == 'S') {
							x++;
						}
					}
				}
			}
		}
	}
	return x;
}

int findX(vector<vector<char>> v2) {
	int x = 0;
	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v2[0].size(); j++) {
			if (v2[i][j] == 'X') {
				x+=is_it_xmas(v2, i, j);
			}
		}
	}
	return x;
}

int main() {
	string a;
	vector<char> v;
	vector<vector<char>> v2;
	while (getline(cin, a)) {
		for (int i = 0; i < a.size(); i++) {
			v.push_back(a[i]);
		}
		v2.push_back(v);
		v.clear();
	}

	//me creo un vector de vectores, cuyas primera y ultima filas sean  0 y cuyas primera y última columnas sean 0
	vector<char> v3;
	for (int i = 0; i < v2[0].size()+2; i++) {
		v3.push_back('0');
	}
	vector<vector<char>> v4;
	v4.push_back(v3);
	for (int i = 0; i < v2.size(); i++) {
		v3.clear();
		v3.push_back('0');
		for (int j = 0; j < v2[0].size(); j++) {
			v3.push_back(v2[i][j]);
		}
		v3.push_back('0');
		v4.push_back(v3);
	}
	v3.clear();
	for (int i = 0; i < v2[0].size()+2; i++) {
		v3.push_back('0');
	}
	v4.push_back(v3);

	int x = findX(v4);
	cout << x << endl;
	return 0;
}
