#include <iostream>
#include "LoanAccount.h"

int main(int argc, const char * argv[]) {
    BankAccount bank(65432,150);
    bank.deposit(23);
    bank.deposit(12.50);
    SavingAccount savings(231, 31231, 23);
    savings.calculateInterest();
    
    CheckingAccount check(41241, 32);
    check.withdraw(54);
    std::cout<<check.getBalance()<<std::endl;
    
}
