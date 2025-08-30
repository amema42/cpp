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
        if (m_values.size() + count > m_capacity)
            throw std::length_error("Span is full (addRange)");
        m_values.insert(m_values.end(), first, last);
    }

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
