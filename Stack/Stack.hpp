#include <stdio.h>
#include <iostream>
#include <fstream>

template <class T>
class Stack {

private:
    T* arr;
    size_t size;
    size_t capacity;
    
    void copy(const Stack& other){
        this->arr = new T[other.capacity];
        for(int i = 0;i<other.capacity;i++){
            this->arr[i] = other.arr[i];
        }
        this->size = other.size;
        this->capacity = other.capacity;
    }
    
    void move(Stack&& other){
        this->arr = other.arr;
        other.arr = nullptr;
        
        this->size = other.size;
        other.size = 0;
        
        this->capacity = other.capacity;
        other.capacity = 0;
    }
    
    void destroy(){
        delete[] arr;
        arr = nullptr;
    }
    
    void resize(size_t newCap){
        T* newArr = new T[newCap];
        for(int i = 0;i<newCap;i++){
            newArr[i] = arr[i];
        }
        delete[]arr;
        arr = newArr;
        this->capacity = newCap;
    }
    
public:
    Stack(){
        this->capacity = 8;
        this->arr = new T[this->capacity];
        this->size = 0;
    }
    
    Stack(const Stack& other){
        copy(other);
    }
    
    Stack(Stack&& other){
        move(std::move(other));
    }
    
    Stack& operator=(const Stack& other){
        if(this!=&other){
            destroy();
            copy(other);
        }
        return *this;
    }
    
    Stack& operator=(Stack&& other){
        if(this!=&other){
            destroy();
            move(std::move(other));
        }
        return *this;
    }
    ~Stack(){
        destroy();
    }
    
    void push(const T& element){
        if(size == capacity)
            resize(capacity * 2);
        
        arr[size] = element;
        size++;
    
    }
    
    T& pop(){
        T& deleted = arr[size - 1];
        size--;
        return deleted;
    }
    T& peek() const{
        return arr[size - 1];
    }
    
    size_t getSize() const{
        return this->size;
    }
    
    bool isEmpty() const{
        return (size == 0);
    }
    
    friend std::ostream& operator<<(std::ostream& os,const Stack& obj){
        for(int i = obj.size - 1;i>=0;i--){
            os << obj.arr[i]<<" ";
        }
        return os;
    }
    
    
};
