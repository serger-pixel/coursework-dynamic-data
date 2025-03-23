#pragma once
#include <string>


class SetOnNodeClass {
private:
    struct Node {
        int _value;
        Node* _next;

        Node(int value, Node* next = nullptr) : _value(value), _next(next) {}
    };

    Node* head;

public:
    SetOnNodeClass();

    SetOnNodeClass(int cnt);

    ~SetOnNodeClass();

    bool isEmpty();

    bool contains(int value);

    void add(int value);

    int size();

    std::string toString(std::string sep);

    bool isSubsetOf(SetOnNodeClass other);

    bool equals(SetOnNodeClass other);

    SetOnNodeClass intersectWith(SetOnNodeClass other);
    SetOnNodeClass unionWith(SetOnNodeClass other);
    SetOnNodeClass difference(SetOnNodeClass other);
    SetOnNodeClass symmetricDifference(SetOnNodeClass other);
}