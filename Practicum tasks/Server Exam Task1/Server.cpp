#include <stdio.h>
#include "Server.h"
#include <iostream>



void Server::setUsers(const User* users, int currUsers){
    
    for(int i = 0;i<currUsers;i++){
        this->users[i] = users[i];
    }
    
    this->currUsers = currUsers;
}

Server::Server(const User* users,int currUsers){
    setUsers(users, currUsers);
}


bool Server::containsUser(const char* name) const{
    
    for(int i = 0;i<currUsers;i++){
        
        if(std::strcmp(users[i].getName(),name) == 0){
            return true;
        }
        
    }
    return false;
    
}

void Server::add(const User& user){
    
    if(!containsUser(user.getName()) && currUsers < MAX_USERS){
        
        users[currUsers] = user;
        currUsers++;
        
    }
    
}

void Server::remove(const User& user){
    
    for(int i = 0;i<currUsers;i++){
        if(std::strcmp(users[i].getName(), user.getName())==0){
            for(int j = i;j<currUsers-1;j++){
                users[j] = users[j+1];
            }
            currUsers--;
        }
    }
}

User Server::printMostViewedUser() const{
    
    int maxIndex = 0;
    
    for(int i = 1;i<currUsers;i++){
        if(users[i].getCounterName() > users[maxIndex].getCounterName()){
            maxIndex = i;
        }
    }
    
    return users[maxIndex];
    
}

void Server::printUsers() const{
    
    for(int i = 0;i<currUsers;i++){
        users[i].printUser();
    }
    
}


void Server::writeServerToBinary(std::ofstream& ofs) const{
    
    ofs.write((const char*) &currUsers,sizeof(currUsers));
    
    for(int i = 0;i<currUsers;i++){
        users[i].writeToBinary(ofs);
    }
    
}

User* Server::readUsers(std::ifstream& ifs){
    
    int size;
    ifs.read((char*) &size,sizeof(size));
    
    for(int i = 0;i<size;i++){
        users[i].readUser(ifs);
    }
    
    return users;
    
}
