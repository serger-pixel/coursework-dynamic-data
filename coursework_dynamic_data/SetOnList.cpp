#include "SetOnList.h"

// Конструктор по умолчанию
SetOnList::SetOnList() {
}

// Конструктор с указанием количества элементов
SetOnList::SetOnList(int cnt) {
    for (int i = 1; i <= cnt; ++i) {
        _setList.push_back(i);
    }
}

// Деструктор
SetOnList::~SetOnList() {
    _setList.~list();
}

// Проверка на пустоту
bool SetOnList::isEmpty() {
    return _setList.empty();
}

// Проверка наличия значения
bool SetOnList::contains(int value) {
    return std::find(_setList.begin(), _setList.end(), value) != _setList.end();
}

// Добавление значения
void SetOnList::add(int value) {
    if (!contains(value)) { 
        _setList.push_back(value);
    }
}

// Возвращает количество элементов
int SetOnList::size() {
    return _setList.size();
}

// Проверка подмножества
bool SetOnList::isSubsetOf(SetOnList other) {
    for (const int& elem : _setList) {
        if (!other.contains(elem)) {
            return false;
        }
    }
    return true;
}

// Приведение к строке
std::string SetOnList::toString(std::string sep) {
    if (isEmpty()) {
        return "Множество пустое";
    }
    std::string result;
    for (const int& elem : _setList) {
        result += std::to_string(elem) + sep;
    }
    result.pop_back(); 
    return result;
}

// Сравнение двух множеств
bool SetOnList::equals(SetOnList other) {
    if (_setList.size() != other.size()) {
        return false;
    }
    return isSubsetOf(other) && other.isSubsetOf(*this);
}

// Объединение
SetOnList SetOnList::unionWith(SetOnList other) {
    SetOnList result;
    for (const int& elem : _setList) {
        result.add(elem);
    }
    for (const int& elem : other._setList) {
        result.add(elem);
    }
    return result;
}

// Пересечение
SetOnList SetOnList::intersectWith(SetOnList other) {
    SetOnList result;
    for (const int& elem : _setList) {
        if (other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Разность
SetOnList SetOnList::difference(SetOnList other) {
    SetOnList result;
    for (const int& elem : _setList) {
        if (!other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Симметричная разность
SetOnList SetOnList::symmetricDifference(SetOnList other) {
    return (intersectWith(other)).difference(unionWith(other));
}