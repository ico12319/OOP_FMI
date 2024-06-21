#include <stdio.h>
#include "Parser.h"

Expression* parser(StringView str){
    str = str.substr(1,str.length() - 2);
    if(str.length() == 1)
        return new Variable(str[0]);
    
    size_t count  = 0;
    for(int i = 0;i<str.length();i++){
        if(str[i] == '('){
            count++;
        }
        else if(str[i] == ')'){
            count--;
        }
        if(count == 0){
            switch (str[i])
            {
                case '!': return new Negation(parser(str.substr(i + 1, str.length() - i - 1)));
                case '&': return new Conjunction(parser(str.substr(0, i)), parser(str.substr(i + 1, str.length() - i - 1)));
                case '|': return new Disjunction(parser(str.substr(0, i)), parser(str.substr(i + 1, str.length() - i - 1)));
            }
        }
    }
    return nullptr;
}
