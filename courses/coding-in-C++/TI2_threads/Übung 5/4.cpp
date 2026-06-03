#include <iostream>
#include <deque>
#include <thread>
#include <semaphore>

typedef struct Good {
    int id;
} Good;

std::deque<Good> buffer;

int next_id = 0;

std::counting_semaphore door(1);

void producer() {
    while (true) {
        door.acquire();
        Good g;
        g.id = next_id++;
        buffer.push_back(g);
        std::cout << "Produced: " << g.id << '\n';
        door.release();
    }
}

void consumer() {
    while (true) {
        door.acquire();
        if (!buffer.empty()) {
            Good g = buffer.front();
            buffer.pop_front();
            std::cout << "Consumed: " << g.id << '\n';
            door.release();
        }
    }
}

int main() {

    std::thread prod{producer};
    std::thread cons{consumer};
    std::thread cons2{consumer};

    prod.join();
    cons.join();
    cons2.join();
}
