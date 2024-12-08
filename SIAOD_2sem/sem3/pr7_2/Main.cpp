#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    // �������� ������� �����
    cout << "��������� ��� ������ � �������.\n";

    // ����� �����
    cout << "�������� ������ ������� �����:\n";
    cout << "1. ������������ ���� �� �������.\n";
    cout << "2. ������ ���� �������.\n";
    int choice;
    cin >> choice;

    Graph graph(0);

    if (choice == 1) {
        graph.setExampleGraph();
        cout << "���� �� ������� ������� ��������.\n";
    }
    else if (choice == 2) {
        graph.inputGraph();
    }
    else {
        cout << "������������ �����. ���������� ���������.\n";
        return 1;
    }

    // ����������� �����
    graph.displayGraph();

    // ���� ��������� � �������� ������
    int start, end;
    cout << "������� ��������� �������: ";
    cin >> start;
    cout << "������� �������� �������: ";
    cin >> end;

    // ���������� ����������� ����
    int shortestPath = graph.findShortestPath(start - 1, end - 1);

    // ����� ����������
    cout << "���������� ���� �� ������� " << start << " � ������� " << end << ": " << shortestPath << endl;

    return 0;
}