#include "DynamicSet.h"


class SetByCriteria : public DynamicSet{
    
private:
    void fill(bool (*pred) (unsigned num));
    
    
public:
    SetByCriteria() = default;
    SetByCriteria(unsigned maxNum, bool(*pred)(unsigned));
    
    
    
};
