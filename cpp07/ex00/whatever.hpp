#pragma once

template <typename T>
void swap(T& v1, T& v2) {
    T tmp = v1;
    v1 = v2;
    v2 = tmp;
}

template <typename T>
T const& min(T const &v1, T const &v2) {

    if (v2 <= v1)
        return v2;
    else
        return v1;
}

template <typename T>
T const& max(T const &v1, T const &v2) {

    if (v2 >= v1)
        return v2;
    else
        return v1;
}