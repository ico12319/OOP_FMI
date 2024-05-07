#include <stdio.h>
#include "StudentArray.h"


StudentArray::StudentArray(){
    this->capacity = 8;
    this->studentsCount = 0;
    this->students = new Student*[this->capacity];
}

void StudentArray::copy(const StudentArray& other){
    this->capacity = other.capacity;
    this->studentsCount = other.studentsCount;
    for(int i = 0;i<other.capacity;i++){
        if(other.students[i] != nullptr){
            this->students[i] = new Student(*other.students[i]);
        }
    }
}


void StudentArray::move(StudentArray&& other){
    this->students = other.students;
    other.students = nullptr;
    
    this->capacity = other.capacity;
    other.capacity = 0;
    
    this->studentsCount = other.studentsCount;
    other.studentsCount = 0;
}

void StudentArray::destroy(){
    for(int i = 0;i<capacity;i++){
        delete students[i];
    }
    delete[] students;
}

StudentArray::StudentArray(const StudentArray& other){
    copy(other);
}

StudentArray::StudentArray(StudentArray&& other){
    move(std::move(other));
}

StudentArray& StudentArray::operator=(const StudentArray& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

StudentArray& StudentArray::operator=(StudentArray&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


StudentArray::~StudentArray(){
    destroy();
}


void StudentArray::resize(unsigned newCap){
    Student** newArr = new Student*[newCap];
    for(int i = 0;i<capacity;i++){
        newArr[i] = students[i];
    }
    delete[] students;
    students = newArr;
    capacity = newCap;
}


void StudentArray::pushAt(int ind, const Student& other){
    if(ind > capacity){
        throw std::invalid_argument("Out of bounds!");
    }
    if(students[ind] == nullptr){
        students[ind] = new Student(other);
        studentsCount++;
    }
    else{
        *students[ind] = other;
    }
}

void StudentArray::pushAt(int ind, Student&& other){
    if(ind > capacity){
        throw std::invalid_argument("Out of bounds!");
    }
    if(students[ind] == nullptr){
        students[ind] = new Student(std::move(other));
        studentsCount++;
    }
    else{
        *students[ind] = std::move(other);
    }
}

void StudentArray::push(const Student& other){
    int index = firstFreeIndex();
    if(index == capacity){
        resize(capacity + capacity /2);
    }
        
    pushAt(index, other);
}


int StudentArray::firstFreeIndex() const{
    for(int i = 0;i<capacity;i++){
        if(students[i] == nullptr){
            return i;
        }
    }
    return capacity;
}

void StudentArray::pushFront(const Student& other){
    pushAt(0, other);
}

void StudentArray::pushBack(const Student& other){
    pushAt(capacity - 1, other);
}

void StudentArray::pushFront(Student&& other){
    pushAt(0,std::move(other));
}

void StudentArray::pushBack(Student&& other){
    pushAt(capacity - 1,std::move(other));
}

Student StudentArray::getFront() const{
    for(int i = 0;i<capacity;i++){
        if(students[i]!=nullptr){
            return *students[i];
        }
    }
    throw std::logic_error("The collection is empty!");
}


Student StudentArray::getBack() const{
    for(int i = capacity - 1;i>=0;i--){
        if(students[i]!=nullptr){
            return *students[i];
        }
    }
    throw std::logic_error("The collection is empty!");
}


size_t StudentArray::size() const{
    return this->studentsCount;
}

bool StudentArray::contains(int ind) const{
    return (students[ind]!=nullptr);
}

Student StudentArray::at(int ind) const{
    if(!contains(ind)){
        throw std::logic_error("Accessing nullptr!");
    }
    
    return *students[ind];
}


void StudentArray::print() const{
    for(int i = 0;i<capacity;i++){
        if(contains(i)){
            students[i]->printStudent();
        }
    }
}
