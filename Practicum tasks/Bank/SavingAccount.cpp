#include <stdio.h>
#include "SavingAccount.h"
#include <iostream>


SavingAccount::SavingAccount(int uniqueNum, double balance, double interestRate) : BankAccount(uniqueNum,balance){
    this->interestRate = interestRate;
}

void SavingAccount::calculateInterest(){
    double interest = getBalance() * (interestRate / 100);
    deposit(interest);
    std::cout<< "Your interest is "  << interest <<" lv." << std::endl;
}


