#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    
    if (!btc.initialize("data.csv")) {
        std::cerr << "Error: could not load price database." << std::endl;
        return 1;
    }
    
    btc.processInput(argv[1]);
    
    return 0;
}