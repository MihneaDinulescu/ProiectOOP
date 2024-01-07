#include <iostream>
#include <limits>
#include <string>
#include "../Headers/Correct Read Function.h"

/**
 * @brief Implementation of the read function for integer values.
 *
 * Continuously reads user input from the standard input and validates it to be within the specified range.
 *
 * @param bottom The minimum value that the user can input.
 * @param top The maximum value that the user can input.
 * @return Returns the validated integer value within the specified range.
 */
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
        } catch (const std::exception &e) {
            (void) e.what();
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }
}

/**
 * @brief Implementation of the read2 function for unsigned long integer values.
 *
 * Continuously reads user input from the standard input and validates it to be within the specified range.
 *
 * @param bottom The minimum value that the user can input.
 * @param top The maximum value that the user can input.
 * @return Returns the validated unsigned long integer value within the specified range.
 */
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
        } catch (const std::exception &e) {
            (void) e.what();
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }
}

