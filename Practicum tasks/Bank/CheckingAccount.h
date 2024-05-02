#include "SavingAccount.h"

class CheckingAccount : public BankAccount{
    
public:
    CheckingAccount(int unqueNum, double balance);
    
    void withdraw(double amount) override;
};
