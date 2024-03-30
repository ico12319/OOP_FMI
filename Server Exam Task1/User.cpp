#include <stdio.h>
#include "User.h"
#include <iostream>


int User::getCounterName() const{
    return this->counterName;
}


const char* User::getName() const{
    counterName++;
    return this->userName;
}

const char* User::getPassword() const{
    return this->password;
}

void User::setName(const char* userName){
    if(userName == nullptr || this->userName == userName){
        return;
    }
     
    delete[]this->userName;
    
    this->userName = new char[std::strlen(userName) + 1];
    std::strcpy(this->userName, userName);
}

void User::setPassword(const char* password){
    
    if(password == nullptr || this->password==password){
        return;
    }
    
    delete[]this->password;
    
    this->password = new char[std::strlen(password) + 1];
    std::strcpy(this->password, password);
}


void User::copy(const User& other){
    
    this->userName = new char[std::strlen(other.userName) + 1];
    std::strcpy(this->userName, other.userName);
    
    this->password = new char[std::strlen(other.password) + 1];
    std::strcpy(this->password,password);
    
    this->counterName = other.counterName;
    
}

void User::destroy(){
    delete[]userName;
    delete[]password;
    
    userName = nullptr;
    password = nullptr;
    counterName = 0;
}

User::User(const User& other){
    copy(other);
}

User& User::operator=(const User& other){
    
    if(this!=&other){
        destroy();
        copy(other);
    }
    
    return *this;
    
}

User::User(const char* userName,const char* password){
    
    setName(userName);
    setPassword(password);
}

User::~User(){
    destroy();
}

void User::printUser() const{
    
    std::cout<<"Name: " << userName <<std::endl;
    std::cout<<"Password: " <<password<<std::endl;
    std::cout<<"Counter name: " <<counterName<<std::endl;
}



void User::writeToBinary(std::ofstream& ofs) const{
    
    size_t nameLen = std::strlen(userName);
    
    ofs.write((const char*) &nameLen,sizeof(nameLen));
    
    ofs.write(userName,nameLen+1);
    
    size_t passLen = std::strlen(password);
    
    ofs.write((const char*) &passLen,sizeof(passLen));
    
    ofs.write(password,passLen+1);
    
    ofs.write((const char*) &counterName, sizeof(counterName));
    
}


User User::readUser(std::ifstream& ifs){
    
    User user;
    
    size_t nameLen;
    ifs.read((char*) &nameLen,sizeof(nameLen));
    
    user.userName = new char[nameLen + 1];
    ifs.read(user.userName,nameLen+1);
    
    size_t passLen;
    ifs.read((char*) &passLen,sizeof(passLen));
    
    user.password = new char[passLen + 1];
    
    ifs.read(user.password,passLen+1);
    
    ifs.read((char*) &user.counterName,sizeof(user.counterName));
    
    return user;
}
