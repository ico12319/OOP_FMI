#include <stdio.h>
#include "StudentDB.h"

StudentDB::StudentDB(){
    this->capacity = 8;
    this->studentsCount = 0;
    this->students = new Student*[this->capacity] {nullptr};
}


void StudentDB::copy(const StudentDB& other){
    this->capacity = other.capacity;
    this->studentsCount = other.studentsCount;
    this->students = new Student*[capacity];
    for(int i = 0;i<studentsCount;i++){
        if(other.students[i]!=nullptr){
            students[i] = new Student(*other.students[i]);
        }
    }
}

void StudentDB::move(StudentDB&& other){
    this->students = other.students;
    other.students = nullptr;
    
    this->capacity = other.capacity;
    other.capacity = 0;
    
    this->studentsCount = other.studentsCount;
    other.studentsCount = 0;
}

StudentDB::StudentDB(StudentDB&& other){
    move(std::move(other));
}

void StudentDB::destroy(){
    for(int i = 0;i<studentsCount;i++){
        delete students[i];
    }
    delete[]students;
}

StudentDB::~StudentDB(){
    destroy();
}

StudentDB::StudentDB(const StudentDB& other){
    copy(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

StudentDB& StudentDB::operator=(StudentDB&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

void StudentDB::resize(size_t newCap){
    Student** temp = new Student*[newCap];
    for(int i = 0;i<studentsCount;i++){
        temp[i] = students[i];
    }
    delete[] students;
    students = temp;
    capacity = newCap;
}

void StudentDB::add(const Student& student){
    if(studentsCount == capacity){
        resize(capacity * 2);
    }
    
    if(find(student.getFn())){
        std::cout<<"A student with such faculty num already exist!"<<std::endl;
        return;
    }
    
    students[studentsCount] = new Student(student);
    studentsCount++;
}


void StudentDB::remove(const Student& student){
    
    if(!find(student.getFn())){
        std::cout<<"No such student in the database!"<<std::endl;
    }
    
    int index = 0;
    for(int i = 0;i<studentsCount;i++){
        if(*students[i] == student){
            index = i;
            delete students[i];
            break;
        }
    }
    for(int i = index;i<studentsCount - 1;i++){
        students[i] = students[i+1];
    }
    
    studentsCount--;
}

bool StudentDB::find(unsigned fn) const{
    
    for(int i = 0;i<studentsCount;i++){
        if(students[i]->getFn() == fn){
            return true;
        }
    }
    return false;
}

void StudentDB::display() const{
    for(int i = 0;i<studentsCount;i++){
        students[i]->printStudent();
    }
}


size_t StudentDB::getStudentsCount() const{
    return this->studentsCount;
}

Student** StudentDB::getStudents() const{
    return students;
}
