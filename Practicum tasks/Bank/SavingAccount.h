#include "BankAccount.h"

class SavingAccount : public BankAccount{
    
private:
    double interestRate = 0;
    
public:
    SavingAccount(int uniqueNum,double balance,double interesRate);
    void calculateInterest();
};


