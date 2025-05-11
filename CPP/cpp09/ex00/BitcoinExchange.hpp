#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;
    std::string _dataFile;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const;
    float getExchangeRate(const std::string& date) const;
    void loadExchangeRates();

public:
    BitcoinExchange(const std::string& dataFile = "data.csv");
    ~BitcoinExchange();
    
    void processInputFile(const std::string& inputFile);
};

#endif 