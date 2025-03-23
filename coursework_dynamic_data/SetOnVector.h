#pragma once
#pragma once
#include <vector>

class SetOnVector {
private:
    std::vector<int> SetVector; // Частное поле для хранения элементов

public:
    SetOnVector(); // Конструктор по умолчанию
    SetOnVector(int cnt); // Конструктор с указанием количества элементов

    bool isEmpty(); // Проверка на пустоту
    bool contains(int value); // Проверка наличия значения
    void add(int value); // Добавление значения
    int size(); // Возвращает количество элементов

    bool isSubsetOf(SetOnVector other); // Проверка подмножества
    bool equals(SetOnVector other); // Сравнение двух множеств
    SetOnVector unionWith(SetOnVector other); // Объединение
    SetOnVector intersectWith(SetOnVector other); // Пересечение
    SetOnVector difference(SetOnVector other); // Разность
    SetOnVector operation(SetOnVector other); // Обобщенная операция
};