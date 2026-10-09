#include <iostream>
#include <limits>
#include <cmath>

bool equalNum(int x) {
    x = std::abs(x);
    
    int last_digit = x % 10;
    x /= 10;

    while (x > 0) {
        int current_digit = x % 10;
        if (current_digit != last_digit) {
            return false;
        }
        x /= 10;
    }

    return true;
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
    }
}

int main() {
    std::cout << "Проверка числа на одинаковость цифр\n";

    int x = userInput();

    bool result = equalNum(x);

    std::cout << "\nЧисло: " << x << "\n";
    std::cout << "Все цифры одинаковы? Ответ:\n" << std::boolalpha << result << "\n";

    return 0;
}