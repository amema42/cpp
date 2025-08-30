#include "BitcoinExchange.hpp"
#include <limits>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
    : _priceDatabase(other._priceDatabase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _priceDatabase = other._priceDatabase;
    }
    return *this;
}

// trim whitespace
std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// validate YYYY-MM-DD
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    std::string y = date.substr(0,4);
    std::string m = date.substr(5,2);
    std::string d = date.substr(8,2);

    for (size_t i=0;i<y.size();++i) if (!std::isdigit((unsigned char)y[i])) return false;
    for (size_t i=0;i<m.size();++i) if (!std::isdigit((unsigned char)m[i])) return false;
    for (size_t i=0;i<d.size();++i) if (!std::isdigit((unsigned char)d[i])) return false;

    int year  = std::atoi(y.c_str());
    int month = std::atoi(m.c_str());
    int day   = std::atoi(d.c_str());

    if (year < 2009)
        return false; // bitcoin genesis!

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1]) return false;

    return true;
}

double BitcoinExchange::parseValue(const std::string& valueStr) const {
    std::string s = trim(valueStr);
    char* endPtr = 0;
    double v = std::strtod(s.c_str(), &endPtr);

    // ensure full conversion
    if (endPtr == s.c_str() || *endPtr != '\0')
        throw std::invalid_argument("Invalid number format");

    // reject NaN/Inf
    if (v != v) // NaN check
        throw std::invalid_argument("NaN not allowed");
    if (v == std::numeric_limits<double>::infinity() ||
        v == -std::numeric_limits<double>::infinity())
        throw std::invalid_argument("Infinity not allowed");

    return v;
}

// load price database from CSV
bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    bool first = true;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (first) {
            first = false;
            std::string t = trim(line);
            if (t == "date,exchange_rate")
                continue; // skip header
            // else treat as data
        }

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, commaPos));
        std::string valueStr = trim(line.substr(commaPos + 1));

        if (!isValidDate(date))
            continue;

        try {
            double value = parseValue(valueStr);
            _priceDatabase[date] = value; // last entry wins
        } catch (...) {
            // skip malformed line
        }
    }

    file.close();
    return !_priceDatabase.empty();
}

// initialize database
bool BitcoinExchange::initialize(const std::string& databaseFile) {
    return loadDatabase(databaseFile);
}

// get exchange rate for specific date
bool BitcoinExchange::getExchangeRate(const std::string& date, double& outRate) const {
    if (_priceDatabase.empty()) return false;

    // lower_bound: first element >= date
    std::map<std::string, double>::const_iterator it = _priceDatabase.lower_bound(date);

    if (it == _priceDatabase.end()) {
        // date after last: use latest
        --it;
        outRate = it->second;
        return true;
    }
    if (it->first == date) {
        outRate = it->second;
        return true;
    }
    if (it == _priceDatabase.begin()) {
        // no previous date available
        return false;
    }
    --it;               // use closest earlier date
    outRate = it->second;
    return true;
}

// process input file
void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            std::string t = trim(line);
            if (t.find("date") != std::string::npos && t.find("value") != std::string::npos)
                continue; // skip header
        }

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl; // print full line
            continue;
        }

        double value = 0.0;
        try {
            value = parseValue(valueStr);
        } catch (...) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = 0.0;
        if (!getExchangeRate(date, rate)) {
            // date before first available
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double result = value * rate;
        // format output: integers cleanly, floats as-is
        std::cout << date << " => " << value;
        if (value == static_cast<int>(value) && value < 1000000) {
            std::cout << " = " << static_cast<int>(result) << std::endl;
        } else {
            std::cout << " = " << result << std::endl;
        }
    }

    file.close();
}
