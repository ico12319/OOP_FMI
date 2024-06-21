#include "UnaryOperation.h"


class Negation : public UnaryOperation{
    
    
public:
    Negation(const Expression* expr);
    virtual bool eval(const BooleanInterpretation& interp) const override;
    virtual Expression* clone() const override;
    
};
