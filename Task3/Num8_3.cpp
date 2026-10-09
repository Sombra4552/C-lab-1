#include <iostream>
#include <limits>

void leftTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
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
    std::cout << "Левый треугольник\n\n";

    int height;
    std::cout << "Ввод высоты треугольника\n";
    while (true) {
        height = userInput();
        if (height > 0) {
            break;
        }
        std::cout << "Ошибка: высота должна быть положительным числом.\n\n";
    }

    std::cout << "\nРезультат:\n";
    leftTriangle(height);

    return 0;
}