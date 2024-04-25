#include <iostream>
// done with the help of Михаел Михайлов -> 0MI0700220, Виктор Миланов -> 0MI0700270, Жоземир Кушев -> 8MI0700284, Димитър Цонев -> 72087
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

    bool isExcluded(int16_t) const;
    unsigned getSize() const;
    void excludePoint(int16_t);

    
    void serialize(std::ofstream& ofs) const;
    void deserialize(std::ifstream& ifs);
    
};
