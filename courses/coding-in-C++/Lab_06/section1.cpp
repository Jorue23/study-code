#include <stdexcept>
#include <iostream>

class FileOpenException : public std::runtime_error {
    public:
        FileOpenException(const std::string &error) :
            std::runtime_error(error) {}
};

class InvalidConfigurationException : public std::runtime_error {
    public: 
        InvalidConfigurationException(const std::string &error) :
            std::runtime_error(error) {}
};

class ConfigLoader {
    public:
        void load(std::string filename) {
            if (filename.find_first_not_of(" \t\r\n") == std::string::npos) {
                throw std::invalid_argument("Empty filename");
            }
            else if (filename == "missing.cfg") {
                throw FileOpenException("Couldn't open file");
            }
            else if (filename == "invalid.cfg") {
                throw InvalidConfigurationException("System configuration is invalid");
            }
            else if (!filename.ends_with(".cfg")) {
                throw std::invalid_argument("Wrong filetype");
            }
        }
};

int main() {

    ConfigLoader Test;
    try {
        Test.load(" ");
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    try {
        Test.load("invalid.cfg");
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }    

    try {
        Test.load("missing.cfg");
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }    
    
    try {
        Test.load("oisefohSe.posj");
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }   
    
    try {
        Test.load("oijsoiawe");
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
    
    return 0;

}