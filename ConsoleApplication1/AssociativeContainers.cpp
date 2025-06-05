#include "AssociativeContainers.h"

void CheckRepeatedNumbers(const std::vector<int>& numbers) {
    std::unordered_set<int> seen;
    for (int num : numbers) {
        if (seen.count(num)) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
            seen.insert(num);
        }
    }
}

std::set<char> FindCommonLetters(const std::vector<std::string>& words) {
    if (words.empty()) return {};

    std::set<char> commonLetters(words[0].begin(), words[0].end());

    for (const auto& word : words) {
        std::set<char> currentLetters(word.begin(), word.end());
        std::set<char> temp;
        std::set_intersection(
            commonLetters.begin(), commonLetters.end(),
            currentLetters.begin(), currentLetters.end(),
            std::inserter(temp, temp.begin())
        );
        commonLetters = temp;
        if (commonLetters.empty()) break;
    }

    return commonLetters;
}

void CountWordOccurrences(const std::vector<std::string>& words) {
    std::map<std::string, int> wordCount;
    for (const auto& word : words) {
        std::cout << ++wordCount[word] << "\n";
    }
}