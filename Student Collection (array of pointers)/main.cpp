#include <iostream>
#include "StudentCollection.h"
#include "string"



int main(int argc, const char * argv[]) {
    
    Student st("Kisa",15);
    Student st1("Vica",15);
    
    Student st2("Misho kucheto",15);
   
    StudentCollection coll;
    coll.push(st);
    coll.pushAt(5,st2);
    coll.push(st1);
    
    coll.print();
    std::cout<<coll.getNumberInClass(st2)<<std::endl;
    std::cout<<coll.getNumberInClass(st1)<<std::endl;
}
