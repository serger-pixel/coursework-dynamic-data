#pragma once
#pragma once
#include <unordered_set>

class SetOnUnorderedSet {
private:
    std::unordered_set<int> SetUnorderedSet; // Частное поле для хранения элементов

public:
    SetOnUnorderedSet(); // Конструктор по умолчанию
    SetOnUnorderedSet(int cnt); // Конструктор с указанием количества элементов

    bool isEmpty(); // Проверка на пустоту
    bool contains(int value); // Проверка наличия значения
    void add(int value); // Добавление значения
    int size(); // Возвращает количество элементов

    bool isSubsetOf(SetOnUnorderedSet other); // Проверка подмножества
    bool equals(SetOnUnorderedSet other); // Сравнение двух множеств
    SetOnUnorderedSet unionWith(SetOnUnorderedSet other); // Объединение
    SetOnUnorderedSet intersectWith(SetOnUnorderedSet other); // Пересечение
    SetOnUnorderedSet difference(SetOnUnorderedSet other); // Разность
    SetOnUnorderedSet operation(SetOnUnorderedSet other); // Обобщенная операция
};