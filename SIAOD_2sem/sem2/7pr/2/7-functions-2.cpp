#include "7-header-2.h"

void addNode(LinkedList* arr) {
	Node* node = new Node;
	cout << "Введите номер зачетной книжки нового узла: "; cin >> node->keyNumber;
	cout << "Введите группу нового узла: "; cin >> node->group;
	cout << "Введите дисциплину нового узла: "; cin >> node->subject;
	cout << "Введите оценку нового узла: "; cin >> node->grade;
	insertNode(arr, node);
	cout << endl;
}

void createList(LinkedList* arr, int n) {
	for (int i = 0; i < n; i++) {
		addNode(arr);
	}
}

void printList(LinkedList* arr) {
	Node* node = arr->firstNode;
	while (node != 0) {
		cout << "Number: " << node -> keyNumber << "\nGroup: " << node->group << "\nSubject : " << node->subject << "\nGrade : " << node->grade << "\n--------------\n";
		node = node->next;
	}
	cout << endl;
}

void insertNode(LinkedList* arr, Node* node) {
	node->next = arr->firstNode;
	if(arr->firstNode!=NULL)arr->firstNode->prev = node;
	arr->firstNode = node;
	if (arr->countNodes == 0) arr->lastNode = node;
	arr->countNodes++;
}


void insertBefore(LinkedList* arr, Node* insert) {
	Node* node = arr->firstNode;
	if (inList(arr, insert->keyNumber)) {
		while (node != 0) {
			if (insert->keyNumber == node->keyNumber) {
				node->prev->next = insert;
				insert->prev = node->prev;
				insert->next = node;
				node->prev = insert;
				arr->countNodes++;
				break;
			}
			node = node->next;
		}
	}
	else {
		while (node != 0) {
			if (insert->keyNumber < node->keyNumber) {
				node->prev->next = insert;
				insert->prev = node->prev;
				insert->next = node;
				node->prev = insert;
				arr->countNodes++;
				break;
			}
			node = node->next;
		}
	}
}



bool inList(LinkedList* arr, int keyNumber) {
	Node* node = arr->firstNode;
	while (node != 0) {
		if (node->keyNumber == keyNumber) return true;
		node = node->next;
	}
	return false;
}