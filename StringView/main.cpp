#include "StringView.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    String str = "Ivan";
    StringView res(str);
    try{
        StringView res2 = res.substring(1, 3);
        std::cout<<res2<<std::endl;
    }
    catch(std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    
    std::cout<<res<<std::endl;
    
}
