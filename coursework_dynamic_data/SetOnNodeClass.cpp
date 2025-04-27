#include "SetOnNodeClass.h"


//Конктруктор
SetOnNodeClass::SetOnNodeClass() : head(nullptr) {};

// Создание непустого множества 
SetOnNodeClass::SetOnNodeClass(int cnt) {
    head = nullptr;
    int localMax = cnt;
    int localMin = 0;
    for (int i = 0; i < cnt; ++i) {
        Node* temp = head;
        int value = (localMin + (std::rand() % (localMax - localMin + 1)));
        add(value);
        while (temp == head) {
            value = (localMin + (std::rand() % (localMax - localMin + 1)));
            add(value);
        }
    }
}

//Деструктор
SetOnNodeClass::~SetOnNodeClass() {
    while (isEmpty()) {
        Node* temp = head->_next;
        delete head;
        head = temp;
    }
}

// Проверка на пустоту
bool SetOnNodeClass::isEmpty() {
    return head == nullptr;
}

// Проверка принадлежности элемента
bool SetOnNodeClass::contains(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->_value == value) {
            return true;
        }
        current = current->_next;
    }
    return false;
}

// Добавление элемента
void SetOnNodeClass::add(int value) {
    if (!contains(value)) {
        head = new Node(value, head);
    }
}



// Определение мощности множества
int SetOnNodeClass::size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        ++count;
        current = current->_next;
    }
    return count;
}

// Вывод множества в виде строки
std::string SetOnNodeClass::toString(std::string sep) {
    if (isEmpty()) {
        return "Множество пустое";
    }
    std::string result;
    Node* current = head;
    while (current != nullptr) {
        result += std::to_string(current->_value) + sep;
        current = current->_next;
    }
    result.pop_back();
    return result;
}

// Проверка: является ли текущее множество подмножеством другого
bool SetOnNodeClass::isSubsetOf(SetOnNodeClass other) {
    Node* current = head;
    while (current != nullptr) {
        if (!other.contains(current->_value)) {
            return false;
        }
        current = current->_next;
    }
    return true;
}

// Проверка на равенство множеств
bool SetOnNodeClass::equals(SetOnNodeClass other) {
    return isSubsetOf(other) && other.isSubsetOf(*this);
}

// Объединение множеств
SetOnNodeClass SetOnNodeClass::unionWith(SetOnNodeClass other) {
    SetOnNodeClass result = SetOnNodeClass();
    Node* current = other.head;
    while (current != nullptr) {
        result.add(current->_value);
        current = current->_next;
    }

    current = this->head;
    while (current != nullptr) {
        result.add(current->_value);
        current = current->_next;
    }


    return result;
}

// Пересечение множеств
SetOnNodeClass SetOnNodeClass::intersectWith(SetOnNodeClass other) {
    SetOnNodeClass result;
    Node* current = head;
    while (current != nullptr) {
        if (other.contains(current->_value)) {
            result.add(current->_value);
        }
        current = current->_next;
    }
    return result;
}

// Разность множеств
SetOnNodeClass SetOnNodeClass::difference(SetOnNodeClass other) {
    SetOnNodeClass result;
    Node* current = other.head;
    while (current != nullptr) {
        if (!contains(current->_value)) {
            result.add(current->_value);
        }
        current = current->_next;
    }
    return result;
}

// Симметричная разность
SetOnNodeClass SetOnNodeClass::symmetricDifference(SetOnNodeClass other) {
    return (unionWith(other)).difference(intersectWith(other));
}
