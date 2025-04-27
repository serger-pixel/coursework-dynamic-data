#include "SetOnPriorityQueue.h"
#include <sstream>
#include <unordered_set>

// Конструктор по умолчанию
SetOnPriorityQueue::SetOnPriorityQueue() {
    _setPriorityQueue = std::priority_queue<int>();
}

// Конструктор с указанием количества элементов
SetOnPriorityQueue::SetOnPriorityQueue(int cnt): SetOnPriorityQueue() {
    for (int i = 0; i < cnt; ++i) {
        int localMin = 0;
        int localMax = cnt;
        int value = (localMin + (std::rand() % (localMax - localMin + 1)));
        add(value);
        while (!contains(value)) {
            value = (localMin + (std::rand() % (localMax - localMin + 1)));
            add(value);
        }
    }
}

// Деструктор
SetOnPriorityQueue::~SetOnPriorityQueue() {
    while (!_setPriorityQueue.empty()) {
        _setPriorityQueue.pop();
    }
}

// Проверка на пустоту
bool SetOnPriorityQueue::isEmpty() {
    return _setPriorityQueue.empty();
}

// Проверка наличия значения
bool SetOnPriorityQueue::contains(int value) {
    std::priority_queue<int> copy = _setPriorityQueue; 
    while (!copy.empty()) {
        if (copy.top() == value) {
            return true;
        }
        copy.pop();
    }
    return false;
}

// Добавление значения
void SetOnPriorityQueue::add(int value) {
    if (!contains(value)) { 
        _setPriorityQueue.push(value);
    }
}

// Возвращает количество элементов
int SetOnPriorityQueue::size() {
    std::priority_queue<int> copy = _setPriorityQueue; 
    int count = 0;
    while (!copy.empty()) {
        copy.pop();
        ++count;
    }
    return count;
}

// Проверка подмножества
bool SetOnPriorityQueue::isSubsetOf(SetOnPriorityQueue other) {
    std::priority_queue<int> copy = _setPriorityQueue; 
    while (!copy.empty()) {
        if (!other.contains(copy.top())) {
            return false;
        }
        copy.pop();
    }
    return true;
}

// Приведение к строке
std::string SetOnPriorityQueue::toString(std::string sep) {
    if (isEmpty()) {
        return "Множество пустое";
    }
    std::string result;
    std::priority_queue<int> copy = _setPriorityQueue; 
    while (!copy.empty()) {
        result += std::to_string(copy.top()) + sep;
        copy.pop();
    }
    result.pop_back(); 
    return result;
}

// Сравнение двух множеств
bool SetOnPriorityQueue::equals(SetOnPriorityQueue other) {
    if (size() != other.size()) {
        return false;
    }
    return isSubsetOf(other) && other.isSubsetOf(*this);
}

// Объединение
SetOnPriorityQueue SetOnPriorityQueue::unionWith(SetOnPriorityQueue other) {
    SetOnPriorityQueue result;
    std::unordered_set<int> uniqueElements; 

    std::priority_queue<int> copy1 = _setPriorityQueue;
    while (!copy1.empty()) {
        uniqueElements.insert(copy1.top());
        copy1.pop();
    }

    std::priority_queue<int> copy2 = other._setPriorityQueue;
    while (!copy2.empty()) {
        uniqueElements.insert(copy2.top());
        copy2.pop();
    }

    for (const int& elem : uniqueElements) {
        result.add(elem);
    }
    return result;
}

// Пересечение
SetOnPriorityQueue SetOnPriorityQueue::intersectWith(SetOnPriorityQueue other) {
    SetOnPriorityQueue result;
    std::priority_queue<int> copy = _setPriorityQueue;

    while (!copy.empty()) {
        if (other.contains(copy.top())) {
            result.add(copy.top());
        }
        copy.pop();
    }
    return result;
}

// Разность
SetOnPriorityQueue SetOnPriorityQueue::difference(SetOnPriorityQueue other) {
    SetOnPriorityQueue result;
    std::priority_queue<int> copy = _setPriorityQueue;

    while (!copy.empty()) {
        if (!other.contains(copy.top())) {
            result.add(copy.top());
        }
        copy.pop();
    }
    return result;
}

// Симметричная разность
SetOnPriorityQueue SetOnPriorityQueue::symmetricDifference(SetOnPriorityQueue other) {
    return (unionWith(other)).difference(intersectWith(other));
}