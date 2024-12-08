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
        //cout << current << " ";

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

    // Ввод графа с клавиатуры
    void inputGraph() {
        cout << "Введите количество вершин: ";
        cin >> vertices;
        visited.resize(vertices, 0);
        adjMatrix.resize(vertices, vector<int>(vertices, 0));

        cout << "Введите рёбра графа (начало, конец, вес). Введите -1 для завершения.\n";
        while (true) {
            int u, v, weight;
            cout << "Начало: ";
            cin >> u;
            if (u == -1) break;
            cout << "Конец: ";
            cin >> v;
            cout << "Вес: ";
            cin >> weight;

            if (u > 0 && v > 0 && u <= vertices && v <= vertices) {
                addEdge(u - 1, v - 1, weight); // Вершины сдвигаются для индексации от 0
            }
            else {
                cout << "Некорректный ввод. Попробуйте снова.\n";
            }
        }
    }

    // Установить граф из варианта задания
    void setExampleGraph() {
        vertices = 6;
        visited.resize(vertices, 0);
        adjMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));

        addEdge(0, 1, 8);
        addEdge(0, 2, 4);
        addEdge(1, 3, 6);
        addEdge(1, 4, 3);
        addEdge(2, 1, 3);
        addEdge(2, 3, 2);
        addEdge(2, 5, 10);
        addEdge(3, 4, 3);
        addEdge(3, 5, 1);
        addEdge(4, 5, 4);
    }
};
