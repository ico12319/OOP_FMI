#include <stdio.h>
#include "PartialFunction.hpp"


template<class Func,class T>
class PartialFunctionByCriteria : public PartialFunction<T>{
    
private:
    Func func;
    ExcludedPoints excludedPoints;
    
    
public:
    PartialFunctionByCriteria(const Func& func,const ExcludedPoints& excluded);
    virtual bool isDefined(int point) const override;
    virtual T operator()(int x) const override;
    virtual PartialFunction<T>* clone()const override;
};


template <class Func,class T>
PartialFunctionByCriteria<Func, T>::PartialFunctionByCriteria(const Func& func,const ExcludedPoints& excluded){
    this->func = func;
    this->excludedPoints = excluded;
}

template <class Func,class T>
T PartialFunctionByCriteria<Func,T>::operator()(int x) const{
    return Pair(isDefined(x),func(x));
}

template <class Func,class T>
bool PartialFunctionByCriteria<Func,T>::isDefined(int point) const{
    for(int i = 0;i<excludedPoints.getSize();i++){
        if(point == excludedPoints.getElementOnIndex(i))
            return false;
    }
    return true;
}

template<class Func,class T>
PartialFunction<T>* PartialFunctionByCriteria<Func,T>::clone() const{
    return new PartialFunctionByCriteria<Func,T>(*this);
}
