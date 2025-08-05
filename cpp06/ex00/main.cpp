#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        // Easter egg per mostrare ASCII art
        if (argc == 2 && std::string(argv[1]) == "--art")
        {
            std::cout << "                                                          _.,:=-,,cccedbec." << std::endl;
            std::cout << "                             ,                 .e$P\"ud$$$$$$$$$$$$$$bc." << std::endl;
            std::cout << "                          `. ,              .d$$\":d$$$$$$$$$$$$$$$$$$$$b." << std::endl;
            std::cout << "                        ~-. ,uee$$$$$eu .,d$$P\",d$$$$$$$$$$$$$$$$$$$$$$$$L" << std::endl;
            std::cout << "                         .d$$$$$$$$$$$$$h`\",ue$$$$$$$$$$$$$$<$$$$$$$$$$$$$" << std::endl;
            std::cout << "                        d$$$$$$$$$$$$$$$$$c`$$$$$$$$$$$$$$$>d$$$$$$$$$$$F" << std::endl;
            std::cout << "                       ,$$$$$$$$$$$$$$$$$$$b.?$$$$$$$$$$$$$<$$$$$$$$$P\"" << std::endl;
            std::cout << "                 .,ze$$$$$$$$$$$$$$$$$$$$$uu$ $$$$$$$$$$$$F<$$$$$$P\"" << std::endl;
            std::cout << "         .ue=+==\"\"\",,\"?$$$$$$$??$$$$$$$$$$$$$b`$$$$$$$$$$$$>$$$$$F" << std::endl;
            std::cout << "       z=',ed$$$$$$$$$$$$$$$$F $6$$$$$$$$$$$$$.?$$$$$$$$$$$h<$$$$" << std::endl;
            std::cout << "    ,d\",$$$$$$$$$$$$$$$$$$$$$b$$$$$$$$$$$$$\",`$c\"$$$$$$$$$$$h<$$$," << std::endl;
            std::cout << "   zF,$$$$$$$$$$$$$$$$$$$\"$$$$$$F?$$$$$$$$$'  $$h'$$$$$$$$$$$$><$$" << std::endl;
            std::cout << "  dS$$$$$$$$$$$$$$$$$$$$$.$$$$$$$ r \"$$$$$$bud$$F $$$$$$$$$$$$$b$$h" << std::endl;
            std::cout << " d$$$$$$$$$$$$$$$$$$$$$$$b`$$$$$$b. u$$$$$$$$$c( <$$$$$$$$$$$$$$$$$h" << std::endl;
            std::cout << "J$$$$$$$$$$$$$$$$$$$$$$$$$h`$$$$$$$$$$$$$$$$$$$$$beu`\"?$$$$$$$$$$$$$L" << std::endl;
            std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$b``\"???$PF+==-,\"??$$$$$$$$$$b,?$$$$$$$$$$$" << std::endl;
            std::cout << "`$$$$$$$$$$$$$$$$$$$$$$$$$$$<$$$$buu$$$$$$$$$ cecececc,??b`$$$$$$$$$$" << std::endl;
            std::cout << "  \"?$$$$$$$$$$$$$$FJ$$$$$$$F<$$$$$$$$$$$$$$$$ $$$$$$$$$b$bud$$$$$$$$$" << std::endl;
            std::cout << "     '\"$$$$$$$$$$FJ$$$$$$$$'d$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$$$F" << std::endl;
            std::cout << "        3$$$$$$$Fd$$$$$$$$\",$$$$$$$$$$$\"$$$$F `$$$$$$$$$$$$$$$$$$$$$" << std::endl;
            std::cout << "        d$$$$$$$d$$$$$$$F.d$$$$$ $$$P\"=2$$$$    ?$$$$$$$$$$$$$$$$$$" << std::endl;
            std::cout << "      z$$$$$$$$$$3$$$P\",d$$$$$$F P\" =J$$$$$F     `?$$$$$$$$$$$$$P\"" << std::endl;
            std::cout << "    u$$$$$$$$$$$L$$\"   $$$$$$$$    `$6R?==?          \"\"??????\"" << std::endl;
            std::cout << "    $$$$$$$$$$$$$$     3$bec:/      '$$CCLL" << std::endl;
            std::cout << "     ?$$$$$$$$$$$$b.   =?$??$+     :d???$??b." << std::endl;
            std::cout << "        `\"\"\"\"\"\"\"\"\"\"\"   \"  \"\"''\"      '\"  \"`" << std::endl;
            return 0;
        }
        
        for(int i = 1; i < argc; i++){
            std::cout << "Testing: " << argv[i] << std::endl;
            ScalarConverter::convert(argv[i]);
            std::cout << "" << std::endl;
        }
        return 0;
    }
    else if (argc == 1) {
        std::cout << "--- TEST CHAR ---" << std::endl;
        std::cout << "Input: 'a'" << std::endl;
        ScalarConverter::convert("'a'");
        std::cout << std::endl;
    
        std::cout << "Input: '*'" << std::endl;
        ScalarConverter::convert("'*'");
        std::cout << std::endl;
    
    // Test 2: Interi
        std::cout << "--- TEST INT ---" << std::endl;
        std::cout << "Input: 0" << std::endl;
        ScalarConverter::convert("0");
        std::cout << std::endl;
    
        std::cout << "Input: 42" << std::endl;
        ScalarConverter::convert("42");
        std::cout << std::endl;
    
        std::cout << "Input: -42" << std::endl;
        ScalarConverter::convert("-42");
        std::cout << std::endl;
    
        std::cout << "Input: 127" << std::endl;
        ScalarConverter::convert("127");
        std::cout << std::endl;
    
    // Test 3: Float
        std::cout << "--- TEST FLOAT ---" << std::endl;
        std::cout << "Input: 42.0f" << std::endl;
        ScalarConverter::convert("42.0f");
        std::cout << std::endl;
    
        std::cout << "Input: -4.2f" << std::endl;
        ScalarConverter::convert("-4.2f");
        std::cout << std::endl;
    
        std::cout << "Input: 0.0f" << std::endl;
        ScalarConverter::convert("0.0f");
        std::cout << std::endl;
    
    // Test 4: Double
        std::cout << "--- TEST DOUBLE ---" << std::endl;
        std::cout << "Input: 42.0" << std::endl;
        ScalarConverter::convert("42.0");
        std::cout << std::endl;
    
        std::cout << "Input: -4.2" << std::endl;
        ScalarConverter::convert("-4.2");
        std::cout << std::endl;
    
    // Test 5: Pseudo-literals
        std::cout << "--- TEST PSEUDO-LITERALS ---" << std::endl;
        std::cout << "Input: nan" << std::endl;
        ScalarConverter::convert("nan");
        std::cout << std::endl;

        std::cout << "Input: nanf" << std::endl;
        ScalarConverter::convert("nanf");
        std::cout << std::endl;
    
        std::cout << "Input: +inf" << std::endl;
        ScalarConverter::convert("+inf");
        std::cout << std::endl;
    
        std::cout << "Input: -inf" << std::endl;
        ScalarConverter::convert("-inf");
        std::cout << std::endl;
    
        std::cout << "Input: +inff" << std::endl;
        ScalarConverter::convert("+inff");
        std::cout << std::endl;
    
        std::cout << "Input: -inff" << std::endl;
        ScalarConverter::convert("-inff");
        std::cout << std::endl;
    
        // Test 6: Input invalidi
        std::cout << "--- TEST INVALID INPUT ---" << std::endl;
        std::cout << "Input: abc" << std::endl;
        ScalarConverter::convert("abc");
        std::cout << std::endl;
    
        std::cout << "Input: 42.42.42" << std::endl;
        ScalarConverter::convert("42.42.42");
        std::cout << std::endl;
    
        std::cout << "Input: +" << std::endl;
        ScalarConverter::convert("+");
        std::cout << std::endl;
    
    // Test 7: Edge cases
        std::cout << "--- TEST EDGE CASES ---" << std::endl;
        std::cout << "Input: 2147483647 (INT_MAX)" << std::endl;
        ScalarConverter::convert("2147483647");
        std::cout << std::endl;
    
        std::cout << "Input: -2147483648 (INT_MIN)" << std::endl;
        ScalarConverter::convert("-2147483648");
        std::cout << std::endl;
    
        std::cout << "Input: 2147483648 (INT_MAX + 1)" << std::endl;
        ScalarConverter::convert("2147483648");
        std::cout << std::endl;
    }
    else {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cout << "You Dumbo!" << std::endl;
        std::cout << "Or run without arguments to see default tests." << std::endl;
        std::cout << "Try: " << argv[0] << " --art for a surprise Dumbo!" << std::endl;
    }
    return 0;
}