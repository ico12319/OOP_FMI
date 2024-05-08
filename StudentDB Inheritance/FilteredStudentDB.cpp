#include <stdio.h>
#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(bool (*criteria) (const Student*)){
    for(int i = studentsCount - 1;i>=0;i--){
        if(!criteria(students[i])){
            remove(*students[i]);
        }
    }
}


void FilteredStudentDB::limit(size_t N){
    if (N >= getStudentsCount()) {
               return;
    }

           // Remove students beyond the first N
    for (size_t i = studentsCount - 1; i >= N; i--) {
        remove(*students[i]);
    }
    
}
