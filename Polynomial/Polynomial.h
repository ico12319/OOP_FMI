#include <fstream>

class Polynomial{
    
private:
    int power = 0;
    int* polynom = nullptr;
    
    void copy(const Polynomial& other);
    void destroy();
    
public:
    Polynomial() = default;
    Polynomial(int power, const int* polynom);
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    ~Polynomial();
    
    void setPolynom(int power, const int* polynom);
    const int getPower() const;
    
    
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);
    
    const int& operator[] (int index) const;
    int& operator[](int index);
    int operator()(int toApply) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& polyn);
};

Polynomial determineHigherDegreePolynom(const Polynomial& lhs,const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);


bool operator==(const Polynomial& lhs, const Polynomial& rhs);
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
