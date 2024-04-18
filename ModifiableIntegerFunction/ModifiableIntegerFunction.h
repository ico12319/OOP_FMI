
#include <stdint.h>

class ModifiableIntegerFunction{
    
public:
    static const int SIZE = 65535;
    int16_t(*func) (int16_t);
    int16_t modificatedResults[SIZE];
    bool isPointExcluded[SIZE] = {false};
    
    
public:
    ModifiableIntegerFunction() = default;
    ModifiableIntegerFunction(int16_t (*base) (int16_t));
    
    void setResult(int16_t value, int16_t result);
    void excludePoint(int16_t value);
    int16_t operator()(int16_t value);
    bool isInjective()const;
    bool isSurjective()const;
    bool isBijective()const;
    
    
    ModifiableIntegerFunction& operator+=(const ModifiableIntegerFunction& other);
    ModifiableIntegerFunction& operator-=(const ModifiableIntegerFunction& other);
    
    
};
bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator!=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
ModifiableIntegerFunction operator^(const ModifiableIntegerFunction& func, int times);
ModifiableIntegerFunction operator+(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
ModifiableIntegerFunction operator-(const ModifiableIntegerFunction& lhs,const ModifiableIntegerFunction& rhs);
ModifiableIntegerFunction operator*(ModifiableIntegerFunction& lhs, ModifiableIntegerFunction& rhs);
