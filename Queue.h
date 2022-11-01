//
// Created by Daniel Ferguson on 1/11/2022.
//

#ifndef PRIORITYQUEUE_QUEUE_H
#define PRIORITYQUEUE_QUEUE_H

#include <iostream>

template<typename T>
class Queue {
public:

    //constructor / destructor
    Queue();
    ~Queue();

    //The 5 permitted linkedlist modifiers
    void enqueue(const T& d);
    T dequeue();
    T& front();

    bool isEmpty() const;
    int size() const;
    int maxLength() const;

    int queueDataReturn(std::ostream &out);

private:

    T LQ[50];
    int length;
};

template<typename T>
std::ostream& operator << (std::ostream& out, Queue<T>& LQin);

#include "Queue.hpp"

#endif //PRIORITYQUEUE_QUEUE_H
