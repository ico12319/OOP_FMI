#include <stdio.h>
#include <iostream>
#include <fstream>

template<class T>

class Queue{
    
private:
    T* arr;
    size_t size;
    size_t capacity;
    
    void copy(const Queue& other){
        this->arr = new T[other.capacity];
        for(int i = 0;i<other.capacity;i++){
            this->arr[i] = other.arr[i];
        }
        this->capacity = other.capacity;
        this->size = other.size;
    }
    
    void move(Queue&& other){
        this->arr = other.arr;
        other.arr = nullptr;
        
        this->size = other.size;
        this->capacity = other.capacity;
        
        other.size = other.capacity = 0;
    }
    void destroy(){
        delete[]arr;
        arr = nullptr;
    }
    
    void resize(size_t newCap){
        T* newArr = new T[newCap];
        for(int i = 0;i<size;i++){
            newArr[i] = arr[i];
        }
        delete[]arr;
        arr = newArr;
        capacity = newCap;
    }
    
public:
    Queue(){
        this->capacity = 8;
        this->arr = new T[this->capacity];
        this->size = 0;
    }
    Queue(const Queue& other){
        copy(other);
    }
    Queue(Queue&& other){
        move(std::move(other));
    }
    
    Queue& operator=(const Queue& other){
        if(this!=&other){
            destroy();
            copy(other);
        }
        return *this;
    }
    
    Queue& operator=(Queue&& other){
        if(this!=&other){
            destroy();
            move(std::move(other));
        }
        return *this;
    }
    
    ~Queue(){
        destroy();
    }
    
    
    void enqueue(const T& element){
        if(size == capacity){
            resize(capacity * 2);
        }
        
        arr[size] = element;
        size++;
    }
    
    T dequeue(){
        T toDelete = arr[0];
        for(int i = 0;i< size - 1;i++){
            arr[i] = arr[i+1];
        }
        size--;
        return toDelete;
    }
    
    T& peek() const{
        return arr[0];
    }
    
    friend std::ostream& operator<<(std::ostream& os,const Queue& obj){
        for(int i = 0;i<obj.size;i++){
            os << obj.arr[i] << " ";
        }
        return os;
    }
    
    
    bool isEmpty() const{
        return (size == 0);
    }
    
    
    size_t getSize() const{
        return size;
    }
    
    
    
};
