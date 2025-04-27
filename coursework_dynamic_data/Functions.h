#pragma once
#include <string>
#include <map>
#include <chrono>
#include "table.h"
#include "SetOnList.h"
#include "SetOnNode.h"
#include "SetOnNodeClass.h"
#include "SetOnPriorityQueue.h"
#include "SetOnSet.h"
#include "SetOnUnorderedSet.h"

enum CollectionTypes{
	List,
	NodePtr,
	NodeClass,
	PrioriyQueue,
	Set,
	UnorderedSet
};

class Functions {
public:
	template <typename T>
	static void calculateTime(
		std::map<CollectionTypes, std::map<Operations, int>>& table, CollectionTypes type,
		T firstCollection, T secondCollection);

	static void calculateTime(
		std::map<CollectionTypes, std::map<Operations, int>>& table, CollectionTypes type,
		Node* firstCollection, Node* secondCollection);

	static void printTable(int firstCnt, int secondCnt);
};




