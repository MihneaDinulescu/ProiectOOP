//
// Created by dinul on 11/18/2023.
//

#include<iostream>
#include "Correct Read Function.h"

int read(int bottom, int top){
    while(true){
        std::string input;
        std::getline(std::cin, input);

        try{
            int digit = stoi(input);
            if(digit >= bottom && digit <= top){
                return digit;
            }
        } catch(std::exception &e){


        }

    }
}

unsigned long read2(int bottom, unsigned long top){
    while(true){
        std::string input;
        std::getline(std::cin, input);

        try{
            unsigned long digit = stoi(input);
            if(digit >= bottom && digit <= top){
                return digit;
            }
        } catch(std::exception &e){


        }

    }
}