#include "User.h"


const int MAX_USERS = 20;

class Server{
    
private:
    User users[MAX_USERS];
    int currUsers = 0;
    
public:
    
    Server() = default;
    Server(const User* users,int currUsers);
    
    
    void setUsers(const User* users,int currUsers);
    
    
    void add(const User& user);
    void remove(const User& user);
    bool containsUser(const char* userName) const;
    void printUsers() const;
    User printMostViewedUser() const;
    
    void writeServerToBinary(std::ofstream& ofs) const;
    User* readUsers(std::ifstream& ifs);
    
    
};
