#include <iostream>
#include <limits>

bool isUpperCase(char x) {
    return x >= 'A' && x <='Z'; 
}

int userInput() {
    char character = 0;

    while (true) {
        std::cout << "Введите символ: ";
        
        if (std::cin >> character) {
            return character;
        }
        
        std::cout << "Ошибка ввода. Введите корректный символ.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "\n";
    }
}

int main() {
    std::cout << "Проверка символа на заглавную букву.\n";
    
    int user_char = userInput();
    bool result = isUpperCase(user_char);

    std::cout << "Заглавная буква? Ответ:\n" << std::boolalpha << result << "\n";

    return 0;
}