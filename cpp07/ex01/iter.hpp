
#include <cstddef> // for size_t
#include <iostream>
#include <string>


template <typename T, typename F>
void iter(T* array, std::size_t length, F f) {
    if (!array) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}


template <typename T>
void print(T const& value) {
    std::cout << value << " ";
}

template <typename T>
void addOne(T& value) {
    value += 1;
}

inline void addExclamation(std::string& s) {
    s += "!";
}