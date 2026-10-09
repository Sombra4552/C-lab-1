#include <iostream>
#include <string>
#include <limits>

std::string reverseListNums(int x) {
    std::string result = "";
    for (int i = x; i >= 0; --i) {
        result += std::to_string(i);
        if (i > 0) {
            result += " ";
        }
    }
    return result;
}

int userInput() {
    int numb = 0;

    while (true) {
        std::cout << "Введите неотрицательное целое число: ";
        
        if (std::cin >> numb) {
            if (numb >= 0) {
                return numb;
            }
            std::cout << "Ошибка: число должно быть неотрицательным.\n\n";
        } else {
            std::cout << "Ошибка ввода. Введите корректное целое число.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Числа наоборот\n";

    int x = userInput();

    std::string result = reverseListNums(x);

    std::cout << "Результат: " << result << "\n";

    return 0;
}
