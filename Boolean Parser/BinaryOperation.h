#include "Negation.h"


class BinaryOperation : public Expression{
    
protected:
    Expression* left;
    Expression* right;
    
    void copy(const BinaryOperation& other);
    void move(BinaryOperation&& other);
    void destroy();
    
public:
    BinaryOperation(const Expression* left,const Expression* right);
    BinaryOperation(const BinaryOperation& other);
    BinaryOperation(BinaryOperation&& other);
    BinaryOperation& operator=(const BinaryOperation& other);
    BinaryOperation& operator=(BinaryOperation&& other);
    ~BinaryOperation();
    
};
