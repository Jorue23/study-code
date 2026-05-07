#include <cmath>
#include <iostream>



class Shape {
    public:
        virtual double area() const {
            return 0.0;
        }

        virtual ~Shape() {};
};

class Circle : public Shape {
    private: 

        double radius;
        static constexpr double PI = 3.1415926;
    
    public:

        Circle(double radius) : radius(radius) {};

        double area() const override {
            return PI * std::pow(radius, 2);
        }
};

class Rectangle : public Shape {
    private: 
        double sideA;
        double sideB;

    public:

        Rectangle(double sideA, double sideB)
            : sideA(sideA), sideB(sideB) {};

        double area() const override {
            return sideA * sideB;
        }
};


int main() {

    Circle circle1(3.4);
    Circle circle2(7.3);
    Rectangle rectangle1(4.3, 6.2);
    Rectangle rectangle2(5.2, 8.4);

    Shape* shapes[4] = {&circle1, &circle2, &rectangle1, &rectangle2};

    for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i++) {
        std::cout << shapes[i]->area() << std::endl;
    }
}