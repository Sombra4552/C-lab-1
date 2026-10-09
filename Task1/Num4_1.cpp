#include <iostream>
#include <limits>

bool isPositive(int x) {
    return x > 0; 
}

int userInput() {
    int numb = 0;

    while (true) {
        std::cout << "Введите целое число: ";
        
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
    std::cout << "Проверка числа на положительность.\n";
    
    int user_num = userInput();
    bool result = isPositive(user_num);

    std::cout << "Результат тестирования:" << std::boolalpha << result << "\n";

    return 0;
}