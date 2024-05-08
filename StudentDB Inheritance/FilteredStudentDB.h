#include "SortedStudentDB.h"

class FilteredStudentDB : public StudentDB{
    
public:
    FilteredStudentDB() : StudentDB(){};
    void filter(bool (*criteria) (const Student*));
    void limit(size_t N);
};
