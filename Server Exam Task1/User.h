#include <fstream>


class User{
    
private:
    char* userName = nullptr;
    char* password = nullptr;
    mutable int counterName = 0;
    
    void copy(const User& other);
    void destroy();
    
public:
    User() = default;
    User(const char* name, const char* password);
    User(const User& other);
    User& operator=(const User& other);
    ~User();
    
    
    const char* getName() const;
    const char* getPassword() const;
    int getCounterName() const;
    
    
    
    void setName(const char* userName);
    void setPassword(const char* password);
    void setCounterName(int counterName);
    
    
    void printUser()const;
    
    
    void writeToBinary(std::ofstream& ofs) const;
    
    User readUser(std::ifstream& ifs);
};
