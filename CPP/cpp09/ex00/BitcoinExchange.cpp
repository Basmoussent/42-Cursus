#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dataFile) : _dataFile(dataFile) {
    loadExchangeRates();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates() {
    std::ifstream file(_dataFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open data file.");
    }

    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate);
        
        try {
            float rateValue = static_cast<float>(std::atof(rate.c_str()));
            _exchangeRates[date] = rateValue;
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid rate in data file: " << line << std::endl;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    try {
        int year = std::atoi(date.substr(0, 4).c_str());
        int month = std::atoi(date.substr(5, 2).c_str());
        int day = std::atoi(date.substr(8, 2).c_str());
        
        if (year < 2009 || year > 2024) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if ((isLeap && day > 29) || (!isLeap && day > 28)) return false;
        }
        
        return true;
    } catch (...) {
        return false;
    }
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    try {
        float val = static_cast<float>(std::atof(value.c_str()));
        return val >= 0 && val <= 1000;
    } catch (...) {
        return false;
    }
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin())
        return it->second;
    if (it == _exchangeRates.end() || it->first != date)
        --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, value;
        
        if (!std::getline(ss, date, '|') || !std::getline(ss, value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (!isValidValue(value)) {
            float val = static_cast<float>(std::atof(value.c_str()));
            if (val < 0) {
                std::cout << "Error: not a positive number." << std::endl;
            } else {
                std::cout << "Error: too large a number." << std::endl;
            }
            continue;
        }
        
        float rate = getExchangeRate(date);
        float result = static_cast<float>(std::atof(value.c_str())) * rate;
        
        std::cout << date << " => " << value << " = " << std::fixed 
                  << std::setprecision(2) << result << std::endl;
    }
} 