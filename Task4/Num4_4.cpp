#include <iostream>
#include <limits>

int* add(int arr[], int size, int x, int pos) {
    int* newArr = new int[size + 1];
    
    for (int i = 0; i < pos; ++i) {
        newArr[i] = arr[i];
    }
    
    newArr[pos] = x;
    
    for (int i = pos; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }
    
    return newArr;
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
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Добавление элемента в массив\n\n";

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

    std::cout << "\nИсходный массив: ";
    printArray(arr, size);

    int x = userInput("\nВведите значение для вставки: ");
    
    int pos = 0;
    while (true) {
        pos = userInput("Введите позицию для вставки (от 0 до " + std::to_string(size) + "): ");
        if (pos >= 0 && pos <= size) {
            break;
        }
        std::cout << "Ошибка: позиция должна быть в диапазоне от 0 до " << size << ".\n\n";
    }

    int* newArr = add(arr, size, x, pos);

    std::cout << "\nРезультат: ";
    printArray(newArr, size + 1);

    delete[] arr;
    delete[] newArr;
    return 0;
}