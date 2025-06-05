#include "VectorTasks.h"
#include "PrintFunction.h"

void VectorTasks(const std::vector<int>& numbers, int n) {
    // A Подсчет количества вхождений n и нахождение их позиций
    int count = std::count(numbers.begin(), numbers.end(), n);
    std::cout << "Число " << n << " появляется " << count << " раз.\n";
    std::cout << "Позиция: ";
    auto it = numbers.begin();
    while ((it = std::find(it, numbers.end(), n)) != numbers.end()) {
        std::cout << std::distance(numbers.begin(), it) << " ";
        ++it;
    }
    std::cout << "\n";

    // B Подсчитывание четных чисел и их расположение
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Количество четных чисел: " << evenCount << "\n";
    std::cout << "Позиция: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    // Суммирование
    if (evenCount > numbers.size() - evenCount) {
        int sumEven = std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int x) { return x % 2 == 0 ? acc + x : acc; });
        std::cout << "Сумма четных чисел: " << sumEven << "\n";
    }
    else {
        int sumAll = std::accumulate(numbers.begin(), numbers.end(), 0);
        std::cout << "Сумма всех чисел: " << sumAll << "\n";
    }

    // C Сортировка и вывод
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    std::cout << "Оригинальный вектор: ";
    Print(numbers, " ");
    std::cout << "Отсортированный вектор: ";
    Print(sortedNumbers, " ");

    // D Перестановка местами первого и последнего элемента.
    std::vector<int> swappedNumbers = numbers;
    std::swap(swappedNumbers.front(), swappedNumbers.back());
    std::cout << "Переставленный вектор: ";
    Print(swappedNumbers, " ");
}