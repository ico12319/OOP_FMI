
#include <stdio.h>
#include "ExcludedPoints.h"


ExcludedPoints::ExcludedPoints() : capacity(8), size(0) {
    excludedPoints = new int16_t[capacity]{ 0 };
}



ExcludedPoints::ExcludedPoints(const ExcludedPoints& other) {
    copyFrom(other);
}

ExcludedPoints& ExcludedPoints::operator=(const ExcludedPoints& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ExcludedPoints::~ExcludedPoints() {
    free();
}

bool ExcludedPoints::isExcluded(int16_t num) const {
    for (size_t i = 0; i < size; i++) {
        if (num == excludedPoints[i]) {
            return true;
        }
    }
    return false;
}

unsigned ExcludedPoints::getSize() const {
    return size;
}



void ExcludedPoints::excludePoint(int16_t num) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    excludedPoints[size] = num;
    size++;
}

void ExcludedPoints::copyFrom(const ExcludedPoints& other) {
    capacity = other.capacity;
    size = other.size;
    excludedPoints = new int16_t[capacity];

    for (size_t i = 0; i < size; i++) {
        excludedPoints[i] = other.excludedPoints[i];
    }
}

void ExcludedPoints::free() {
    delete[] excludedPoints;
    
    
    size = capacity = 0;
}

void ExcludedPoints::resize(unsigned newCap) {
    capacity = newCap;
    int16_t* arr = new int16_t[capacity];
    for (size_t i = 0; i < size; i++) {
        arr[i] = excludedPoints[i];
    }
    delete[] excludedPoints;
    excludedPoints = arr;
}

std::ostream& operator<<(std::ostream& os, const ExcludedPoints& obj) {
    os.write((const char*)(&obj.size), sizeof(obj.size));
    os.write((const char*)(obj.excludedPoints), obj.size * sizeof(int16_t));

    return os;
}

std::istream& operator>>(std::istream& is, ExcludedPoints& obj) {
    is.read((char*)(&obj.size), sizeof(obj.size));
    obj.capacity = 2 * obj.size;
    obj.excludedPoints = new int16_t[obj.capacity]{};
    is.read((char*)(obj.excludedPoints), obj.size * sizeof(int16_t));

    return is;
}
