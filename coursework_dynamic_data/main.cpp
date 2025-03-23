#include <iostream>
#include <iomanip> // Для std::setw и std::setfill

int main() {
    setlocale(LC_ALL, "");
    // Функция для отрисовки горизонтальной линии
    auto drawHorizontalLine = [](int width) {
        for (int i = 0; i < width; ++i) {
            std::cout << "-";
        }
        std::cout << std::endl;
        };

    // Функция для отрисовки строки таблицы
    auto printRow = [&](const std::string& operation,
        const std::string& singleLinkedList,
        const std::string& classList,
        const std::string& vector,
        const std::string& list,
        const std::string& unorderedSet,
        const std::string& prioritySet) {
            std::cout << "| " << std::setw(22) << std::left << operation;
            std::cout << " | " << std::setw(22) << std::left << singleLinkedList;
            std::cout << " | " << std::setw(22) << std::left << classList;
            std::cout << " | " << std::setw(22) << std::left << vector;
            std::cout << " | " << std::setw(22) << std::left << list;
            std::cout << " | " << std::setw(22) << std::left << unorderedSet;
            std::cout << " | " << std::setw(22) << std::left << prioritySet;
            std::cout << " |" << std::endl;
        };

    // Верхняя часть таблицы
    std::cout << "Введите размер первого множества (целое от 100 до 100000):" << std::endl;
    drawHorizontalLine(180);

    // Заголовок таблицы
    printRow("Операция", "Односвязный список", "Класс список", "Vector", "List", "unordered_set", "priority_set");
    drawHorizontalLine(180);

    // Тело таблицы
    printRow("Создание множества", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Мощность", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Подмножество A-A", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Подмножество B-A", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Равенство A-A", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Равенство B-A", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Объединение", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Пересечение", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Разность A-B", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Разность B-A", "", "", "", "", "", "");
    drawHorizontalLine(180);
    printRow("Симметричная разность", "", "", "", "", "", "");

    return 0;
}