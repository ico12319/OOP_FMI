#include <stdio.h>
#include "PartialFunctionByCriteria.hpp"

template<class T>
class MaximumPartialFunction : public PartialFunction<T>{
    
private:
    PartialFunction<T>** functions;
    size_t functionsCount;
    
    
public:
    MaximumPartialFunction(const PartialFunction<T>** funcs, size_t size);
    virtual T operator()(int point) const override;
    virtual bool isDefined(int x) const override;
    virtual ~MaximumPartialFunction();
    virtual PartialFunction<T>* clone() const override;
    
};

template<class T>
PartialFunction<T>* MaximumPartialFunction<T>::clone() const{
    return new MaximumPartialFunction<T>(*this);
}

template<class T>
MaximumPartialFunction<T>::MaximumPartialFunction(const PartialFunction<T>** funcs,size_t size){
    this->functions = new PartialFunction<T>*[size];
    for(int i = 0;i<size;i++){
        this->functions[i] = funcs[i]->clone();
    }
    this->functionsCount = size;
}
template<class T>
bool MaximumPartialFunction<T>::isDefined(int x) const{
    for (int i = 0; i < functionsCount; i++) {
        if (!functions[i]->isDefined(x)) {
            return false;
        }
    }
    return true;
}

template<class T>
T MaximumPartialFunction<T>::operator()(int point) const{
    if (!isDefined(point)) {
        throw std::logic_error("Function is not defined at this point");
    }

    int maxValue = -1;
    for (size_t i = 0; i < functionsCount; ++i) {
        int value = functions[i]->operator()(point).getValue();
        maxValue = std::max(maxValue, value);
    }
    return Pair(true,maxValue);
}

template<class T>
MaximumPartialFunction<T>::~MaximumPartialFunction(){
    for (int i = 0; i < functionsCount; i++) {
        delete functions[i];
    }
    delete[] functions;
}
