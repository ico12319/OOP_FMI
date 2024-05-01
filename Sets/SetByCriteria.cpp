#include "SetByCriteria.h"

void SetByCriteria::fill(bool (*pred) (unsigned)){
    for(int i = 0;i<getMaxNum();i++){
        if(pred(i)){
            add(i);
        }
    }
}

SetByCriteria::SetByCriteria(unsigned maxNum,bool(*pred) (unsigned)) : DynamicSet(maxNum){
    fill(pred);
}


