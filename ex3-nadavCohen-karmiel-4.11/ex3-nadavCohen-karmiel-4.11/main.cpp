// main.cpp
#include <iostream>
#include "Utils.h"

int main() {
    int choice;

    do {
        std::cout << "Choose an option:\n";
        std::cout << "1. Reverse an array\n";
        std::cout << "2. Enter 10 numbers and reverse them\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int size;
            std::cout << "Enter the size of the array: ";
            std::cin >> size;

            int* arr = new int[size];
            std::cout << "Enter " << size << " integers:\n";
            for (int i = 0; i < size; i++) {
                std::cin >> arr[i];
            }

            reverse(arr, size);

            std::cout << "Reversed array: ";
            for (int i = 0; i < size; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;

            delete[] arr; // ????? ?????? ??????
            break;
        }
        case 2: {
            int* reversedArray = reverse10();

            std::cout << "Reversed input: ";
            for (int i = 0; i < 10; i++) {
                std::cout << reversedArray[i] << " ";
            }
            std::cout << std::endl;

            delete[] reversedArray; // ????? ?????? ??????
            break;
        }
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
