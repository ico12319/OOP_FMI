#include <stdio.h>
#include "StudentDatabase.h"

StudentDatabase::StudentDatabase(const Student* students,size_t studenstCount){
    this->students = new Student[studenstCount];
    for(int i = 0;i<studenstCount;i++)
        this->students[i] = students[i];
    this->studentsCount = studenstCount;
}

static size_t getFileSize(std::ifstream& ifs){
    size_t currPos = ifs.tellg();
    ifs.seekg(0,std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(currPos);
    
    return size;
}

StudentDatabase::StudentDatabase(){
    this->studentsCount = 8;
    this->students = new Student[this->studentsCount];
}


StudentDatabase::StudentDatabase(const StudentDatabase& other){
    copy(other);
}

StudentDatabase::StudentDatabase(StudentDatabase&& other){
    move(std::move(other));
}

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

StudentDatabase& StudentDatabase::operator=(StudentDatabase&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

StudentDatabase::~StudentDatabase(){
    destroy();
}

void StudentDatabase::destroy(){
    delete[]this->students;
    this->students = nullptr;
}

void StudentDatabase::move(StudentDatabase&& other){
    this->students = other.students;
    other.students = nullptr;
    this->studentsCount = other.studentsCount;
    other.studentsCount = 0;
}

void StudentDatabase::copy(const StudentDatabase& other){
    this->students = new Student[other.studentsCount];
    for(int i = 0;i<other.studentsCount;i++)
        this->students[i] = other.students[i];
    this->studentsCount = other.studentsCount;
}



void StudentDatabase::printDatabase() const{
    for(int i = 0;i<studentsCount;i++){
        std::cout<<"Name: " << students[i].getName()<<" is " << students[i].getAge() << " years old."<<std::endl;
    }
}


void StudentDatabase::writeStudentsToDatabse(std::ofstream& ofs) const{
    ofs.write((const char*) students,sizeof(Student) * studentsCount);
}


void StudentDatabase::readStudentsFromDatabase(std::ifstream& ifs){
    size_t size = getFileSize(ifs);
    this->studentsCount = size / sizeof(Student);
    this->students = new Student[this->studentsCount];
    ifs.read((char*) students,size);
}



