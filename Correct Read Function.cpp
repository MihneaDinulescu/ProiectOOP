#include <iostream>
#include <limits>
#include <string>
#include "Correct Read Function.h"

int read(int bottom, int top) {
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        try {
            size_t pos;
            int digit = std::stoi(input, &pos);

            if (pos == input.length() && digit >= bottom && digit <= top) {
                return digit;
            } else {
                throw std::invalid_argument("Invalid input");
            }
        } catch (const std::exception& e) {
            (void)e.what();
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }
}

unsigned long read2(unsigned int bottom, unsigned long top) {
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        try {
            size_t pos;
            unsigned long digit = std::stoul(input, &pos);

            if (pos == input.length() && digit >= bottom && digit <= top) {
                return digit;
            } else {
                throw std::invalid_argument("Invalid input");
            }
        } catch (const std::exception& e) {
            (void)e.what();
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }
}

