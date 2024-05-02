#include <stdio.h>
#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(int uniqueNum, double balance){
    this->uniqueNum = uniqueNum;
    this->balance = balance;
}

void BankAccount::deposit(double amount){
    this->balance += amount;
}

void BankAccount::withdraw(double amount){
    if(amount > this->balance){
        std::cout<<"Insufficient funds!"<<std::endl;
    }
    this->balance -= amount;
}

double BankAccount::getBalance() const{
    return this->balance;
}
