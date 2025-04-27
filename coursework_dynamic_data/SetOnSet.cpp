#include "SetOnSet.h"
#include <random>

// Конструктор по умолчанию
SetOnSet::SetOnSet() {
    _set = std::set<int>();
}

// Конструктор с указанием количества элементов
SetOnSet::SetOnSet(int cnt): SetOnSet() {
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
SetOnSet::~SetOnSet() {
    _set.clear();
}

// Проверка на пустоту
bool SetOnSet::isEmpty() {
    return _set.empty();
}

// Проверка наличия значения
bool SetOnSet::contains(int value) {
    return _set.find(value) != _set.end();
}

// Добавление значения
void SetOnSet::add(int value) {
    _set.insert(value);
}

// Возвращает количество элементов
int SetOnSet::size() {
    return _set.size();
}

// Проверка подмножества
bool SetOnSet::isSubsetOf(SetOnSet other) {
    for (const int& elem : _set) {
        if (!other.contains(elem)) {
            return false;
        }
    }
    return true;
}

// Приведение к строке
std::string SetOnSet::toString(std::string sep) {
    if (isEmpty()) {
        return "Множество пустое";
    }
    std::string result;
    for (const int& elem : _set) {
        result += std::to_string(elem) + sep;
    }
    result.pop_back();
    return result;
}

// Сравнение двух множеств
bool SetOnSet::equals(SetOnSet other) {
    if (_set.size() != other.size()) {
        return false;
    }
    return isSubsetOf(other) && other.isSubsetOf(*this);
}

// Объединение
SetOnSet SetOnSet::unionWith(SetOnSet other) {
    SetOnSet result;
    for (const int& elem : _set) {
        result.add(elem);
    }
    for (const int& elem : other._set) {
        result.add(elem);
    }
    return result;
}

// Пересечение
SetOnSet SetOnSet::intersectWith(SetOnSet other) {
    SetOnSet result;
    for (const int& elem : _set) {
        if (other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Разность
SetOnSet SetOnSet::difference(SetOnSet other) {
    SetOnSet result;
    for (const int& elem : _set) {
        if (!other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Симметричная разность
SetOnSet SetOnSet::symmetricDifference(SetOnSet other) {
    return (unionWith(other)).difference(intersectWith(other));
}