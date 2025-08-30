#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <limits>

class Span {
public:
    // only "meaningful" constructor: MUST specify the capacity N.
    explicit Span(unsigned int capacity);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int value);

    template <typename It>
    void addRange(It first, It last) {
        const std::size_t count = static_cast<std::size_t>(std::distance(first, last));
        // check 4 overflow
        if (count > m_capacity || m_values.size() > m_capacity - count)
            throw std::length_error("Span capacity exceeded");
        m_values.insert(m_values.end(), first, last);
    }

    // or: iterator range overload (remove addRange and keep only addNumber)

    // template <typename It>
    // void addNumber(It first, It last) {
    //     // Variant A: safe for input iterators (inserts one by one)
    //     std::size_t used = m_values.size();
    //     const std::size_t cap = static_cast<std::size_t>(m_capacity);
    //     for (; first != last; ++first) {
    //         if (used >= cap) throw std::length_error("Span capacity exceeded");
    //         m_values.push_back(*first);
    //         ++used;
    //     }

    unsigned int shortestSpan() const;
    unsigned int longestSpan()  const;

    unsigned int capacity() const {
        return m_capacity;
    }
    std::size_t  size() const {
        return m_values.size();
    }

private:
    Span();

    unsigned int   m_capacity;
    std::vector<int> m_values;
};

#endif
