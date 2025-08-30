#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <algorithm>

class BitcoinExchange {
private:
    // std::map: auto-sorted keys, perfect for date range queries
    std::map<std::string, double> _priceDatabase;
    
    // parsing & validation utils
    bool loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    bool isLeapYear(int year) const;
    double parseValue(const std::string& valueStr) const;
    std::string trim(const std::string& str) const;
    
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    
    // main interface methods
    bool initialize(const std::string& databaseFile);
    void processInput(const std::string& inputFile);
    bool getExchangeRate(const std::string& date, double& outRate) const;
};

#endif