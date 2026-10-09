#include <iostream>
#include <limits>

void reverse(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        ++left;
        --right;
    }
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
    std::cout << "Реверс массива\n\n";

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

    std::cout << "\nИсходный ";
    printArray(arr, size);

    reverse(arr, size);

    std::cout << "После реверса ";
    printArray(arr, size);

    delete[] arr;
    return 0;
}