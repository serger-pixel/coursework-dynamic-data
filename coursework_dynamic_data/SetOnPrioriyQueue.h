#pragma once
#pragma once
#include <queue>

class SetOnPriorityQueue {
private:
    std::priority_queue<int> SetPriorityQueue; // Частное поле для хранения элементов

public:
    SetOnPriorityQueue(); // Конструктор по умолчанию
    SetOnPriorityQueue(int cnt); // Конструктор с указанием количества элементов

    bool isEmpty(); // Проверка на пустоту
    bool contains(int value); // Проверка наличия значения
    void add(int value); // Добавление значения
    int size(); // Возвращает количество элементов

    bool isSubsetOf(SetOnPriorityQueue other); // Проверка подмножества
    bool equals(SetOnPriorityQueue other); // Сравнение двух множеств
    SetOnPriorityQueue unionWith(SetOnPriorityQueue other); // Объединение
    SetOnPriorityQueue intersectWith(SetOnPriorityQueue other); // Пересечение
    SetOnPriorityQueue difference(SetOnPriorityQueue other); // Разность
    SetOnPriorityQueue operation(SetOnPriorityQueue other); // Обобщенная операция
};