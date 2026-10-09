#include <iostream>
#include <limits>

int findLast(int arr[], int size, int x) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int userInput(const std::string& prompt) {
    int numb = 0;

    while (true) {
        std::cout << prompt;
        
        if (std::cin >> numb) {
            return numb;
        }
        
        std::cout << "Ошибка ввода. Введите корректное целое число.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите элемент массива " << (i + 1) << ": ";
        arr[i] = userInput("");
    }
}

void printArray(int arr[], int size) {
    std::cout << "Массив: [";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "Поиск последнего значения в массиве\n\n";

    int size = 0;
    while (true) {
        size = userInput("Введите размер массива: ");
        if (size > 0) {
            break;
        }
        std::cout << "Ошибка: размер массива должен быть положительным числом.\n\n";
    }

    int* arr = new int[size];
    fillArray(arr, size);

    std::cout << "\n";
    printArray(arr, size);

    int x = userInput("\nВведите число для поиска: ");

    int result = findLast(arr, size, x);

    std::cout << "\n";
    if (result == -1) {
        std::cout << "Число " << x << " не найдено в массиве.\n";
    } else {
        std::cout << "Последнее вхождение числа " << x << " находится по индексу: " << result << "\n";
    }

    delete[] arr;
    return 0;
}
