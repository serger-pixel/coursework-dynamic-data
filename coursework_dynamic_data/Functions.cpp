#include "Functions.h"


//¬ычисление времени операций дл€ класса
template <typename T>
void Functions::calculateTime(
	std::map<CollectionTypes, std::map<Operations, int>>& table, CollectionTypes type,
	T firstCollection, T secondCollection)
	{
		std::map<Operations, int> column;
		auto start = std::chrono::high_resolution_clock::now();
		T local = new T(firstCollection.size());
		column[CREATE] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.size();
		column[SIZE_SET] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.isSubsetOf(firstCollection);
		column[SUBSET_THIS] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.isSubsetOf(secondCollection);
		column[SUBSET_OTHER] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.equals(firstCollection);
		column[EQUALS_THIS] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.equals(secondCollection);
		column[EQUALS_OTHER] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.unionWith(secondCollection);
		column[UNION] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.intersectWith(secondCollection);
		column[INTERSECTION] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		firstCollection.difference(secondCollection);
		column[DIFFERENCE_FIRST_SECOND] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		secondCollection.difference(firstCollection);
		column[DIFFERENCE_SECOND_FIRST] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		secondCollection.symmetricDifference(firstCollection);
		column[SYMMETRIC_DIFFERENCE] = (std::chrono::high_resolution_clock::now() - start).count();
		table[type] = column;
	}
			

//¬ычисление времени дл€ структуры
void Functions::calculateTime(
	std::map<CollectionTypes, std::map<Operations, int>>& table, CollectionTypes type,
	Node* firstCollection, Node* secondCollection) {
		std::map<Operations, int> column;
		auto start = std::chrono::high_resolution_clock::now();
		Node* local = newSet();
		column[CREATE] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		size(firstCollection);
		column[SIZE_SET] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		isSubsetOf(firstCollection, firstCollection);
		column[SUBSET_THIS] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		isSubsetOf(firstCollection, secondCollection);
		column[SUBSET_OTHER] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		equals(firstCollection, firstCollection);
		column[EQUALS_THIS] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		equals(firstCollection, secondCollection);
		column[EQUALS_OTHER] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		unionOf(firstCollection, secondCollection);
		column[UNION] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		intersectOf(firstCollection, secondCollection);
		column[INTERSECTION] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		differenceOf(firstCollection, secondCollection);
		column[DIFFERENCE_FIRST_SECOND] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		differenceOf(secondCollection, firstCollection);
		column[DIFFERENCE_SECOND_FIRST] = (std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		symmetricDifference(firstCollection, secondCollection);
		column[SYMMETRIC_DIFFERENCE] = (std::chrono::high_resolution_clock::now() - start).count();
		table[type] = column;
}

 void Functions::printTable(int firstCnt, int secondCnt)
{
	 std::map<CollectionTypes, std::map<Operations, int>> firstTable;
	 calculateTime(firstTable, List, SetOnList(firstCnt), SetOnList(secondCnt));
	 calculateTime(firstTable, NodePtr, newSet(firstCnt), newSet(secondCnt));
	 calculateTime(firstTable, NodeClass, SetOnNodeClass(firstCnt), SetOnNodeClass(secondCnt));
	 calculateTime(firstTable, PrioriyQueue, SetOnPriorityQueue(firstCnt), SetOnPriorityQueue(secondCnt));
	 calculateTime(firstTable, PrioriyQueue, SetOnSet(firstCnt), SetOnSet(secondCnt));
	 calculateTime(firstTable, PrioriyQueue, SetOnUnorderedSet(firstCnt), SetOnUnorderedSet(secondCnt));
}
