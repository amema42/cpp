#include "Span.hpp"

Span::Span() : m_capacity(0), m_values() {}

Span::Span(unsigned int capacity)
: m_capacity(capacity), m_values()
{
    m_values.reserve(capacity); // reduce reallocations
}

Span::Span(const Span& other)
: m_capacity(other.m_capacity), m_values(other.m_values) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_capacity = other.m_capacity;
        m_values   = other.m_values;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (m_values.size() >= m_capacity)
        throw std::length_error("Span is full");
    m_values.push_back(value);
}

unsigned int Span::shortestSpan() const {
    if (m_values.size() < 2)
        throw std::logic_error("Not enough elements for a span");

    // Do not mutate internal state: work on a copy
    std::vector<int> sortedValues = m_values;
    std::sort(sortedValues.begin(), sortedValues.end());

    unsigned int minGap = std::numeric_limits<unsigned int>::max();
    for (std::size_t i = 1; i < sortedValues.size(); ++i) {
        // use 'long' to avoid overflow when subtracting extremes
        long diff = static_cast<long>(sortedValues[i]) - static_cast<long>(sortedValues[i - 1]);
        if (diff < 0) diff = -diff;
        if (static_cast<unsigned long>(diff) < minGap)
            minGap = static_cast<unsigned int>(diff);
    }
    return minGap;
}

unsigned int Span::longestSpan() const {
    if (m_values.size() < 2)
        throw std::logic_error("Not enough elements for a span");

    const int minValue = *std::min_element(m_values.begin(), m_values.end());
    const int maxValue = *std::max_element(m_values.begin(), m_values.end());

    long diff = static_cast<long>(maxValue) - static_cast<long>(minValue);
    if (diff < 0) diff = -diff;
    return static_cast<unsigned int>(diff);
}
