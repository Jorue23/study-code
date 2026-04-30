#include <iostream>

class User {
    protected:
        std::string name;
        int id;
    public:
        User(std::string name, int id) 
            : name(name), id(id) {
                std::cout << "Constructor of user" << std::endl;
            }
        void printInfo() {
            std::cout << "Name: " << name << "ID: " << id << std::endl;
        }
};

class Student : public User {
    private:
        int classNumber;
    public:
        Student(std::string name, int id, int classNumber) : User(name, id), classNumber(classNumber) {}
};






int main() {
    
}