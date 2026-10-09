#include <iostream>
#include <limits>

bool sum3(int x, int y, int z) {
    if (x + y == z) {
        return true;
    }
    if (x + z == y) {
        return true;
    }
    if (y + z == x) {
        return true;
    }
    return false;
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
    std::cout << "Тройная сумма\n";

    std::cout << "Ввод первого числа x\n";
    int x = userInput();
    
    std::cout << "\nВвод второго числа y\n";
    int y = userInput();
    
    std::cout << "\nВвод третьего числа z\n";
    int z = userInput();

    bool result = sum3(x, y, z);

    std::cout << "Вы ввели: x = " << x << ", y = " << y << ", z = " << z << "\n";
    std::cout << "\nРезультат:\n";
    switch (result) {
        case true:
            std::cout << "true\n";
            break;
        case false:
            std::cout << "false\n";
            break;

    }

    return 0;
}