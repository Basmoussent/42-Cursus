#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isSpecialFloat(const std::string& literal) {
    return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

bool ScalarConverter::isSpecialDouble(const std::string& literal) {
    return literal == "nan" || literal == "+inf" || literal == "-inf";
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (isSpecialFloat(literal)) return true;
    if (literal.empty() || literal[literal.length() - 1] != 'f') return false;
    
    bool hasDecimal = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return hasDecimal;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (isSpecialDouble(literal)) return true;
    
    bool hasDecimal = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return hasDecimal;
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << f;
    if (f == static_cast<int>(f)) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d;
    if (d == static_cast<int>(d)) {
        std::cout << ".0";
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    if (isSpecialFloat(literal) || isSpecialDouble(literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (isSpecialFloat(literal)) {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        } else {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return;
    }

    if (isChar(literal)) {
        char c = literal[1];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isInt(literal)) {
        long long int_val = std::atoll(literal.c_str());
        if (int_val > std::numeric_limits<int>::max() || 
            int_val < std::numeric_limits<int>::min()) {
            std::cout << "Error: Integer overflow" << std::endl;
            return;
        }
        int i = static_cast<int>(int_val);
        if (i >= 0 && i <= 127) {
            printChar(static_cast<char>(i));
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
    else if (isFloat(literal)) {
        float f = std::atof(literal.c_str());
        if (f >= 0 && f <= 127 && !std::isnan(f) && !std::isinf(f)) {
            printChar(static_cast<char>(f));
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        if (!std::isnan(f) && !std::isinf(f) && 
            f >= std::numeric_limits<int>::min() && 
            f <= std::numeric_limits<int>::max()) {
            printInt(static_cast<int>(f));
        } else {
            std::cout << "int: impossible" << std::endl;
        }
        printFloat(f);
        printDouble(static_cast<double>(f));
    }
    else if (isDouble(literal)) {
        double d = std::atof(literal.c_str());
        if (d >= 0 && d <= 127 && !std::isnan(d) && !std::isinf(d)) {
            printChar(static_cast<char>(d));
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        if (!std::isnan(d) && !std::isinf(d) && 
            d >= std::numeric_limits<int>::min() && 
            d <= std::numeric_limits<int>::max()) {
            printInt(static_cast<int>(d));
        } else {
            std::cout << "int: impossible" << std::endl;
        }
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else {
        std::cout << "Error: Invalid input format" << std::endl;
    }
} 