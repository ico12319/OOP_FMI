#include "ImmutableString.h"

int main(int argc, const char * argv[]) {
    
    ImmutableString str = "Kisata";
    ImmutableString str2 = "Kisata";
    ImmutableString str3 = "Ashonesa";
    std::cout<<str.length()<<std::endl;
    std::cout<<(str3 < str)<<std::endl;
    
    
}
