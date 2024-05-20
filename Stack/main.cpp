#include "Stack.hpp"

int main() {
    
    Stack<char> charStack;
    Stack <int> stack;
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(7);
    
    stack.pop();
    stack.push(6);
    stack.push(9);
    stack.push(7);
    
    
    charStack.push('a');
    charStack.push('c');
    charStack.push('b');
    
    std::cout<< charStack.peek()<<std::endl;
    
    std::cout<<charStack<<std::endl;
    
    //std::cout<<stack<<std::endl;
   
}
