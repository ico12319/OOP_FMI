#include "Parser.h"

int main(int argc, const char * argv[]) {
    
    BooleanInterpretation boolean;
    boolean.setVariableValue('b', true);
    boolean.setVariableValue('d', false);
    boolean.setVariableValue('a', true);
    boolean.setVariableValue('p', false);
    boolean.setVariableValue('q', true);
    boolean.setVariableValue('h', false);
    
    Expression* expr = new Disjunction(new Negation(new Variable('a')),new Variable('b'));
    std::cout<<expr->eval(boolean)<<std::endl;
    Expression* expr2 = new Conjunction(new Disjunction(new Conjunction(new Variable('a'),new Variable('b')),new Disjunction(new Variable('p'),new Variable('q'))),new Negation(new Variable('h')));
    std::cout<<expr2->eval(boolean)<<std::endl;//this works
    
    StringView str = "(((a&b)|(p|q))&(!h))";
    StringView str2 = "((p)|(!p))";
    Expression* parsedExpr = parser(str);
    std::cout<<parsedExpr->eval(boolean)<<std::endl;
    
}
