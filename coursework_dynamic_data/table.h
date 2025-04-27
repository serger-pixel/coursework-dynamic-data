#pragma once
#include<string>
#include<iostream>
#include <iomanip>
#include <windows.h>

enum Operations {
	CREATE,
	SIZE,
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

	void printRow(Operations operation,
		const std::string& singleLinkedList,
		const std::string& classList,
		const std::string& vector,
		const std::string& list,
		const std::string& unorderedSet,
		const std::string& prioritySet);
	void drawHorizontalLine(int width);
};