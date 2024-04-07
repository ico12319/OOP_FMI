#include <fstream>


class Istring{
    
private:
    char* data = nullptr;
    size_t length = 0;
    
    
    void copy(const Istring& other);
    void destroy();
    
public:
    Istring() = default;
    Istring(const char* data);
    Istring(const Istring& other);
    Istring& operator=(const Istring& other);
    ~Istring();
    
    size_t getLength() const;
    const char* getData() const;
    void setData(const char* data);
    
    
    void reverse();
    bool isPalindrome() const;
    
    
    const char& operator[](int index) const;
    char& operator[](int index);
    Istring& operator+=(const Istring& other);
    Istring& operator-=(const Istring& other);
    Istring& operator()(int replicateCount);
    
    friend std::ostream& operator<<(std::ostream& os,const Istring& str);
    
};

Istring operator+(const Istring& lhs, const Istring& rhs);
bool operator==(const Istring& lhs,const Istring& rhs);
bool operator!=(const Istring& lhs,const Istring& rhs);
