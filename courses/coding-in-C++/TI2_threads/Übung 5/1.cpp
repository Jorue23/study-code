#include <iostream>
#include <thread>
#include <semaphore>

std::binary_semaphore door(1);

constexpr int NUM_ITERATIONS = 1000000;
constexpr int NUM_ITERATIONS_2 = 500000;

int counter = 0;

void increment_loop(int iterations) {
    for(int i = 0; i < iterations; i++) {
        door.acquire();
        counter++;
        door.release();
    }
}

int main() {
    std::thread t1{increment_loop, NUM_ITERATIONS};
    std::thread t2{increment_loop, NUM_ITERATIONS};
    std::thread t3{increment_loop, NUM_ITERATIONS_2};

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Endwert: " << counter << '\n';
}