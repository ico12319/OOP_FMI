#include <iostream>
#include "FilteredStudentDB.h"

bool sortByFacultyNumber(const Student* s1, const Student* s2) {
    return s1->getFn() > s2->getFn();
}

bool compareByFn(const Student* s1, const Student* s2) {
    return s1->getFn() < s2->getFn();
}

bool filterByGrade(const Student* student) {
    return student->getYear() >= 3;
}


int main(){
    
    Student student1("Kisata", 2346, 3);
    Student student2("Ivan", 6765, 1);
    Student student3("Nadenko", 1452, 4);
    Student student4("Orlad", 1545, 2);
    
    SortedStudentDB sorted;

        // Adding students to the FilteredStudentDB object
    sorted.add(student1);
    sorted.add(student2);
    sorted.add(student3);
    sorted.add(student4);

        // Filtering students with a grade greater than or equal to 3
    //sorted.sortBy(sortByFacultyNumber);

    //sorted.display();
    
    FilteredStudentDB filtered;

    filtered.add(student1);
    filtered.add(student2);
    filtered.add(student3);
    filtered.add(student4);
    
    //filtered.filter(filterByGrade);
    filtered.limit(3);
    
    filtered.display();
    
    
    
    
    
}

