#include <stdio.h>
#include "CheckingAccount.h"
#include <iostream>


CheckingAccount::CheckingAccount(int uniqueNum, double balance) : BankAccount(uniqueNum,balance){}

void CheckingAccount::withdraw(double amount){
    
    balance -= amount;
    if(balance < 0){
        std::cout<<"Warning! Negative balance!"<<std::endl;
    }
}
