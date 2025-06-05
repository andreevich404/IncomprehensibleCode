#include "PrintFunction.h"

template <typename Container>
void Print(const Container& container, const std::string& delimiter) {
    bool first = true;
    for (const auto& item : container) {
        if (!first) {
            std::cout << delimiter;
        }
        std::cout << item;
        first = false;
    }
    std::cout << "\n";
}

template <typename Iter>
void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it) {
        std::cout << *it << std::endl;
    }
}

template void Print<std::vector<int>>(const std::vector<int>&, const std::string&);
template void PrintResults<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);