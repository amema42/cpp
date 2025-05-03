#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        char *s = argv[i];
        for (int j = 0; s[j] != '\0'; ++j) {
            char c = s[j];
            std::cout << static_cast<char>(std::toupper(c));
        }
        if (i + 1 < argc)
            std::cout << ' ';
    }
    std::cout << '\n';
    return 0;    
}