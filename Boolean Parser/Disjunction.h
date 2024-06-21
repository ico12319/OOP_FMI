#include "Conjunction.h"


class Disjunction : public BinaryOperation{
    
    
public:
    Disjunction(const Expression* left,const Expression* right);
    virtual bool eval(const BooleanInterpretation& interp) const override;
    virtual Expression* clone() const override;
    
};
