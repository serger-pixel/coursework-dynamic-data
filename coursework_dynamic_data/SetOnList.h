#pragma once
#include <list>
#include <string>

class SetOnList {
private:
    std::list<int> _setList;

public:
    SetOnList();
    SetOnList(int cnt);
    ~SetOnList();

    bool isEmpty();
    bool contains(int value);
    void add(int value);
    int size();

    bool isSubsetOf(SetOnList other);
    std::string toString(std::string sep);
    bool equals(SetOnList other);
    SetOnList unionWith(SetOnList other);
    SetOnList intersectWith(SetOnList other);
    SetOnList difference(SetOnList other);
    SetOnList symmetricDifference(SetOnList other);
};