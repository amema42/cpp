#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// test by subject
static void runSubjectSample() {
    std::cout << "subject tests\n";
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan()  << "\n";
    std::cout << "\n";
}

//range add (addRange)
static void runAddRangeTest() {
    std::cout << "addRange tests w. std::vector\n";

    // some values in a std::container
    std::vector<int> extra;
    for (int i = 0; i < 8; ++i) extra.push_back(i * 10);

    Span sp(8);
    sp.addRange(extra.begin(), extra.end());

    std::cout << "shortestSpan = " << sp.shortestSpan() << "\n";
    std::cout << "longestSpan  = " << sp.longestSpan()  << "\n";
    std::cout << "\n";
}

//some big n test
static void runBigTest() {
    std::cout << "some Big test: 10,000+ random values\n";

    const int N = 10000;
    std::vector<int> bigData; bigData.reserve(N);

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < N; ++i) bigData.push_back(std::rand());

    Span sp(N);
    sp.addRange(bigData.begin(), bigData.end());

    std::cout << "shortestSpan = " << sp.shortestSpan() << "\n";
    std::cout << "longestSpan  = " << sp.longestSpan()  << "\n";
    std::cout << "\n";
}

static void runErrorTests() {
    std::cout << "some: Error handling tests\n";

    // capacity overflow
    try {
        Span s(2);
        s.addNumber(1);
        s.addNumber(2);
        s.addNumber(3); // here should throw!
        std::cout << "ERROR: capacity overflow not detected\n";
    } catch (const std::exception& e) {
        std::cout << "capacity overflow -> " << e.what() << "\n";
    }

    // NOT enough elements for spans!
    try {
        Span s(5);
        s.addNumber(42);
        std::cout << s.shortestSpan() << "\n"; // here should throw!
    } catch (const std::exception& e) {
        std::cout << "not enough elements -> " << e.what() << "\n";
    }

    std::cout << "\n";
}

int main() {
    runSubjectSample();
    runAddRangeTest();
    runBigTest();
    runErrorTests();
    return 0;
}
