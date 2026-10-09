#include <iostream>
#include <string>
#include <limits>

std::string makeDecision(int x, int y) {
    if (x < y) {
        return std::to_string(x) + " < " + std::to_string(y);
    } else if (x > y) {
        return std::to_string(x) + " > " + std::to_string(y);
    } else {
        return std::to_string(x) + " == " + std::to_string(y);
    }
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

    std::cout << "Строка сравнения\n";

    std::cout << "Ввод первого числа x\n";
    int x = userInput();
    
    std::cout << "\nВвод второго числа y\n";
    int y = userInput();

    std::string result = makeDecision(x, y);

    std::cout << "Результат сравнения: " << result << "\n";

    return 0;
}