#include "stdafx.h"
#include "Menu.h"
#include "Contains.h"
#include "Change.h"
#include "Matrix.h"
#include "Polynomial.h"
#include <limits>
#include <cstdlib> // ��� system()

using namespace std;

void LabMenu::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void LabMenu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

template <typename T>
T LabMenu::getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            clearInput();
            cout << "������ �����. ����������, ������� ���������� ��������.\n";
        }
        else {
            clearInput();
            return value;
        }
    }
}

void LabMenu::showMainMenu() {
    clearScreen();
    cout << "\n=== ������������ ������ 5: ��� �� �++ - ������� ===\n";
    cout << "1. ������� 1: ��������� ������� contains\n";
    cout << "2. ������� 2: ��������� ������� change\n";
    cout << "3. ������� 3: ��������� ����� Matrix\n";
    cout << "4. ������� 4: ��������� ����� Polynomial\n";
    cout << "0. �����\n";
    cout << "�������� �������: ";
}

void LabMenu::run() {
    while (true) {
        showMainMenu();
        int choice = getInput<int>("");

        switch (choice) {
        case 1:
            clearScreen();
            demoContains();
            cout << "\n������� Enter ��� �����������...";
            clearInput();
            break;
        case 2:
            clearScreen();
            demoChange();
            cout << "\n������� Enter ��� �����������...";
            clearInput();
            break;
        case 3:
            clearScreen();
            demoMatrix();
            cout << "\n������� Enter ��� �����������...";
            clearInput();
            break;
        case 4:
            clearScreen();
            demoPolynomial();
            cout << "\n������� Enter ��� �����������...";
            clearInput();
            break;
        case 0:
            return;
        default:
            cout << "�������� �����. ���������� �����.\n";
            clearInput();
        }
    }
}

// ����� ������������ ���������� ������
template int LabMenu::getInput<int>(const string&);
template double LabMenu::getInput<double>(const string&);
template string LabMenu::getInput<string>(const string&);