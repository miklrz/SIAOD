#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int keyNumber;
	string group;
	string subject;
	int grade;
	Node* prev = NULL;
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
void insertNode(LinkedList* arr, Node* node);
void insertBefore(LinkedList* arr, Node* insert);

bool inList(LinkedList* arr, int keyNumber);