#include "VectorTasks.h"
#include "PrintFunction.h"

void VectorTasks(const std::vector<int>& numbers, int n) {
    // A ������� ���������� ��������� n � ���������� �� �������
    int count = std::count(numbers.begin(), numbers.end(), n);
    std::cout << "����� " << n << " ���������� " << count << " ���.\n";
    std::cout << "�������: ";
    auto it = numbers.begin();
    while ((it = std::find(it, numbers.end(), n)) != numbers.end()) {
        std::cout << std::distance(numbers.begin(), it) << " ";
        ++it;
    }
    std::cout << "\n";

    // B ������������� ������ ����� � �� ������������
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; });
    std::cout << "���������� ������ �����: " << evenCount << "\n";
    std::cout << "�������: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    // ������������
    if (evenCount > numbers.size() - evenCount) {
        int sumEven = std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int x) { return x % 2 == 0 ? acc + x : acc; });
        std::cout << "����� ������ �����: " << sumEven << "\n";
    }
    else {
        int sumAll = std::accumulate(numbers.begin(), numbers.end(), 0);
        std::cout << "����� ���� �����: " << sumAll << "\n";
    }

    // C ���������� � �����
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    std::cout << "������������ ������: ";
    Print(numbers, " ");
    std::cout << "��������������� ������: ";
    Print(sortedNumbers, " ");

    // D ������������ ������� ������� � ���������� ��������.
    std::vector<int> swappedNumbers = numbers;
    std::swap(swappedNumbers.front(), swappedNumbers.back());
    std::cout << "�������������� ������: ";
    Print(swappedNumbers, " ");
}