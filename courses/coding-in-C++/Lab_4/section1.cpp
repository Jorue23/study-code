#include <iostream>
#include <cmath>


class Vector2D {
    private:
        double x;
        double y;
    public:
        Vector2D()
            : x(0.0), y(0.0) {}

        Vector2D(double x, double y) 
            : x(x), y(y) {}

        void operator+=(const Vector2D &vec) {
            this->x += vec.getX();
            this->y += vec.getY();
        }

        double getX() const {
            return this->x;
        }

        double getY() const {
            return this->y;
        }

        void printCoords() const {
            std::cout << "X Value: " << this->getX() << " Y Value: " << this->getY() << std::endl;
        }

        float getLength() {
            return sqrt(x * x + y * y);
        }

        float getLength(int precision) {
            float value = this->getLength();
            double factor = std::pow(10.0, precision);
            return std::round(value * factor) / factor;
        }
};

Vector2D operator+(const Vector2D &vec, const Vector2D &vec2) {
    return Vector2D(vec.getX() + vec2.getX(),
                    vec.getY() + vec2.getY());
}


int main() {
    Vector2D Vec = Vector2D(182.34, 8349.45);
    Vec.printCoords();
    std::cout << Vec.getX() << " " << Vec.getY() << std::endl;
    std::cout << "Length not rounded: " << Vec.getLength() << std::endl;
    std::cout << "Value rounded to 1 decimal: " << Vec.getLength(1) << std::endl;

}