#pragma once
#include <unordered_set>
#include <string>

class SetOnUnorderedSet {
private:
    std::unordered_set<int> _setUnorderedSet; 

public:
    SetOnUnorderedSet(); 
    SetOnUnorderedSet(int cnt); 
    ~SetOnUnorderedSet(); 

    bool isEmpty(); 
    bool contains(int value); 
    void add(int value); 
    int size(); 

    bool isSubsetOf(SetOnUnorderedSet other); 
    std::string toString(std::string sep); 
    bool equals(SetOnUnorderedSet other); 
    SetOnUnorderedSet unionWith(SetOnUnorderedSet other); 
    SetOnUnorderedSet intersectWith(SetOnUnorderedSet other); 
    SetOnUnorderedSet difference(SetOnUnorderedSet other); 
    SetOnUnorderedSet symmetricDifference(SetOnUnorderedSet other); 
};