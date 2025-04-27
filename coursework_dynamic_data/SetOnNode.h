#pragma once
#include <string>

struct Node {
	int value;
	Node* next;
};

Node* newSet();

Node* newSet(int cnt);

bool isEmpty(Node* ptr);

bool contains(Node* ptr, int value);

Node* add(Node* ptr, int value);

int size(Node* ptr);

std::string toString(Node* ptr, std::string sep);

Node* delSet(Node* ptr);

bool isSubsetOf(Node* A, Node* B);

bool equals(Node* B, Node* A);

Node* unionOf(Node* A, Node* B);

Node* intersectOf(Node* A, Node* B);

Node* differenceOf(Node* A, Node* B);

Node* symmetricDifference(Node* A, Node* B);