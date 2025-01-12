/*
 * en este problema nos dan una serie de números y nosotros tenemos que aplicarles "parpadeos"
 * cada parpadeo realiza una operación en los números, la operación es la siguiente:
 * si el número es 0, se convierte en 1
 * si el número posee un número par de dígitos, se divide en 2 números
 * en caso de que no se apliquen ninguna de las anteriores, se multiplica por 2024
 *
 * se realizan en total BLINKS parpadeos y se cuentan cuantos números hay en el último parpadeo
 *
 * se ha visto que los números podrían poseer una estructura de árbol
 *
 * se ha visto que si n es demasiado grande, es necesaria la programación dinámica
 */

#include <iostream>
#include <vector>
#include <cmath>

#define BLINKS 25

typedef unsigned long long ull;

using namespace std;

class Node {
public:
	ull value;
	Node *left;
	Node *right;

	Node(ull value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Tree {
public:
	Node *root;

	Tree() {
		this->root = nullptr;
	}

	void insert(ull value) {
		if (this->root == nullptr) {
			this->root = new Node(value);
		} else {
			insert(this->root, value);
		}
	}

	void insert(Node *node, ull value) {
		if (value < node->value) {
			if (node->left == nullptr) {
				node->left = new Node(value);
			} else {
				insert(node->left, value);
			}
		} else {
			if (node->right == nullptr) {
				node->right = new Node(value);
			} else {
				insert(node->right, value);
			}
		}
	}

	void print() {
		print(this->root);
	}

	void print(Node *node) {
		if (node != nullptr) {
			print(node->left);
			cout << node->value << " ";
			print(node->right);
		}
	}
};

//vector de vectores que guarda los punteros de los nodos de cada nivel
vector<vector<Node*>> levels (BLINKS+1);

ull num_digits(ull n) {
	ull count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

// función que cuenta los nodos del nivel n
ull countNodes(Node *node, ull n) {
	if (node == nullptr) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	return countNodes(node->left, n - 1) + countNodes(node->right, n - 1);
}

//función que busca el valor de un nodo en el nivel n
//si lo encuentra, devuelve la posición en la que se encuentra para despues copiar el nodo
//si no lo encuentra, devuelve -1
int search(Node *node, ull n) {
	for (int i = 0; i < levels[n].size(); i++) {
		if (levels[n][i]->value == node->value) {
			return i;
		}
	}
	return -1;
}

void parpadeo(Node *node) {
	if (node != nullptr) {
		if (node-> value == 0) {
			//creamos un nuevo nodo con el valor 1 y lo insertamos en un nuevo nivel
			Node *newNode = new Node(1);
			node->left = newNode;
			node->right = nullptr;
		} else if (num_digits(node->value) % 2 == 0) {
			//creamos dos nuevos nodos con los valores de la división y los insertamos en un nuevo nivel
			ull value = pow(10, num_digits(node->value) / 2);
			Node *newNode1 = new Node(node->value / value);
			Node *newNode2 = new Node(node->value % value);
			node->left = newNode1;
			node->right = newNode2;
		} else {
			//creamos un nuevo nodo con el valor multiplicado por 2024 y lo insertamos en un nuevo nivel
			Node *newNode = new Node(node->value * 2024);
			node->left = newNode;
			node->right = nullptr;
		}
	}
}

// función recursiva que realiza los n parpadeos
void parpadeos(Node *node, ull n) {
	if (node == nullptr) {
		return;
	}
	if (n == 0) {
		return;
	}
	if (search(node, n) != -1) {
		//si el nodo ya se encuentra en el nivel n, en el arbol nos guaramos el nodo que hemos guardado en el vector
		Node *puntero = nullptr;
		puntero = levels[n][search(node, n)];
		*node = *puntero;
		return;
	}
	parpadeo(node);
	parpadeos(node->left, n - 1);
	parpadeos(node->right, n - 1);
}

int main() {
	/* obtenemos los valores de entrada mediante un cin
	 * creamos un árbol nuevo con cada valor de entrada
	 * cada valor de entrada es un nodo raíz
	 * sumamos la cantidad de nodos en el nivel BLINKS
	 * */
	ull n;
	ull value=0;
	while (cin >> n) {
		Tree tree;
		tree.insert(n);
		parpadeos(tree.root, BLINKS);
		ull count = countNodes(tree.root, BLINKS);
		cout << "count: " << count << endl;
		value += count;
	}
	cout << "value: " << value << endl;
	return 0;
}
