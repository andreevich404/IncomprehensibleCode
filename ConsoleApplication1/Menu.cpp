#include "Menu.h"
#include "PrintFunction.h"
#include "AssociativeContainers.h"
#include "Algorithms.h"
#include "VectorTasks.h"

void ShowMenu() {
    std::cout << "Выберите задание для демонстрации:\n";
    std::cout << "1. Печать элементов контейнера\n";
    std::cout << "2. Проверка повторяющихся чисел\n";
    std::cout << "3. Поиск общих букв в словах\n";
    std::cout << "4. Подсчет повторений слов\n";
    std::cout << "5. Дублирование элементов вектора\n";
    std::cout << "6. Обработка положительных чисел\n";
    std::cout << "7. Уникальные элементы\n";
    std::cout << "8. Работа с вектором\n";
    std::cout << "0. Выход\n";
}

void ExecuteTask(int choice) {
    switch (choice) {
    case 1: {
        std::vector<int> data = { 1, 2, 3 };
        Print(data, ", ");
        break;
    }
    case 2: {
        std::vector<int> numbers = { 1, 2, 1, 2, 2, 1, 6 };
        CheckRepeatedNumbers(numbers);
        break;
    }
    case 3: {
        std::vector<std::string> words = { "apple", "peach" };
        auto commonLetters = FindCommonLetters(words);
        for (char c : commonLetters) {
            std::cout << c;
        }
        std::cout << "\n";
        break;
    }
    case 4: {
        std::vector<std::string> words = { "copy", "delta", "copy", "copy", "delta", "paste", "paste", "beta", "paste" };
        CountWordOccurrences(words);
        break;
    }
    case 5: {
        std::vector<int> v = { 1, 2, 3 };
        Duplicate(v);
        Print(v, " ");
        break;
    }
    case 6: {
        std::vector<int> data = { 1, -2, 3, -4, 5 };
        Process(data);
        break;
    }
    case 7: {
        std::vector<int> v = { 1, 1, 2, 2, 3, 3 };
        auto last = Unique(v.begin(), v.end());
        v.erase(last, v.end());
        Print(v, " ");
        break;
    }
    case 8: {
        std::vector<int> numbers = { 1, 2, 3, 4, 5, 2, 3 };
        int n;
        std::cout << "Введите число n: ";
        std::cin >> n;
        VectorTasks(numbers, n);
        break;
    }
    default:
        std::cout << "Неверный выбор.\n";
    }
}