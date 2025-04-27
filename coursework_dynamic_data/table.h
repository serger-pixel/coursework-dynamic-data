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
		const std::string singleLinkedList,
		const std::string classList,
		const std::string vector,
		const std::string list,
		const std::string unorderedSet,
		const std::string prioritySet);
	static void drawHorizontalLine(int width);
};