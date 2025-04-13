#include "Menu.h"
#include "Complex.h"
#include "Rational.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void testComplexNumbers() {
    clearScreen();
    std::cout << "=== Complex Numbers ===" << std::endl;

    Complex c1, c2;

    std::cout << "Enter first complex number\n";
    std::cin >> c1;

    std::cout << "\nEnter second complex number\n";
    std::cin >> c2;

    std::cout << "\nYou entered:\n";
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n\n";

    std::cout << "c1 + c2 = " << (c1 + c2) << std::endl;
    std::cout << "c1 - c2 = " << (c1 - c2) << std::endl;
    std::cout << "c1 * c2 = " << (c1 * c2) << std::endl;

    try {
        std::cout << "c1 / c2 = " << (c1 / c2) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void testRationalNumbers() {
    clearScreen();
    std::cout << "=== Rational Numbers ===" << std::endl;

    Rational r1, r2;

    std::cout << "Enter first rational number (a/b or a): ";
    std::cin >> r1;

    std::cout << "Enter second rational number (a/b or a): ";
    std::cin >> r2;

    std::cout << "\nYou entered:\n";
    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n\n";

    std::cout << "r1 + r2 = " << (r1 + r2) << std::endl;
    std::cout << "r1 - r2 = " << (r1 - r2) << std::endl;
    std::cout << "r1 * r2 = " << (r1 * r2) << std::endl;

    try {
        std::cout << "r1 / r2 = " << (r1 / r2) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void showMenu() {
    int choice;
    do {
        clearScreen();
        std::cout << "=== Main Menu ===" << std::endl;
        std::cout << "1. Complex" << std::endl;
        std::cout << "2. Rational" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice (1-3): ";

        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1, 2 or 3: ";
        }

        switch (choice) {
        case 1:
            testComplexNumbers();
            break;
        case 2:
            testRationalNumbers();
            break;
        case 3:
            std::cout << "Exiting program..." << std::endl;
            return;
        }

    } while (choice != 3);
}