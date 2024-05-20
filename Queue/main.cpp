#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    Queue<int> queue;
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(11);
    
    queue.dequeue();
    queue.dequeue();
    
    std::cout<<queue<<std::endl;
    std::cout<<queue.getSize()<<std::endl;
}
