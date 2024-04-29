#include <stdio.h>
#include "StudentCollection.h"

size_t StudentCollection::getCapacity() const{
    return this->allocatedSpace;
}

StudentCollection::StudentCollection(){
    this->currSize = 0;
    this->allocatedSpace = 8;
    this->students = new Student*[allocatedSpace];
}

StudentCollection::~StudentCollection(){
    destroy();
}
void StudentCollection::copy(const StudentCollection& other){
    this->currSize = other.currSize;
    this->allocatedSpace = other.allocatedSpace;
    
    this->students = new Student*[other.allocatedSpace];
    
    for(int i = 0;i<other.allocatedSpace;i++){
        if(other.students[i] != nullptr){
            students[i] = new Student(*other.students[i]);
        }
    }
}


void StudentCollection::destroy(){
    for(int i = 0;i<allocatedSpace;i++){
        delete students[i];
    }
    delete[] students;
    
    this->currSize = 0;
    this->allocatedSpace = 0;
}


StudentCollection::StudentCollection(const StudentCollection& other){
    copy(other);
}

void StudentCollection::move(StudentCollection&& other){
    this->currSize = other.currSize;
    other.currSize = 0;
    
    this->allocatedSpace = other.allocatedSpace;
    other.allocatedSpace = 0;
    
    this->students = other.students;
    other.students = nullptr;
}


StudentCollection::StudentCollection(StudentCollection&& other){
    move(std::move(other));
}

StudentCollection& StudentCollection::operator=(const StudentCollection& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    
    return *this;
}

StudentCollection& StudentCollection::operator=(StudentCollection&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    
    return *this;
}


size_t StudentCollection::getFirstFreeIndex() const{
    for(int i = 0;i<allocatedSpace;i++){
        if(students[i] == nullptr){
            return i;
        }
    }
    return allocatedSpace;
}

void StudentCollection::pushAt(size_t index,const Student& other){
    if(index > allocatedSpace){
        throw std::out_of_range("Out of bounds!");
    }
    
    if(students[index] == nullptr){
        students[index] = new Student(other);
        currSize++;
    }
    else{
        *students[index] = other;
    }
    
}

void StudentCollection::push(const Student& student){
    size_t index = getFirstFreeIndex();
    if(index == allocatedSpace){
        resize(allocatedSpace + allocatedSpace / 2);
    }
    
    pushAt(index, student);
}

void StudentCollection::removeAt(size_t index){
    if(index > allocatedSpace){
        throw std::out_of_range("Out of bounds");
    }
    
    if(!containsAt(index)){
        return;
    }
    
    delete students[index];
    students[index] = nullptr;
    currSize--;
}


bool StudentCollection::containsAt(size_t index) const{
    return (students[index] != nullptr);
}


void StudentCollection::resize(size_t newAlloc){
    if(newAlloc <= allocatedSpace){
        return;
    }
    
    Student** newStudents = new Student*[newAlloc];
    for(int i = 0;i<newAlloc;i++){
        newStudents[i] = students[i];
    }
    
    delete[]students;
    students = newStudents;
    allocatedSpace = newAlloc;
}

size_t StudentCollection::getNumberInClass(const Student& student) const{
    
    for(int i = 0;i<allocatedSpace;i++){
        if(students[i] != nullptr && students[i]->getName() == student.getName()){
            return i;
        }
    }
    
    return -1;
    
}

void StudentCollection::setAt(const Student& student, size_t index){
    
    if(students[index] == nullptr){
        students[index] = new Student(student);
        currSize++;
    }
    else{
        *students[index] = student;
    }
}

const Student& StudentCollection::at(size_t index) const{
    
    if(index > allocatedSpace){
        throw std::out_of_range("Out of bounds");
    }
    
    if(!containsAt(index)){
        throw std::logic_error("Student not contained!");
    }
    
    return *students[index];
}


void StudentCollection::print() const{
    for(int i = 0;i<allocatedSpace;i++){
        if(containsAt(i)){
            students[i]->printStudent();
        }
    }
}
