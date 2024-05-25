#include "ValueFiller.h"


class ExcludedPoints : public ValueFiller{
    
    
public:
    ExcludedPoints() = default;
    ExcludedPoints(const char* filePath);
};
