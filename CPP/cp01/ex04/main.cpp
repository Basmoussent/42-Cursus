/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:08:09 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 23:08:09 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replaceAndWriteToFile(const std::string &filename, const std::string &s1, const std::string &s2) {
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty!" << std::endl;
        return;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line)) {
        content += line + "\n";
    }
    inputFile.close();

    std::string newContent;
    std::size_t i = 0;
    while (i < content.length()) {
        std::size_t found = content.find(s1, i);
        if (found != std::string::npos) {
            newContent.append(content, i, found - i);
            newContent.append(s2);
            i = found + s1.length();
        } else {
            newContent.append(content, i, content.length() - i);
            break;
        }
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Cannot create output file '" << filename << ".replace'" << std::endl;
        return;
    }

    outputFile << newContent;
    outputFile.close();
    std::cout << "File '" << filename << ".replace' created successfully!" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceAndWriteToFile(filename, s1, s2);
    return 0;
}
