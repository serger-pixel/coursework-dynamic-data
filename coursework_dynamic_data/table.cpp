#include "table.h"

void table::drawHorizontalLine(int width) {
    for (int i = 0; i < width; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void table::printRow(Operations operation,
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
