#pragma once
#include <list>

class SetOnList {
private:
    std::list<int> SetList; // Частное поле для хранения элементов

public:
    SetOnList(); // Конструктор по умолчанию
    SetOnList(int cnt); // Конструктор с указанием количества элементов

    bool isEmpty() ; // Проверка на пустоту
    bool contains(int value) ; // Проверка наличия значения
    void add(int value); // Добавление значения
    int size() ; // Возвращает количество элементов

    bool isSubsetOf( SetOnList other) ; // Проверка подмножества
    bool equals( SetOnList other) ; // Сравнение двух множеств
    SetOnList unionWith( SetOnList other) ; // Объединение
    SetOnList intersectWith( SetOnList other) ; // Пересечение
    SetOnList difference( SetOnList other) ; // Разность
    SetOnList operation( SetOnList other) ; // Обобщенная операция

};
