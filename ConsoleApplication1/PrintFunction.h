#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename Container>
void Print(const Container& container, const std::string& delimiter);

template <typename Iter>
void PrintResults(Iter first, Iter last);