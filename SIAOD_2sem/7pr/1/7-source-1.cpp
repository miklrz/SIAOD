#include "7-header-1.h"

int main() {
	setlocale(LC_ALL, "rus");
	LinkedList lst;
	createList(&lst,5);

	insertSums(&lst);
	printList(&lst);
}