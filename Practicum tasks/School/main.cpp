#include <iostream>
#include "Teacher.h"

int main(int argc, const char * argv[]) {
    
    
    char subjects[3][20] = { "English", "Mathematics", "Physics" };
    
    char** subjectsPointers = new char* [3];
    subjectsPointers[0] = subjects[0];
    subjectsPointers[1] = subjects[1];
    subjectsPointers[2] = subjects[2];

    Teacher t("Prof. Ivanov", 33, subjectsPointers, 3);

    t.printTeacher();
    delete[] subjectsPointers;
}
