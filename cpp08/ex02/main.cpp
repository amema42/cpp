// #include <iostream>
// #include "MutantStack.hpp"

// int main() {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;  // 17
//     mstack.pop();
//     std::cout << mstack.size() << std::endl; // 1

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     // [...]
//     mstack.push(0);

//     MutantStack<int>::iterator it  = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;
//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::stack<int> s(mstack); // copy into std::stack (subject required)
//     return 0;
// }

#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> ms;

    std::cout << "started from the bottom buuuuut actually... from the top cause it's a (mutant) stack\n";
    std::cout << "size=" << ms.size() << "\n\n";
    if (ms.empty())
        std::cout << "empty=yes"<<std::endl;

    std::cout << "push 5\n";
    ms.push(5);
    std::cout << "top=" << ms.top() << "  size=" << ms.size() << "\n";
    std::cout << "content [bottom->top]: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it;
        if (it + 1 != ms.end())
            std::cout << " ";
        else
            std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "push 17\n";
    ms.push(17);
    std::cout << "top=" << ms.top() << "  size=" << ms.size() << "\n";
    std::cout << "content [bottom->top]: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it;
        if (it + 1 != ms.end())
            std::cout << " ";
        else
            std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "pop\n";
    ms.pop();
    std::cout << "size=" << ms.size() << "\n";
    std::cout << "content [bottom->top]: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it;
        if (it + 1 != ms.end())
            std::cout << " ";
        else
            std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "push 3, then 5, then 737, then 0\n";
    ms.push(3);
    ms.push(5);
    ms.push(737);
    ms.push(0);
    std::cout << "top=" << ms.top() << "  size=" << ms.size() << "\n";
    std::cout << "content [bottom->top]: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it;
        if (it + 1 != ms.end())
            std::cout << " ";
        else
            std::cout << "\n";
    }

    std::cout << "\nthat's all folks!\n";
    return 0;
}
