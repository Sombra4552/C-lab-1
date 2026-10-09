#include <iostream>
#include <limits>

int pow(int x, int y) {
    if (y < 0) {
        return 0;
    }
    
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
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
    setlocale(LC_ALL, "Russian");

    std::cout << "Степень числа\n\n";

    std::cout << "Ввод основания x\n";
    int x = userInput();
    
    int y;
    std::cout << "\nВвод показателя степени y\n";
    while (true) {
        y = userInput();
        if (y >= 0) {
            break;
        }
        std::cout << "Ошибка: показатель степени должен быть неотрицательным.\n\n";
    }

    int result = pow(x, y);

    std::cout << "\nРезультат: " << x << " в степени " << y << " = " << result << "\n";

    return 0;
}