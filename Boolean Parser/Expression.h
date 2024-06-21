#include "BooleanInterpretation.h"


class Expression{
    
    
public:
    virtual bool eval(const BooleanInterpretation& interp) const  = 0;
    virtual Expression* clone() const = 0;
    virtual ~Expression() = default;
    
};
