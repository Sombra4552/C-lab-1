#include <iostream>
#include <limits>

int* deleteNegative(int arr[], int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            ++count;
        }
    }
    
    int* result = new int[count];
    
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            result[j] = arr[i];
            ++j;
        }
    }
    
    newSize = count;
    return result;
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
        std::cout << "Введите элемент массива" << (i + 1) << ": ";
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

    std::cout << "Удалить негатив\n\n";

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

    int newSize = 0;
    int* result = deleteNegative(arr, size, newSize);

    std::cout << "Массив без отрицательных: ";
    if (newSize == 0) {
        std::cout << "[]\n";
    } else {
        printArray(result, newSize);
    }

    delete[] arr;
    delete[] result;
    return 0;
}