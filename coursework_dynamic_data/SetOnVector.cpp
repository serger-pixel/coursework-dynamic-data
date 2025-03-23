#include "SetOnVector.h"

// Конструктор по умолчанию
SetOnVector::SetOnVector() {
}

// Конструктор с указанием количества элементов
SetOnVector::SetOnVector(int cnt) {
    for (int i = 1; i <= cnt; ++i) {
        _setVector.push_back(i);
    }
}

// Деструктор
SetOnVector::~SetOnVector() {
    _setVector.~vector();
}

// Проверка на пустоту
bool SetOnVector::isEmpty() {
    return _setVector.empty();
}

// Проверка наличия значения
bool SetOnVector::contains(int value) {
    return std::find(_setVector.begin(), _setVector.end(), value) != _setVector.end();
}

// Добавление значения
void SetOnVector::add(int value) {
    if (!contains(value)) { 
        _setVector.push_back(value);
    }
}

// Возвращает количество элементов
int SetOnVector::size() {
    return _setVector.size();
}

// Проверка подмножества
bool SetOnVector::isSubsetOf(SetOnVector other) {
    for (const int& elem : _setVector) {
        if (!other.contains(elem)) {
            return false;
        }
    }
    return true;
}

// Приведение к строке
std::string SetOnVector::toString(std::string sep) {
    if (isEmpty()) {
        return "Множество пустое";
    }
    std::string result;
    for (const int& elem : _setVector) {
        result += std::to_string(elem) + sep;
    }
    result.pop_back();
    return result;
}

// Сравнение двух множеств
bool SetOnVector::equals(SetOnVector other) {
    if (_setVector.size() != other.size()) {
        return false;
    }
    return isSubsetOf(other) && other.isSubsetOf(*this);
}

// Объединение
SetOnVector SetOnVector::unionWith(SetOnVector other) {
    SetOnVector result;
    for (const int& elem : _setVector) {
        result.add(elem);
    }
    for (const int& elem : other._setVector) {
        result.add(elem);
    }
    return result;
}

// Пересечение
SetOnVector SetOnVector::intersectWith(SetOnVector other) {
    SetOnVector result;
    for (const int& elem : _setVector) {
        if (other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Разность
SetOnVector SetOnVector::difference(SetOnVector other) {
    SetOnVector result;
    for (const int& elem : _setVector) {
        if (!other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

// Симметричная разность
SetOnVector SetOnVector::symmetricDifference(SetOnVector other) {
    return (intersectWith(other)).difference(unionWith(other));
}