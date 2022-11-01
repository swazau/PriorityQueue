#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> test;

    for (int i = 20; i > 9; i--) {
        test.enqueue(i);
    }

    for (int i = 0; i < 10; i++) { // shows that the stack is actually ordering by priority
        test.enqueue(i);
    }

    std::cout<< test.dequeue() << std::endl;
    std::cout<< test.dequeue() << std::endl;

    std::cout << test << std::endl;

    return 0;
}
