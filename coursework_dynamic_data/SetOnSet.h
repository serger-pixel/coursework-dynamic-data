#pragma once
#include <set>
#include <string>

class SetOnSet {
private:
    std::set<int> _set; 

public:
    SetOnSet(); 
    SetOnSet(int cnt); 
    ~SetOnSet(); 

    bool isEmpty(); 
    bool contains(int value); 
    void add(int value); 
    int size(); 

    bool isSubsetOf(SetOnSet other); 
    std::string toString(std::string sep); 
    bool equals(SetOnSet other); 
    SetOnSet unionWith(SetOnSet other); 
    SetOnSet intersectWith(SetOnSet other); 
    SetOnSet difference(SetOnSet other); 
    SetOnSet symmetricDifference(SetOnSet other); 
};