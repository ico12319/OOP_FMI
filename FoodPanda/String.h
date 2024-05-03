#include <fstream>

class String{
    
private:
    char* data;
    size_t currLen;
    unsigned capacity;
    
    void resize(unsigned newCap);
    void copy(const String& other);
    void destroy();
    void move(String&& other);
    
    explicit String(unsigned len);
    
public:
    String();
    String(const char* data);
    String(const String& other);
    String(String&& other);
    ~String();
    String& operator=(const String& other);
    String& operator=(String&& other);
    
    const char* c_str() const;
    size_t length() const;
    unsigned getCap() const;
    
    String& operator+=(const String& other);
    const char& operator[](unsigned index) const;
    char& operator[](unsigned index);
    friend String operator+(const String& lhs,const String& rhs);
    friend std::istream& operator>>(std::istream& is,String& obj);
    
    
};

std::ostream& operator<<(std::ostream& os,const String& obj);
bool operator==(const String& lhs,const String& rhs);

