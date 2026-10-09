#include <iostream>
#include <limits>

int* concat(int arr1[], int size1, int arr2[], int size2) {
    int* result = new int[size1 + size2];
    
    for (int i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }
    
    for (int i = 0; i < size2; ++i) {
        result[size1 + i] = arr2[i];
    }
    
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

int inputPositiveSize(const std::string& prompt) {
    int size = 0;
    while (true) {
        size = userInput(prompt);
        if (size > 0) {
            return size;
        }
        std::cout << "Ошибка: размер должен быть положительным числом.\n\n";
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
    std::cout << "]";
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Объединение двух массивов\n\n";

    std::cout << "Ввод первого массива\n";
    int size1 = inputPositiveSize("Введите размер первого массива: ");
    int* arr1 = new int[size1];
    fillArray(arr1, size1);

    std::cout << "\nВвод второго массива\n";
    int size2 = inputPositiveSize("Введите размер второго массива: ");
    int* arr2 = new int[size2];
    fillArray(arr2, size2);

    std::cout << "\nПервый массив: ";
    printArray(arr1, size1);
    std::cout << "\nВторой массив: ";
    printArray(arr2, size2);
    std::cout << "\n\n";

    int* result = concat(arr1, size1, arr2, size2);

    std::cout << "Результат объединения: ";
    printArray(result, size1 + size2);
    std::cout << "\n";

    delete[] arr1;
    delete[] arr2;
    delete[] result;

    return 0;
}