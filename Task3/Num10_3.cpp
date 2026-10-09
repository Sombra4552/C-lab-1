#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

void guessGame() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int secret = std::rand() % 10;
    int attempts = 0;
    int guess;

    while (true) {
        if (attempts == 0) {
            std::cout << "Введите число от 0 до 9: ";
        } else {
            std::cout << "Вы не угадали, введите число от 0 до 9: ";
        }

        if (!(std::cin >> guess)) {
            std::cout << "Ошибка ввода. Введите корректное целое число.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (guess < 0 || guess > 9) {
            std::cout << "Число должно быть в диапазоне от 0 до 9.\n\n";
            continue;
        }

        ++attempts;

        if (guess == secret) {
            std::cout << "Вы угадали!\n";
            break;
        }
    }

    std::cout << "Вы отгадали число за " << attempts << " попытк";
    if (attempts == 1) {
        std::cout << "у\n";
    } else if (attempts >= 2 && attempts <= 4) {
        std::cout << "и\n";
    } else {
        std::cout << "ок\n";
    }
}

int main() {
    std::cout << "Игра Угадайка\n\n";
    guessGame();

    return 0;
}