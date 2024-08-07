#include <iostream>
#include <vector>
#include <string>

class PrinterQueue {
private:
    std::vector<std::string> queue;

public:
    void add(const std::string& str) {
        queue.push_back(str);
    }

    void add(const std::string& str, int index) {
        if (index >= 0  <= queue.size()) {
            queue.insert(queue.begin() + index, str);
        }
        else {
            std::cout << "Нету такого индекса" << std::endl;
        }
    }

    void remove(int index) {
        if (index >= 0 && index < queue.size()) {
            queue.erase(queue.begin() + index);
        }
        else {
            std::cout << "Нету такого индекса" << std::endl;
        }
    }

    void print() {
        if (!queue.empty()) {
            std::cout << queue.front() << std::endl;
        }
        else {
            std::cout << "Нету элементов" << std::endl;
        }
    }

    void printQueue() {
        for (const auto& str : queue) {
            std::cout << str << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    PrinterQueue printer;

    printer.add("Строка 1");
    printer.add("Строка 2");
    printer.add("Строка 3");

    std::cout << "Очередь: " << std::endl;
    printer.printQueue();

    printer.print();

    printer.add("Строка 4", 3);

    std::cout << "Добавления строки в произвольное место: " << std::endl;
    printer.printQueue();

    printer.remove(2);

    std::cout << "После удаления строки: " << std::endl;
    printer.printQueue();

    return 0;
}