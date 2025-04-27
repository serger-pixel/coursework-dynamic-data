#pragma once
#include <queue>
#include <string>

class SetOnPriorityQueue {
private:
    std::priority_queue<int> _setPriorityQueue; 

public:
    SetOnPriorityQueue(); 
    SetOnPriorityQueue(int cnt); 
    ~SetOnPriorityQueue(); 

    bool isEmpty(); 
    bool contains(int value); 
    void add(int value); 
    int size(); 

    bool isSubsetOf(SetOnPriorityQueue other); 
    std::string toString(std::string sep); 
    bool equals(SetOnPriorityQueue other); 
    SetOnPriorityQueue unionWith(SetOnPriorityQueue other); 
    SetOnPriorityQueue intersectWith(SetOnPriorityQueue other); 
    SetOnPriorityQueue difference(SetOnPriorityQueue other); 
    SetOnPriorityQueue symmetricDifference(SetOnPriorityQueue other); 
};