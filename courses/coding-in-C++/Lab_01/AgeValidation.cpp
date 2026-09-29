#include <iostream>
#include <iomanip>
#include <cstdint>
#include <limits>
#include <string>


namespace validation {

    bool isAdult(std::uint_fast8_t age) {
        return age >= 18;
    }

    bool isSenior(std::uint_fast8_t age) {
        return age >= 65;
    }
}

int main() {
    while (true) {

        const std::uint16_t MAX_AGE = 187;

        std::cout << "Please enter your age: ";
        std::string input;
        std::getline(std::cin, input);

        std::size_t pos = 0;
        int parsed = -1;
        try {
            parsed = std::stoi(input, &pos);
        } catch (...) {}

        if (pos != input.size() || parsed < 0 || parsed > MAX_AGE) {
            std::cout << "You did not enter a valid number. Please try again." << std::endl;
            continue;
        }

        std::uint_fast16_t age = static_cast<std::uint_fast16_t>(parsed);

        std::cout << "You are " << age << " years old" << std::endl;

        if(!validation::isAdult(age) && !validation::isSenior(age)) {
            std::cout << "That means you are still a kid or teenager!" << std::endl;
        }
        else if(validation::isSenior(age)) {
            std::cout << "That means you are a senior citizen." << std::endl;
        }
        else {
            std::cout << "That means you are an adult citizen." << std::endl;
        }
    }
}