#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // std::out_of_range
#include <cstddef>   // size_t

template <typename T>
class Array {
private:
    T*             _data;
    unsigned int   _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _data(NULL), _size(n) {
        if (_size > 0)
            _data = new T[_size]();
    }

    Array(const Array& other) : _data(NULL), _size(other._size) {
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    // copy assignment: deep copy + strong exception safety
    Array& operator=(const Array& other) {
        if (this != &other) {
            T* newData = NULL;
            if (other._size > 0) {
                newData = new T[other._size];
                for (unsigned int i = 0; i < other._size; ++i)
                    newData[i] = other._data[i];
            }
            delete [] _data;
            _data = newData;
            _size = other._size;
        }
        return *this;
    }

    ~Array() { delete [] _data; }

    // operator[] w bound checking
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("index out of range");
        return _data[index];
    }

    // const version
    T const& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("index out of range");
        return _data[index];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif
