#include "Variable.h"


class UnaryOperation : public Expression{
    
protected:
    Expression* expr;
    
    void copy(const UnaryOperation& other);
    void move(UnaryOperation&& other);
    void destroy();
    
public:
    UnaryOperation(const Expression* expr);
    UnaryOperation(const UnaryOperation& other);
    UnaryOperation& operator=(const UnaryOperation& other);
    UnaryOperation& operator=(UnaryOperation&& other);
    UnaryOperation(UnaryOperation&& other);
    ~UnaryOperation();
    
    
    
    
};
