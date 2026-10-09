#include <iostream>
#include <limits>
#include <iomanip>

double safeDiv(int x, int y) {
    if (y == 0) {
        return 0.0;
    }
    
    return static_cast<double>(x) / y;
}

int userInput() {
    int numb = 0;

    while (true) {
        std::cout << "Введите целое число: ";
        
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

    std::cout << "Безопасное деление\n";

    std::cout << "Ввод делимого x\n";
    int x = userInput();
    
    std::cout << "\n Ввод делителя y\n";
    int y = userInput();

    double result = safeDiv(x, y);

    
    if (y == 0) {
        std::cout << "Деление на ноль невозможно!\n";
    } else {
        std::cout << "Результат деления: " << std::fixed << std::setprecision(2) << result << "\n";
    }

    return 0;
}
