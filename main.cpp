#include <iostream>
#include "p_queue.h"

#define log(x) std::cout << x << std::endl;
int main() {
    p_queue<int> pq;

    for (int i = 0; i < 10; ++i) {
        pq.push(i);
    }
    std::cout << "size: "<< pq.size() << std::endl;
    while (!pq.empty()){
        std::cout << "#"<<pq.pop() << "\n";
    }

    std::cout << "size: "<< pq.size() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
