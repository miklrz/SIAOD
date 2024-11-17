#include <iostream>
#include <vector>
#include <limits>
#include <iomanip> // Для форматирования вывода
using namespace std;

// Граф представлен матрицей смежности
class Graph {
private:
    int vertices; // количество вершин
    vector<vector<int>> adjMatrix; // матрица смежности
    vector<int> visited; // посещённые вершины
    int minDistance;

    // Рекурсивный метод поиска кратчайшего пути
    void decisionTree(int current, int end, int distance) {
        if (current == end) {
            minDistance = min(minDistance, distance);
            return;
        }

        visited[current] = 1;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i] && adjMatrix[current][i] != 0) {
                decisionTree(i, end, distance + adjMatrix[current][i]);
            }
        }

        visited[current] = 0; // откат для следующего пути
    }

public:
    Graph(int v) : vertices(v), minDistance(INT_MAX) {
        adjMatrix.resize(v, vector<int>(v, 0));
        visited.resize(v, 0);
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
    }

    int findShortestPath(int start, int end) {
        minDistance = INT_MAX;
        decisionTree(start, end, 0);
        return minDistance;
    }


    void displayGraph() {
        cout << "Матрица смежности:\n";

        // Печать заголовка с номерами столбцов
        cout << setw(4) << " "; // Отступ для заголовка строк
        for (int i = 0; i < vertices; ++i) {
            cout << setw(4) << (i + 1);
        }
        cout << endl;

        // Печать строк матрицы
        for (int i = 0; i < vertices; ++i) {
            cout << setw(4) << (i + 1); // Номер строки
            for (int j = 0; j < vertices; ++j) {
                cout << setw(4) << (adjMatrix[i][j] ? adjMatrix[i][j] : 0);
            }
            cout << endl;
        }
    }
};
