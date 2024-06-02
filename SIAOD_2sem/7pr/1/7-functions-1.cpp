#include "7-header-1.h"

void addNode(LinkedList* arr) {
	Node* node = new Node;
	cout << "¬ведите данные нового узла: "; cin >> node->info;
	insertNode(arr, node);
}

void createList(LinkedList* arr, int n) {
	for (int i = 0; i < n; i++) {
		addNode(arr);
	}
}

void printList(LinkedList* arr) {
	Node* node = arr->firstNode;
	cout << "List:";
	while (node != 0) {
		cout << " " << node->info;
		node = node->next;
	}
	cout << endl;
}



void createListFromTwo(LinkedList* L, LinkedList* L1, LinkedList* L2) {
	Node* node1 = L1->firstNode;
	Node* node2 = L2->firstNode;
	while (node1 != 0) {
		if (!inList(L, node1->info)) {
			Node* newNode = new Node;
			newNode->info = node1->info;
			insertNode(L, newNode);
		}	
		node1 = node1->next;
	}
	while(node2 != 0) {
		if (!inList(L, node2->info)) {
			Node* newNode = new Node;
			newNode->info = node2->info;
			insertNode(L, newNode);
		}
		node2 = node2->next;
	}
}

void deleteEvenIndexes(LinkedList* L) {
	Node* current = L->firstNode;
	Node* prev = NULL;
	int index = 0;
	while (current != NULL) {
		if (index % 2 == 0) { 
			Node* nodeToDelete = current;
			if (prev == NULL) {
				L->firstNode = current->next;
				current = L->firstNode;
			}
			else {
				prev->next = current->next;
				current = current->next;
			}
			delete nodeToDelete;
			L->countNodes--;
		}
		else {
			prev = current;
			current = current->next;
		}
		index++;
	}
}

void insertSums(LinkedList* L) {
	if (L->firstNode == NULL || L->firstNode->next == NULL) return;
	Node* prev1 = L->firstNode;
	Node* prev2 = prev1->next;
	while (prev1 != NULL && prev2 != NULL) {
		Node* node = new Node;
		node->info = prev1->info + prev2->info;
		node->next = prev2->next;
		prev2->next = node;
		L->countNodes++;
		prev1 = node->next;
		if (prev1 != NULL) {
			prev2 = prev1->next;
		}
	}
}



bool inList(LinkedList* arr, int info) {
	Node* node = arr->firstNode;
	while (node != 0) {
		if (node->info == info) return true;
		node = node->next;
	}
	return false;
}

void insertNode(LinkedList* arr, Node* node) {
	node->next = arr->firstNode;
	arr->firstNode = node;
	if (arr->countNodes == 0) arr->lastNode = node;
	arr->countNodes++;
}