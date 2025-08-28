#pragma once

#include <cstddef> // for size_t
#include <iostream>
#include <string>

// template <typename T>
// void iter (T *array, std::size_t length, void (*func)(T &)){
//     if (!array || !func)
//         return;
//     for (std::size_t i = 0; i < length; ++i)
//         func(array[i]);
// }

// template <typename T>
// void iter (T *array, std::size_t length, void (*func)(T const&)){
//     if (!array || !func)
//         return;
//     for (std::size_t i = 0; i < length; ++i)
//         func(array[i]);
// }

template <typename T, typename F>
void iter(T* array, std::size_t length, F f) {
    if (!array) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}

// helper functions

template <typename T>
void print(T const& value) {
    std::cout << value << " ";
}

// generic add function
template <typename T>
void addOne(T& value) {
    value += 1;
}

// overload for std::string: add exclamation mark
inline void addExclamation(std::string& s) {
    s += "!";
}