#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <ctime>
#include <algorithm>


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
        if (*end != '\0') return false;
        if (v <= 0) return false;
        if (v > INT_MAX) return false;

        int x = static_cast<int>(v);

        if (std::find(_vec.begin(), _vec.end(), x) != _vec.end())
            return false;

        _vec.push_back(x);
        _deq.push_back(x);
    }

    _before = _vec; // print "before"
    return true;
}


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


void PMerge::insertionSortVector(std::vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        int key = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > key) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;
    }
}

void PMerge::insertionSortDeque(std::deque<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        int key = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > key) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;
    }
}

// build the order for indices 1..m-1. - sequence: J0=0, J1=1, Jn=Jn-1 + 2*Jn-2 -> 0,1,1,3,5,11,...
std::vector<size_t> PMerge::buildJacobsthalOrder(size_t m) {
    std::vector<size_t> order;
    if (m <= 1) return order;

    size_t j0 = 0; // J0
    size_t j1 = 1; // J1
    size_t j  = j1 + 2 * j0; // J2 (=1)

    while (j < m) {
        size_t start = j;
        size_t stop  = j1;
        size_t idx = start;
        while (idx > stop) {
            order.push_back(idx);
            --idx;
        }
        j0 = j1;
        j1 = j;
        j  = j1 + 2 * j0;
    }

    size_t idx2 = m - 1;
    while (idx2 > j1) {
        order.push_back(idx2);
        --idx2;
    }
    return order;
}

// simple merge-insertion + Jacobsthal order
void PMerge::sortVector(std::vector<int>& a) {
    if (a.size() <= 1) return;

    // 1. pairing (min, max)
    std::vector<int> mins;
    std::vector<int> maxs;
    mins.reserve(a.size() / 2);
    maxs.reserve(a.size() / 2);

    size_t i = 0;
    size_t n = a.size();
    while (i + 1 < n) {
        int x = a[i];
        int y = a[i + 1];
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        mins.push_back(x);
        maxs.push_back(y);
        i += 2;
    }

    bool hasExtra = false;
    int extra = 0;
    if (i < n) {
        hasExtra = true;
        extra = a[i];
    }

    // 2. sort the "max" values recursively
    if (maxs.size() > 1) {
        std::vector<int> tmp = maxs;
        sortVector(tmp);
        maxs.swap(tmp);
    }

    // 3. "initial chain" = sorted maxs
    std::vector<int> chain = maxs;

    // 4. Insert mins[0], then the others following Jacobsthal order
    if (!mins.empty()) {
        binInsertVector(chain, mins[0]);
        std::vector<size_t> order = buildJacobsthalOrder(mins.size());
        for (size_t k = 0; k < order.size(); ++k) {
            size_t idx = order[k];
            if (idx < mins.size()) {
                binInsertVector(chain, mins[idx]);
            }
        }
    }

    // 5. insert eventual extra element (last odd element)
    if (hasExtra) {
        binInsertVector(chain, extra);
    }

    a.swap(chain);
}


void PMerge::sortDeque(std::deque<int>& a) {
    if (a.size() <= 1) return;

    std::deque<int> mins;
    std::deque<int> maxs;

    size_t i = 0;
    size_t n = a.size();
    while (i + 1 < n) {
        int x = a[i];
        int y = a[i + 1];
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        mins.push_back(x);
        maxs.push_back(y);
        i += 2;
    }

    bool hasExtra = false;
    int extra = 0;
    if (i < n) {
        hasExtra = true;
        extra = a[i];
    }

    if (maxs.size() > 1) {
        std::deque<int> tmp = maxs;
        sortDeque(tmp);
        maxs.swap(tmp);
    }

    std::deque<int> chain = maxs;

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

// run / show utils

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
    std::cout << "before:";
    for (size_t i = 0; i < _before.size(); ++i) {
        std::cout << " " << _before[i];
    }
    std::cout << std::endl;

    std::cout << "after:";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << " " << _vec[i];
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << _vecTimeUs << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << _deqTimeUs << " us" << std::endl;
}
