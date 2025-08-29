#include "iter.hpp"
#include <string>
#include <iostream>

int main() {
    {
        int a[] = {1, 2, 3, 4};
        ::iter(a, 4, ::print<int>); std::cout << "\n";
        ::iter(a, 4, ::addOne<int>);
        ::iter(a, 4, ::print<int>); std::cout << "\n";
    }
    {
        char c[] = {'a', 'b', 'c', 'd'};
        ::iter(c, 4, ::print<char>); std::cout << "\n";
        ::iter(c, 4, ::addOne<char>);
        ::iter(c, 4, ::print<char>); std::cout << "\n";
    }
    {
        std::string s[] = {"abc", "def", "ghi", "jkl"};
        ::iter(s, 4, ::print<std::string>); std::cout << "\n";
        //::iter(s, 4, ::add);  // overloading for std::string
        ::iter(s, 4, static_cast<void(*)(std::string&)>(&addOne));
        ::iter(s, 4, ::addExclamation);
        ::iter(s, 4, ::print<std::string>); std::cout << "\n";
    }
    {
        const int k[] = {10, 20, 30};
        ::iter(k, 3, ::print<int>);
        std::cout << "\n";
    }
    return 0;
}
