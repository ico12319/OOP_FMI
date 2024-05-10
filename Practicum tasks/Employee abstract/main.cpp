#include "CommisionEmployee.h"


Employee* createEmployee(std::istream& is){
    std::cout<<"Enter Employee type:";
    char type;
    is >> type;
    std::cout<<std::endl;
    char name[1024];
    double salary;
    std::cout<<"Enter name:";
    is >> name;
    std::cout<<std::endl;
    std::cout<<"Enter salary: ";
    is >> salary;
    std::cout<<std::endl;
    
    if(type == 'h'){
        int overTime;
        is >> overTime;
        return new HourlyEmployee(name,salary,overTime);
    }
    else if (type == 'c'){
        size_t commison;
        is >> commison;
        return new CommisionEmployee(name,salary,commison);
    }
    
    return nullptr;
}



Employee* findMaxSalary(Employee** const coll,size_t size){
    Employee* highestPaid = nullptr;
    double maxSalary  = 0;
    for(int i = 0;i<size;i++){
        if(coll[i]->getSalary() > maxSalary){
            maxSalary = coll[i]->getSalary();
            highestPaid = coll[i];
        }
    }
    return highestPaid;
}


Employee* findMinSalary(Employee** const coll,size_t size){
    Employee* lowestPaid = nullptr;
    double minSalary  = -1;
    for(int i = 0;i<size;i++){
        if(coll[i]->getSalary() < minSalary){
            minSalary = coll[i]->getSalary();
            lowestPaid = coll[i];
        }
    }
    return lowestPaid;
}


double findAverageSalary(Employee** const coll,size_t size){
    double sum = 0;
    for(int i = 0;i<size;i++){
        sum+=coll[i]->getSalary();
    }
    
    return sum / size;
}


Employee* closestToAverage(Employee** const coll,size_t size){
    double average = findAverageSalary(coll, size);

    for(int i = 0;i<size - 1;i++){
        for(int j = 0;j<size - i - 1;j++){
            double diff1 = std::abs(coll[j]->getSalary() - average);
            double diff2 = std::abs(coll[j + 1]->getSalary() - average);
            if(diff1 > diff2){
                std::swap(coll[j],coll[j+1]);
            }
        }
    }
    return coll[0];
    
}


void sort(Employee** coll,size_t size){
    for(int i = 0;i<size - 1;i++){
        for(int j = 0; j<size - i - 1;j++){
            if(coll[j]->getSalary() < coll[j+1]->getSalary()){
                std::swap(coll[j],coll[j+1]);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    HourlyEmployee person("Kisata", 30, 2);
    person.calculateSalary();
    //std::cout<<person;
    
    
    CommisionEmployee person2("Drista", 400, 3);
    
    person2.calculateSalary();
    //std::cout<<person2;
    
    
    //Employee* emp = createEmployee(std::cin);
    //std::cout << *emp;
    
    
    Employee* arr[3];
    arr[0] = new HourlyEmployee("Misho",2,1);
    arr[1] = new CommisionEmployee("Martin",200,20);
    arr[2] = new CommisionEmployee("Ivan",100,56);
    
    //sort(arr, 3);
    //std::cout<<*arr[0];
    //std::cout<<*arr[1];
    //std::cout<<*arr[2];
    
    //Employee* emp = findMaxSalary(arr, 3);
    //std::cout<<*emp;
    
    //std::cout<<findAverageSalary(arr, 3);
    Employee* emp = closestToAverage(arr, 3);
    std::cout<<*emp;
}
