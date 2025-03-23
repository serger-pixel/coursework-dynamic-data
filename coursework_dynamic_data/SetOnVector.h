#pragma once
#include <vector>
#include <string>

class SetOnVector {
private:
    std::vector<int> _setVector; // Частное поле для хранения элементов

public:
    SetOnVector(); // Конструктор по умолчанию
    SetOnVector(int cnt); // Конструктор с указанием количества элементов
    ~SetOnVector(); // Деструктор

    bool isEmpty(); // Проверка на пустоту
    bool contains(int value); // Проверка наличия значения
    void add(int value); // Добавление значения
    int size(); // Возвращает количество элементов

    bool isSubsetOf(SetOnVector other); // Проверка подмножества
    std::string toString(std::string sep); // Приведение к строке
    bool equals(SetOnVector other); // Сравнение двух множеств
    SetOnVector unionWith(SetOnVector other); // Объединение
    SetOnVector intersectWith(SetOnVector other); // Пересечение
    SetOnVector difference(SetOnVector other); // Разность
    SetOnVector symmetricDifference(SetOnVector other); // Симметричная разность
};