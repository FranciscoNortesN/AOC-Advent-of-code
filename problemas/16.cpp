#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

class Punto {
public:
    int posX, posY;  // Posiciones
    int dirX, dirY;  // Direcciones
    int costo;       // Costo asociado

    // Constructor
    Punto(int x = 0, int y = 0, int dx = 0, int dy = 0, int c = 0)
        : posX(x), posY(y), dirX(dx), dirY(dy), costo(c) {}

    // Sobrecarga del operador '>'
    bool operator>(const Punto& other) const {
        return costo > other.costo;
    }

    // Método para verificar si el punto es válido en un laberinto
    bool es_valido(const vector<vector<char>>& maze) const {
        return maze[posX][posY] != '#';
    }

    // Método para mover adelante
    Punto moverAdelante() const {
        return Punto(posX - dirX, posY + dirY, dirX, dirY, costo);
    }

    // Método para rotar el punto
    Punto rotar(bool horario) const {
        if (horario) {
            return Punto(posX, posY, dirY, -dirX, costo);
        } else {
            return Punto(posX, posY, -dirY, dirX, costo);
        }
    }
};

vector<vector<int>> bfs(const vector<vector<char>>& maze, Punto start, Punto end) {
    int rows = maze.size();
    int cols = maze[0].size();

    //Búsqueda en anchura pero en la cola tienen prioridad los puntos con menor costo acumulado, 
    //así se garantiza que la primera vez que se llega al destino, es con el menor costo posible.
    vector<vector<int>> visitados(rows, vector<int>(cols, 0));
    priority_queue<Punto, vector<Punto>, greater<Punto>> pq;

    start.costo = 0;
    pq.push(start);

    while (!pq.empty()) {
        Punto actual = pq.top();
        pq.pop();

        if (actual.posX == end.posX && actual.posY == end.posY) {
            visitados[actual.posX][actual.posY] = actual.costo;
            return visitados;
        }

        if (visitados[actual.posX][actual.posY]) {
            continue;
        }
        visitados[actual.posX][actual.posY] = actual.costo;

        // Mover hacia adelante
        Punto adelante = actual.moverAdelante();
        if (adelante.es_valido(maze)) {
            adelante.costo = actual.costo + 1;
            pq.push(adelante);
        }

        // Rotar a la izquierda y mover
        Punto izquierda = actual.rotar(false).moverAdelante();
        if (izquierda.es_valido(maze)) {
            izquierda.costo = actual.costo + 1001;
            pq.push(izquierda);
        }

        // Rotar a la derecha y mover
        Punto derecha = actual.rotar(true).moverAdelante();
        if (derecha.es_valido(maze)) {
            derecha.costo = actual.costo + 1001;
            pq.push(derecha);
        }
    }

    return visitados; // En caso de no encontrar un camino
}

vector<vector<char>> readMazeFromFile(const string& filename) {
    vector<vector<char>> maze;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return maze;
    }

    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        maze.push_back(row);
    }

    file.close();
    return maze;
}

int main() {
    string filename = "input_dia16.txt";
    vector<vector<char>> maze = readMazeFromFile(filename);

    if (maze.empty()) {
        return 1;
    }

    Punto start, end;

    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[0].size(); ++j) {
            if (maze[i][j] == 'S') {
                start = Punto(i, j, 0, 1, 0); // Dirección inicial EAST
            } else if (maze[i][j] == 'E') {
                end = Punto(i, j, 0, 1, 0);
            }
        }
    }

    auto starting = chrono::system_clock::now();
    vector<vector<int>> mem = bfs(maze, start, end);
    auto ending = chrono::system_clock::now();

    chrono::duration<float, milli> duration = ending - starting;
    cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << endl;

    int resultado = mem[end.posX][end.posY];
    cout << "El costo mínimo para llegar al destino es " << resultado << " puntos." << endl;

    return 0;
}
