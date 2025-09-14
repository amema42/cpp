#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>


PMerge::PMerge() : _vecTimeUs(0.0), _deqTimeUs(0.0) {}

PMerge::~PMerge() {}

bool PMerge::isAllDigits(const std::string& s) const {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (!std::isdigit(c)) return false;
    }
    return true;
}

bool PMerge::loadArgs(int argc, char** argv) {
    if (argc < 2) return false;

    _vec.clear();
    _deq.clear();

    for (int i = 1; i < argc; ++i) {
        std::string token = argv[i];

        if (!isAllDigits(token)) return false;

        char* end = 0;
        long v = std::strtol(token.c_str(), &end, 10);
        if (*end != '\0')
            return false;
        if (v <= 0)
            return false;
        if (v > INT_MAX)
            return false;

        int x = static_cast<int>(v);

        // reject duplicates
        if (std::find(_vec.begin(), _vec.end(), x) != _vec.end())
            return false;

        _vec.push_back(x);
        _deq.push_back(x);
    }

    _before = _vec; // keep original sequence for "Before:"
    return true;
}

// binary insert (keep ascending order)

void PMerge::binInsertVector(std::vector<int>& a, int value) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    a.insert(a.begin() + left, value);
}

void PMerge::binInsertDeque(std::deque<int>& a, int value) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    a.insert(a.begin() + left, value);
}

// "jacobsthal order builder" : builds the insertion order for indices 1..m-1.
std::vector<size_t> PMerge::buildJacobsthalOrder(size_t m) {
    std::vector<size_t> order;
    if (m <= 1)
        return order;

    // generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);  // J(0)
    jacobsthal.push_back(1);  // J(1)
    
    // generate Jacobsthal numbers until we exceed m-1
    while (true) {
        size_t next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
        if (next >= m) break;
    }

    // build insertion order based on Jacobsthal sequence
    // first, always insert index 1 (if m > 1)
    if (m > 1) {
        order.push_back(1);
    }
    
    // then, for each Jacobsthal interval, insert indices in descending order
    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i-1] < m; ++i) {
        // insert from min(jacobsthal[i], m-1) down to jacobsthal[i-1]+1 in descending order
        size_t start = std::min(jacobsthal[i], m - 1);
        size_t end = jacobsthal[i-1];
        for (size_t idx = start; idx > end && idx > 1; --idx) {
            order.push_back(idx);
        }
    }
    
    return order;
}

// ford–johnson (merge-insertion) — std::vector<int>
//  - pair input into (min,max)
//  - recursively sort MAX -> && this becomes the main chain
//  - insert MIN[0], then the other MINs in "Jacobsthal order"
//  - insert leftover (if the input size was odd)

void PMerge::sortVector(std::vector<int>& a) {
    if (a.size() <= 1) return;

    std::vector<int> mins;
    std::vector<int> maxs;
    mins.reserve(a.size() / 2);
    maxs.reserve(a.size() / 2);

    // pairing
    size_t i = 0;
    size_t n = a.size();
    while (i + 1 < n) {
        int x = a[i];
        int y = a[i + 1];
        if (x > y) { int tmp = x; x = y; y = tmp; }
        mins.push_back(x);
        maxs.push_back(y);
        i += 2;
    }

    bool hasExtra = (i < n);
    int extra = hasExtra ? a[i] : 0;

    sortVector(maxs);
    std::vector<int> chain = maxs; // already ascending

    // insert MINs
    if (!mins.empty()) {
        // insert first min
        binInsertVector(chain, mins[0]);
        // then insert remaining mins in Jacobsthal order
        std::vector<size_t> order = buildJacobsthalOrder(mins.size());
        for (size_t k = 0; k < order.size(); ++k) {
            size_t idx = order[k];
            if (idx < mins.size()) {
                binInsertVector(chain, mins[idx]);
            }
        }
    }

    // insert leftover
    if (hasExtra) {
        binInsertVector(chain, extra);
    }

    a.swap(chain);
}

// merge-insertion — std::deque<int>
void PMerge::sortDeque(std::deque<int>& a) {
    if (a.size() <= 1)
        return;

    std::deque<int> mins;
    std::deque<int> maxs;

    size_t i = 0;
    size_t n = a.size();
    while (i + 1 < n) {
        int x = a[i];
        int y = a[i + 1];
        if (x > y) { int tmp = x; x = y; y = tmp; }
        mins.push_back(x);
        maxs.push_back(y);
        i += 2;
    }

    bool hasExtra = (i < n);
    int extra = hasExtra ? a[i] : 0;

    // main chain: recursively sort MAX
    sortDeque(maxs);
    std::deque<int> chain = maxs;

    // insert MINs
    if (!mins.empty()) {
        binInsertDeque(chain, mins[0]);
        std::vector<size_t> order = buildJacobsthalOrder(mins.size());
        for (size_t k = 0; k < order.size(); ++k) {
            size_t idx = order[k];
            if (idx < mins.size()) {
                binInsertDeque(chain, mins[idx]);
            }
        }
    }

    if (hasExtra) {
        binInsertDeque(chain, extra);
    }

    a.swap(chain);
}

void PMerge::run() {
    clock_t t0, t1;

    t0 = clock();
    sortVector(_vec);
    t1 = clock();
    _vecTimeUs = (double)(t1 - t0) * 1e6 / CLOCKS_PER_SEC;

    t0 = clock();
    sortDeque(_deq);
    t1 = clock();
    _deqTimeUs = (double)(t1 - t0) * 1e6 / CLOCKS_PER_SEC;
}

void PMerge::show() const {
    std::cout << "Before:";
    for (size_t i = 0; i < _before.size(); ++i) std::cout << " " << _before[i];
    std::cout << std::endl;

    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << " " << _vec[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << _vecTimeUs << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << _deqTimeUs << " us" << std::endl;
}