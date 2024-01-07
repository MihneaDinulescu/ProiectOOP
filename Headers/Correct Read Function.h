//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_CORRECT_READ_FUNCTION_H
#define OOP_CORRECT_READ_FUNCTION_H

#include <string>

/**
 * @brief Reads an integer value from the standard input within a specified range.
 *
 * This function prompts the user to input an integer value between the given bottom and top range values.
 * If the input is valid and within the specified range, it returns the input value.
 *
 * @param bottom The minimum value that the user can input.
 * @param top The maximum value that the user can input.
 * @return Returns the validated integer value within the range.
 */
int read(int bottom, int top);

/**
 * @brief Reads an unsigned long integer value from the standard input within a specified range.
 *
 * This function prompts the user to input an unsigned long integer value between the given bottom and top range values.
 * If the input is valid and within the specified range, it returns the input value.
 *
 * @param bottom The minimum value that the user can input.
 * @param top The maximum value that the user can input.
 * @return Returns the validated unsigned long integer value within the range.
 */
unsigned long read2(unsigned int bottom, unsigned long top);


#endif //OOP_CORRECT_READ_FUNCTION_H
