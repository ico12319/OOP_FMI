#include <iostream>


const int ALPHABET_SIZE = 26;

class BooleanInterpretation{
    
private:
    bool variablesValues[ALPHABET_SIZE] {false};
    
public:
    BooleanInterpretation() = default;
    BooleanInterpretation(const bool* variablesValues);
    bool getVariableValue(char var) const;
    void setVariableValue(char var,bool value);
    
};
