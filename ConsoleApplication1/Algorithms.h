#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
void Duplicate(std::vector<T>& v);

template <typename T>
void Process(const std::vector<T>& data);

template <typename Iter>
Iter Unique(Iter first, Iter last);

template void Duplicate<int>(std::vector<int>&);
template void Process<int>(const std::vector<int>&);
template std::vector<int>::iterator Unique<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);