#include <iostream>
#include <string>
#include <limits>

std::string age(int x) {
    int last_digit = x % 10;
    int last_two_digits = x % 100;
    
    std::string word;
    
    if (last_two_digits >= 11 && last_two_digits <= 14) {
        word = "лет";
    } else {
        switch (last_digit) {
            case 1:
                word = "год";
                break;
            case 2:
            case 3:
            case 4:
                word = "года";
                break;
            default:
                word = "лет";
                break;
        }
    }
    
    return std::to_string(x) + " " + word;
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
    std::cout << "Возраст\n";

    std::cout << "Ввод возраста\n";
    int x = userInput();

    std::string result = age(x);

    std::cout << "Результат: " << result << "\n";

    return 0;
}