#include "Algorithms.h"
#include "PrintFunction.h"

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t originalSize = v.size();
    v.reserve(2 * originalSize);
    for (size_t i = 0; i < originalSize; ++i) {
        v.push_back(v[i]);
    }
}

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;
    std::copy_if(
        data.begin(), data.end(),
        std::back_inserter(filtered),
        [](const T& x) { return x > 0; }
    );
    PrintResults(filtered.begin(), filtered.end());
}

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;

    Iter result = first;
    while (++first != last) {
        if (!(*result == *first)) {
            *(++result) = *first;
        }
    }
    return ++result;
}