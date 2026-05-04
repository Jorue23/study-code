#include <iostream>
#include <cmath>


class Vector2D {
    private:
        double x;
        double y;
    public:
        Vector2D() {}

        Vector2D(double x, double y) 
            : x(x), y(y) {}

        double getX() {
            return this->x;
        }

        double getY() {
            return this->y;
        }

        void printCoords() {
            std::cout << "X Value: " << this->x << " Y Value: " << this->y << std::endl;
        }

        float getLength() {
            return sqrt(x * x + y * y);
        }

        float getLength(int precision) {
            float value = sqrt(x * x + y * y);
            double factor = std::pow(10.0, precision);
            return std::round(value * factor) / factor;
        }
};


int main() {
    Vector2D Vec = Vector2D(182.34, 8349.45);
    Vec.printCoords();
    std::cout << Vec.getX() << " " << Vec.getY() << std::endl;
    std::cout << "Length not rounded: " << Vec.getLength() << std::endl;
    std::cout << "Value rounded to 7 decimals: " << Vec.getLength(1) << std::endl;

}