#include "StringView.h"

int main(int argc, const char * argv[]) {
    String str = "Hello";
    String str2 = "Ivan";
    str+=str2;
    String str3 = str + str2;
    StringView view = str;
    auto newView = view.substr(1, 3);
    std::cout<<newView<<std::endl;
}
