#include "5_header_2.h"

int main() {
	setlocale(LC_ALL, "rus");
	string str;
	input_string(str);
	int choice = 1;
	while (choice != 0) {
		cout << "�������� ����� ������:\n1. ������� ������\n2. ������� �����\n3. " <<
			"������� ���������\n4. ������� ���������\n5. ������� ������������� �����\n6. ������������ ������ �����\n0. ����� �� ���������\n��� �����: "; cin >> choice;
		switch (choice) {
		case(1):
			output_string(str);
			break;
		case(2):
			output_words(str);
			break;
		case(3):
			output_substr(str);
			break;
		case(4):
			cin.ignore();
			int start, length;
			cout << "������� ������ ������ ��������� ���������: "; cin >> start;
			cout << "������� ����� ��������� ���������: "; cin >> length;
			remove_substr(str, start,length);
		case(5):
			delete_same_words(str);
			break;
		case(6):
			get_num_arr(str);
			break;
		case(0):
			cout << "����� �� ���������!" << endl;
		}
	}
}