#include "SetOnUnorderedSet.h"
#include <random>

// Конструктор по умолчанию
SetOnUnorderedSet::SetOnUnorderedSet() {
}

// Конструктор с указанием количества элементов
SetOnUnorderedSet::SetOnUnorderedSet(int cnt) {
    for (int i = 1; i <= cnt; ++i) {
        _setUnorderedSet.insert(i);
    }
}

// Деструктор
SetOnUnorderedSet::~SetOnUnorderedSet() {
    _setUnorderedSet.~unordered_set();
}

// Проверка на пустоту
bool SetOnUnorderedSet::isEmpty() {
    return _setUnorderedSet.empty();
}

// Проверка наличия значения
bool SetOnUnorderedSet::contains(int value) {
    return _setUnorderedSet.find(value) != _setUnorderedSet.end();
}

// Добавление значения
void SetOnUnorderedSet::add(int value) {
    _setUnorderedSet.insert(value);
}

// Возвращает количество элементов
int SetOnUnorderedSet::size() {
    return _setUnorderedSet.size();
}

// Проверка подмножества
bool SetOnUnorderedSet::isSubsetOf(SetOnUnorderedSet other) {
    for (const int& elem : _setUnorderedSet) {
        if (!other.contains(elem)) {
            return false;
        }
    }
    return true;
}

// Приведение к строке
std::string SetOnUnorderedSet::toString(std::string sep) {
    if (isEmpty()) {
        return "Множество пустое";
    }
    std::string result;
    for (const int& elem : _setUnorderedSet) {
        result += std::to_string(elem) + sep;
    }
    result.pop_back();
    return result;
}

// Сравнение двух множеств
bool SetOnUnorderedSet::equals(SetOnUnorderedSet other) {
    if (_setUnorderedSet.size() != other.size()) {
        return false;
    }
    return isSubsetOf(other) && other.isSubsetOf(*this);
}

// Объединение
SetOnUnorderedSet SetOnUnorderedSet::unionWith(SetOnUnorderedSet other) {
    SetOnUnorderedSet result;
    for (const int& elem : _setUnorderedSet) {
        result.add(elem);
    }
    for (const int& elem : other._setUnorderedSet) {
        result.add(elem);
    }
    return result;
}

// Пересечение
SetOnUnorderedSet SetOnUnorderedSet::intersectWith(SetOnUnorderedSet other) {
    SetOnUnorderedSet result;
    for (const int& elem : _setUnorderedSet) {
        if (other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Разность
SetOnUnorderedSet SetOnUnorderedSet::difference(SetOnUnorderedSet other) {
    SetOnUnorderedSet result;
    for (const int& elem : _setUnorderedSet) {
        if (!other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Симметричная разность
SetOnUnorderedSet SetOnUnorderedSet::symmetricDifference(SetOnUnorderedSet other) {
    return (intersectWith(other)).difference(unionWith(other));
}