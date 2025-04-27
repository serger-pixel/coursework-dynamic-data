#include "table.h"

void table::drawHorizontalLine(int width) {
    for (int i = 0; i < width; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void table::printRow(Operations operation,
    const int singleLinkedList,
    const int classList,
    const int vector,
    const int list,
    const int unorderedSet,
    const int prioritySet) {
        std::cout << "| " << std::setw(22) << std::left << operation;
        std::cout << " | " << std::setw(22) << std::left << singleLinkedList;
        std::cout << " | " << std::setw(22) << std::left << classList;
        std::cout << " | " << std::setw(22) << std::left << vector;
        std::cout << " | " << std::setw(22) << std::left << list;
        std::cout << " | " << std::setw(22) << std::left << unorderedSet;
        std::cout << " | " << std::setw(22) << std::left << prioritySet;
        std::cout << " |" << std::endl;
    };
