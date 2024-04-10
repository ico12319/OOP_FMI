#include "GraduatedStudent.h"

int main(){
    
    int size = 5;
    int* grades = new int[size];
    grades[0] = 2;
    grades[1] = 3;
    grades[2] = 2;
    grades[3] = 2;
    grades[4] = 4;
    
    GraduatedStudent student("Ivan",grades,size,"I love Chica");

    student.printStudent();
    
    delete[]grades;
    
    
    
    
    
}
