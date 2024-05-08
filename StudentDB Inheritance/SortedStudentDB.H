#include "StudentDB.h"

class SortedStudentDB : public StudentDB{
    
public:
    SortedStudentDB() : StudentDB(){};
    void sortBy(bool (*compare) (const Student*,const Student*));
    
    
};
