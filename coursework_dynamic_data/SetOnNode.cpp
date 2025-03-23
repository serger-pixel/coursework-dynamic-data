#include "SetOnList.h"
#include <string>

// Создание пустого множества
Node* newSet() {
    return nullptr;
}

// Проверка на пустоту
bool isEmpty(Node* ptr) {
    return (ptr == nullptr);
}

// Проверка принадлежности элемента
bool contains(Node* ptr, int value) {
    while (ptr != nullptr) {
        if (ptr->value == value) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Добавление элемента
Node* add(Node* ptr, int value) {
    if (!contains(ptr, value)) {
        Node* newEl = new Node;
        newEl->value = value;
        newEl->next = ptr;
        return newEl;
    }
    return ptr;
}

// Создание не пустого множества
Node* newSet(int cnt) {
    Node* ptr = nullptr;
    for (int i = 0; i < cnt; ++i) {
        ptr = add(ptr, i);
    }
    return ptr;
}

// Определение мощности множества
int size(Node* ptr) {
    int cnt = 0;
    while (ptr != nullptr) {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

// Вывод множества
std::string toString(Node* ptr, std::string sep) {
    if (isEmpty(ptr)) {
        return "Множество пустое";
    }
    std::string result;
    while (ptr != nullptr) {
        result += std::to_string(ptr->value) + sep;
        ptr = ptr->next;
    }
    if (!result.empty()) {
        result.pop_back(); // Удаляем последний разделитель
    }
    return result;
}

// Удаление множества
Node* delSet(Node* ptr) {
    while (ptr != nullptr) {
        Node* temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    return nullptr;
}

// Проверка: А - подмножество B
bool isSubsetOf(Node* A, Node* B) {
    while (A != nullptr) {
        if (!contains(B, A->value)) {
            return false;
        }
        A = A->next;
    }
    return true;
}

// Равенство множеств
bool equals(Node* A, Node* B) {
    return (isSubsetOf(A, B) && isSubsetOf(B, A));
}

// Объединение множеств
Node* unionOf(Node* A, Node* B) {
    Node* res = nullptr;
    while (A != nullptr) {
        res = add(res, A->value);
        A = A->next;
    }
    while (B != nullptr) {
        res = add(res, B->value);
        B = B->next;
    }
    return res;
}

// Пересечение множеств
Node* intersectOf(Node* A, Node* B) {
    Node* res = nullptr;
    while (A != nullptr) {
        if (contains(B, A->value)) {
            res = add(res, A->value);
        }
        A = A->next;
    }
    return res;
}

// Разность множеств: B - A
Node* differenceOf(Node* A, Node* B) {
    Node* res = nullptr;
    while (B != nullptr) {
        if (!contains(A, B->value)) {
            res = add(res, B->value);
        }
        B = B->next;
    }
    return res;
}

// Симметричная разность
Node* symmetricDifference(Node* A, Node* B) {
    Node* unionRes = unionOf(A, B);
    Node* intersectRes = intersectOf(A, B);
    return differenceOf(unionRes, intersectRes);
}