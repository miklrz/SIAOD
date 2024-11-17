#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    // ���������� ������
    int vertices = 6;

    // �������� �����
    Graph graph(vertices);

    // ���������� ����� (�� �������)
    graph.addEdge(0, 1, 8);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 3, 6);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 2);
    graph.addEdge(2, 1, 3);
    graph.addEdge(2, 5, 10);
    graph.addEdge(3, 4, 3);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 4);

    // ����������� �����
    graph.displayGraph();

    // ���������� ����������� ����
    int start = 0; // ��������� ������� (1 � �������)
    int end = 5;   // �������� ������� (6 � �������)

    int shortestPath = graph.findShortestPath(start, end);

    // ����� ����������
    cout << "���������� ���� �� ������� " << (start + 1) << " � ������� " << (end + 1) << ": " << shortestPath << endl;

    return 0;
}