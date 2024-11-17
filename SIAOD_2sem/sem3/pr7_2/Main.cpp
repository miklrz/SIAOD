#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    // Количество вершин
    int vertices = 6;

    // Создание графа
    Graph graph(vertices);

    // Заполнение графа (из задания)
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

    // Отображение графа
    graph.displayGraph();

    // Нахождение кратчайшего пути
    int start = 0; // начальная вершина (1 в задании)
    int end = 5;   // конечная вершина (6 в задании)

    int shortestPath = graph.findShortestPath(start, end);

    // Вывод результата
    cout << "Кратчайший путь из вершины " << (start + 1) << " в вершину " << (end + 1) << ": " << shortestPath << endl;

    return 0;
}