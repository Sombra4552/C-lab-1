#include <iostream>
#include <limits>

int lastNumSum(int x, int y) {
    return std::abs(x % 10) + std::abs(y % 10);
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
    std::cout << "Многократный вызов: сумма послених цифр.\n";

    int result = 0;
    
    for (int i = 1; i <= 5; ++i) {
        std::cout << "--- Ввод числа №" << i << " ---\n";
        int current_number = userInput();

        if (i == 1) {
            result = current_number % 10;
            std::cout << "Начальное значение: " << result << "\n\n";
        } else {
            result = lastNumSum(result, current_number);
            std::cout << "Промежуточный результат: " << result << "\n\n";
        }
    }

    std::cout << "Итоговый результат:\n" << std::boolalpha << result << "\n";

    return 0;

}