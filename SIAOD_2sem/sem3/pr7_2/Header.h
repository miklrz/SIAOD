#include <iostream>
#include <vector>
#include <limits>
#include <iomanip> // ��� �������������� ������
using namespace std;

// ���� ����������� �������� ���������
class Graph {
private:
    int vertices; // ���������� ������
    vector<vector<int>> adjMatrix; // ������� ���������
    vector<int> visited; // ���������� �������
    int minDistance;

    // ����������� ����� ������ ����������� ����
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

        visited[current] = 0; // ����� ��� ���������� ����
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
        cout << "������� ���������:\n";

        // ������ ��������� � �������� ��������
        cout << setw(4) << " "; // ������ ��� ��������� �����
        for (int i = 0; i < vertices; ++i) {
            cout << setw(4) << (i + 1);
        }
        cout << endl;

        // ������ ����� �������
        for (int i = 0; i < vertices; ++i) {
            cout << setw(4) << (i + 1); // ����� ������
            for (int j = 0; j < vertices; ++j) {
                cout << setw(4) << (adjMatrix[i][j] ? adjMatrix[i][j] : 0);
            }
            cout << endl;
        }
    }
};
