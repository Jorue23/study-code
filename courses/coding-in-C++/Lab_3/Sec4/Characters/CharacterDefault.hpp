/**
 * @file CharacterDefault.hpp
 * @brief Declaration of the Character class.
 * 
 * This module defines a default class "Character" with members and functions that all characters have.
 * This default character is not to be used, it is intended to be inherited from.
 * 
 */


#ifndef CHARACTER_DEFAULT_HPP
#define CHARACTER_DEFAULT_HPP

#include <string>

class Character {
    private:
        std::string name;
        double healthPoints;
        int level;

};



#endif