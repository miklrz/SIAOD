#pragma once
#include <iostream>

using namespace std;

struct Node {
	int info;
	Node* next = NULL;
};

struct LinkedList {
	Node* firstNode = NULL;
	Node* lastNode = NULL;
	int countNodes = 0;
};

void addNode(LinkedList* arr);
void createList(LinkedList* arr, int n);
void printList(LinkedList* arr);

void createListFromTwo(LinkedList* L, LinkedList* L1, LinkedList* L2);
void deleteEvenIndexes(LinkedList* L);
void insertSums(LinkedList* L);

bool inList(LinkedList* arr, int info);
void insertNode(LinkedList* arr, Node* node);