#include "BinaryOperation.h"


class Conjunction : public BinaryOperation{
    
    
public:
    Conjunction(const Expression* left,const Expression* right);
    virtual bool eval(const BooleanInterpretation& interp) const override;
    virtual Expression* clone() const override;
    
};
