#include <iostream>

class ExcludedPoints {
private:
    void copyFrom(const ExcludedPoints&);
    void free();
    void resize(unsigned);

    int16_t* excludedPoints;
    uint16_t capacity;
    uint16_t size;
    
public:
    ExcludedPoints();
    ExcludedPoints(const ExcludedPoints&);
    ExcludedPoints& operator=(const ExcludedPoints&);
    ~ExcludedPoints();

    // Functionality:
    bool isExcluded(int16_t) const;
    unsigned getSize() const;
    void excludePoint(int16_t);

    // Operators:
    friend std::ostream& operator<<(std::ostream& os, const ExcludedPoints& obj);
    friend std::istream& operator>>(std::istream& is, ExcludedPoints& obj);
    
};
