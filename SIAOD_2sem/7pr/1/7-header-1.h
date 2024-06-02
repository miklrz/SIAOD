#pragma once
#include <iostream>

using namespace std;

struct Node {
	int info;
	Node* next = NULL;
};

struct HeadNode {
	Node* firstNode = NULL;
	Node* lastNode = NULL;
	int countNodes = 0;
};

void insertNode(HeadNode* node);
void createNode(HeadNode* node);
void printList(HeadNode* node);