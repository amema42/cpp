#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PMerge {
public:
    PMerge();
    ~PMerge();

    bool loadArgs(int argc, char** argv);
    void run();
    void show() const;

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;
    std::vector<int> _before;
    double _vecTimeUs;
    double _deqTimeUs;

    // ford–johnson (merge-insertion) in-place implementations
    void sortVector(std::vector<int>& a);
    void sortDeque (std::deque<int>&  a);

    // binary insertion into a sorted sequence (ascending)
    void binInsertVector(std::vector<int>& a, int value);
    void binInsertDeque (std::deque<int>&  a, int value);

    // build Jacobsthal insertion order for indices 1..m-1
    std::vector<size_t> buildJacobsthalOrder(size_t m);

    // input validation
    bool isAllDigits(const std::string& s) const;
};

#endif
