//
// Created by dinul on 11/18/2023.
//

#include<iostream>
#include "Correct Read Function.h"

#include <iostream>
#include <limits>
#include <string>

int read(int bottom, int top) {
    int result = 0;

    while (true) {
        std::string input;
        if (!std::getline(std::cin, input)) {
            break;
        }

        try {
            int digit = std::stoi(input);
            if (digit >= bottom && digit <= top) {
                result = digit;
                break;
            }
        } catch (const std::exception& e) {
            e.what();
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }

    return result;
}

unsigned long read2(unsigned int bottom, unsigned long top) {
    int result = 0;
    while (true) {
        std::string input;
        if (!std::getline(std::cin, input)) {
            break;
        }

        try {
            unsigned long digit = std::stoi(input);
            if (digit >= bottom && digit <= top) {
                return digit;
            }
        } catch (const std::exception& e) {
            e.what();
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }

    return result;
}
