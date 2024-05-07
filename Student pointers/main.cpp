#include <iostream>
#include "StudentArray.h"

int main(int argc, const char * argv[]){
    
    
    StudentArray students;
    
    Student student5("Mrusa",1234, "IS");
    Student student4("Arba",1234, "IS");
    Student student2("Chica",1234, "IS");
    Student student3("Kisa", 6666, "KN");
    Student student1("Mishaka", 3213, "KS");
    Student student6("Isho", 5414, "RU");
    
    
    try{
        Student st = students.getBack();
        st.printStudent();
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    
}
