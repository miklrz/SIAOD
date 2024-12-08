#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    // Создание пустого графа
    cout << "Программа для работы с графами.\n";

    // Выбор графа
    cout << "Выберите способ задания графа:\n";
    cout << "1. Использовать граф из задания.\n";
    cout << "2. Ввести граф вручную.\n";
    int choice;
    cin >> choice;

    Graph graph(0);

    if (choice == 1) {
        graph.setExampleGraph();
        cout << "Граф из задания успешно загружен.\n";
    }
    else if (choice == 2) {
        graph.inputGraph();
    }
    else {
        cout << "Некорректный выбор. Завершение программы.\n";
        return 1;
    }

    // Отображение графа
    graph.displayGraph();

    // Ввод начальной и конечной вершин
    int start, end;
    cout << "Введите начальную вершину: ";
    cin >> start;
    cout << "Введите конечную вершину: ";
    cin >> end;

    // Нахождение кратчайшего пути
    int shortestPath = graph.findShortestPath(start - 1, end - 1);

    // Вывод результата
    cout << "Кратчайший путь из вершины " << start << " в вершину " << end << ": " << shortestPath << endl;

    return 0;
}