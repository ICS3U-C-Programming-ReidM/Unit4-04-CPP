// Copyright (c) 2025 Reid MacLean All rights reserved.
//
// Created by: Reid MacLean
// Created on: March 2025
// This program checks if the user enters
// the correct random number using a break statement

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>
#include <stdexcept>  // For std::invalid_argument
#include <string>

int main() {
    // This function checks if the user enters the correct
    // random number using a break statement
    int randomNumber;
    int userGuess;
    std::string userInput;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 0 and 9
    randomNumber = rand() % 10;  // random number between 0 and 9

    std::cout << "Enter a number between 0 and 9: " << std::endl;

    while (true) {
        std::cin >> userInput;

        // Check if the input is a valid integer
        try {
            userGuess = std::stoi(userInput);
        } catch (const std::invalid_argument& e) {
            std::cout << "Enter integer!" << std::endl;
            continue;  // Skip to the next iteration of the loop
        }

        // Check if number is within 0-9
        if (userGuess < 0 || userGuess > 9) {
            std::cout << "Enter number within 0-9!" << std::endl;
            continue;  // Ask again
        }

        // Check if the guess is correct
        if (userGuess == randomNumber) {
            std::cout << "You guessed right!" << std::endl;
            break;  // Exit the loop if the guess is correct
        } else {
            std::cout << "Try one more time!" << std::endl;
        }
    }

    return 0;
}
