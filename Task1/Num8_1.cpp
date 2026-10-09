#include <iostream>
#include <limits>

bool isDivisor(int x, int y) {
    bool x_divides_y = (x != 0) && (y % x == 0);
    bool y_divides_x = (y != 0) && (x % y == 0);
    
    return x_divides_y || y_divides_x;
}

int userInput() {
    int numb = 0;

    while (true) {
        std::cout << "Введите число: ";
        
        if (std::cin >> numb) {
            return numb;
        }
        
        std::cout << "Ошибка ввода. Введите корректное число.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "\n";
    }
}

int main() {
    std::cout << "Проверка делимости.\n";
    
    std::cout << "Ввод первого числа x.\n";
    int x = userInput();

    std::cout << "Ввод второго числа y.\n";
    int y = userInput();

    bool result = isDivisor(x, y);

    std::cout << "Делит ли одно число другое нацело? Ответ:\n" << std::boolalpha << result << "\n";

    return 0;
}