#include <iostream>
#include <cmath>
#include <limits>

int sumLastNums(int x) {
    x = std::abs(x);

    int the_last_digit = x % 10;

    int the_second_last_digit = (x / 10) % 10;

    return the_last_digit + the_second_last_digit;
}

int userInput() {
    int numb = 0;

    while (true) {
        std::cout << "Введите число больше 2х знаков: ";
        
        if (std::cin >> numb) {
            if (std::abs(numb) >= 10) {
                return numb;
            } else {
                std::cout << "Ой, кажется число слишком короткое. Попробуйте снова.\n";
            }
        } else {
            std::cout << "Ошибка ввода, введите, пожалуйста, корректное число.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "\n";
        }
    }
}

int main() {

    std::cout << "Сумма двух последних знаков числа.\n\n";
    
    int user_num = userInput();
    int result = sumLastNums(user_num);
    
    std::cout << "Сумма двух последних чисел: " << result << "\n";

    return 0;
}
