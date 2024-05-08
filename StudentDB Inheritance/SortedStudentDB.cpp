#include <stdio.h>
#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(bool (*compare) (const Student*,const Student*)){
    for(int i = 0;i<studentsCount - 1;i++){
        for(int j = 0;j<studentsCount - i - 1;j++){
            if(compare(students[j],students[j+1])){
                std::swap(students[j],students[j+1]);
            }
        }
    }
}
