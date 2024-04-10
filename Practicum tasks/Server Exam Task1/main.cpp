#include <iostream>
#include "Server.h"

int main(int argc, const char * argv[]) {
    
    Server s;
    
    std::ifstream ifs("ExamTask1.dat",std::ios::binary);
    s.readUsers(ifs);
    s.printUsers();
    
}
