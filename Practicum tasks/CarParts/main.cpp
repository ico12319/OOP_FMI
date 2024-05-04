#include "Car.h"

int main(int argc, const char * argv[]) {
   
    
    Tyres tyre1(2313, "Ivan Chicev", "Cool", 178, 54, 15);
    Tyres tyre2(67699, "Michelin", "Trash", 132, 43, 19);
    Tyres tyre3(5645, "Vinin", "Cool", 143, 67, 21);
    Tyres tyre4(2790, "Vs", "Cool", 181, 57, 29);


    Tyres tyres[] = {tyre1,tyre2,tyre3,tyre4};
    
    FuelTank tank(200);
    FuelTank tank2(400);
    
    Accumulator accum(421, "Ivan Milin", "quliaty", 40000, "Kiks");
    
    Engine engine(414124, "Vica", "shit", 156);
    Engine engine2(5321434, "Mich", "cool", 200);
    
    
    Car car(tank, engine, tyres, accum, 300, 500);
    Car car3(tank, engine, tyres, accum, 300, 500);
    Car car2(tank2, engine2, tyres, accum, 100, 750);
    
    //try{
        //car.drive(20);
    //}
    //catch(const insufficient_fuel_error& i){
        //std::cout<<i.what()<<std::endl;
    //}
    
    
    //car.print();
    
    Car* winner =  dragRace(&car,&car2);
    if(winner!=nullptr){
        std::cout<<winner->getEngine();
    }
    else{
        std::cout<<"Draw!"<<std::endl;
    }
    
    
}
