#include "5pr_header_1.h"


int main() {
	setlocale(LC_ALL, "rus");
	char* str = new char[100];
	char* sub_str = new char[100];
	char* inp_str = new char[100];
	int index;
	input_string(str);
	int choice = 1; 
	while (choice != 0) {
		cout << "�������� ����� ������:\n1. ������� ������\n2. ������� �����\n3. " <<
			"������� ���������\n4. ������� ���������\n5. ������� ������������� �����\n6. ������������ ������ �����\n7. �������� ���������\n0. ����� �� ���������\n��� �����: "; cin >> choice; cin.ignore();
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
			input_string(sub_str);
			remove_substr(str, sub_str);
		case(5):
			delete_same_words(str);
			break;
		case(6):
			create_num_arr(str);
			break;
		case(7):
			cout << "������� �����, ������� ������ ��������: "; 
			cin.getline(inp_str, 100);
			cout << "������� ������ ��� �������: ";
			cin >> index;
			cin.ignore();
			insert_substr(str, inp_str, index);
			break;
		case(0):
			cout << "����� �� ���������!" << endl;
		}
	}

}