//
// Created by dinul on 11/18/2023.
//

#include<iostream>
#include "Correct Read Function.h"
#include <limits>
#include <string>

int read(int bottom, int top){
    while(true){
        std::string input;
        std::getline(std::cin, input);

        try{
            int digit = std::stoi(input);
            if(digit >= bottom && digit <= top){
                return digit;
            }
        } catch(const std::exception& e){
            std::cerr << "Exception caught: " << e.what() << std::endl;
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }

    }
}

unsigned long read2(unsigned int bottom, unsigned long top) {

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        try {
            unsigned long digit = std::stoi(input);
            if (digit >= bottom && digit <= top) {
                return digit;
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            std::cerr << "Invalid input. Please enter a valid number.\n";
        }
    }

}
