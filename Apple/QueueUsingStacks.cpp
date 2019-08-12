//
//  main.cpp
//  QueueUsingStack
//
//  Created by Anmol Jain on 12/08/19.
//  Copyright © 2019 Anmol Jain. All rights reserved.
//

// Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data
// structure with the following methods: enqueue, which inserts an element into the queue, and
// dequeue, which removes it.

#include <iostream>
#include <stack>

template<typename type>
class Queue {
    std::stack<type> insertion;
    std::stack<type> deletion;
public:
    void enqueue(type value) {
        insertion.push(value);
    }
    
    type dequeue() {
        if (deletion.empty()) {
            if (insertion.empty())
                return NULL;
            while (!insertion.empty()) {
                deletion.push(insertion.top());
                insertion.pop();
            }
        }
        
        type value = deletion.top();
        deletion.pop();
        return value;
    }
};

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    
    queue.enqueue(60);
    queue.enqueue(70);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
}
