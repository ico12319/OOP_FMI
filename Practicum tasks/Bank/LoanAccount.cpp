#include <stdio.h>
#include "LoanAccount.h"

LoanAccount::LoanAccount(int uniqueNum, double loanAmount, double loanInterestRate) : BankAccount(uniqueNum,loanAmount){
    this->loanInterestRate = loanInterestRate;
}

void LoanAccount::applyInterest(){
    double interest = balance * (loanInterestRate / 100);
    deposit(interest);
}
