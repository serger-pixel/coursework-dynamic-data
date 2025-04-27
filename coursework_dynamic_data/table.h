#pragma once
#include<string>
#include<iostream>
#include <iomanip>
#include <windows.h>
#include "Functions.h"

enum Operations {
	CREATE,
	SIZE_SET,
	SUBSET_THIS,
	SUBSET_OTHER,
	EQUALS_THIS,
	EQUALS_OTHER,
	UNION,
	INTERSECTION,
	DIFFERENCE_FIRST_SECOND,
	DIFFERENCE_SECOND_FIRST,
	SYMMETRIC_DIFFERENCE

};

class table {
public:
	const int WIDTH_LINE = 180;

	static void printRow(Operations operation,
		const int singleLinkedList,
		const int classList,
		const int vector,
		const int list,
		const int unorderedSet,
		const int prioritySet);
	static void drawHorizontalLine(int width);
};