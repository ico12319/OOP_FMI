#include "FunctionCrafter.h"

PartialFunction<Pair>* crafter(std::ifstream& ifs){
    
    int16_t N;
    int16_t T;
    
    ifs.read((char*) &N,sizeof(int16_t));
    ifs.read((char*) &T,sizeof(int16_t));
    
    if(T == 0){
        int32_t* points = new int32_t[N];
        ifs.read((char*)points, sizeof(int32_t) * N);
        int32_t* values = new int32_t[N];
        ifs.read((char*)values,sizeof(int32_t) * N);
        FunctionWithStandartValue func(points, N, values);
        PartialFunction<Pair>* toReturn = new PartialFunctionByCriteria<FunctionWithStandartValue, Pair>(func);
        return toReturn;
    }
    else if(T == 1){
        int32_t* points = new int32_t[N];
        ifs.read((char*)points,sizeof(int32_t) * N);
        FunctionWithExcludedValues func(points, N);
        PartialFunction<Pair>* toReturn = new PartialFunctionByCriteria<FunctionWithExcludedValues, Pair>(func);
        return toReturn;
    }
    else if(T == 2){
        int32_t* points = new int32_t[N];
        ifs.read((char*)points,sizeof(int32_t) * N);
        FunctionWithConstantValues func(points, N);
        PartialFunction<Pair>* toReturn = new PartialFunctionByCriteria<FunctionWithConstantValues, Pair>(func);
        return toReturn;
    }
    else if(T == 3){
        PartialFunction<Pair>** arr = new PartialFunction<Pair>*[N];
            for(int i = 0;i<N;i++){
                char buff[1024];
                ifs.getline(buff,1024);
                std::ifstream newIfs(buff,std::ios::binary);
                i++;
                arr[i] = crafter(newIfs); // the maximum and minimum class should be fixed and the recursive function
              
        }
        MaximumFunction<Pair> func(arr , N);
        PartialFunction<Pair>* result = &func;
        return result;
        
    }
    else
        return nullptr;
}
