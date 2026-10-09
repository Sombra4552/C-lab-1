#include <iostream>
#include <limits>

void printDays(int x) {
    if (x < 1 || x > 7) {
        std::cout << "это не день недели\n";
        return;
    }

    switch (x) {
        case 1: std::cout << "понедельник\n";
        case 2: std::cout << "вторник\n";
        case 3: std::cout << "среда\n";
        case 4: std::cout << "четверг\n";
        case 5: std::cout << "пятница\n";
        case 6: std::cout << "суббота\n";
        case 7: std::cout << "воскресенье\n";
    }
}

int userInput() {
    int numb = 0;

    while (true) {
        std::cout << "Введите номер дня недели (1-7): ";
        
        if (std::cin >> numb) {
            return numb;
        }
        
        std::cout << "Ошибка ввода. Введите корректное целое число.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }
}

int main() {
    std::cout << "Вывод дней недели\n";

    int day = userInput();

    printDays(day);

    return 0;
}