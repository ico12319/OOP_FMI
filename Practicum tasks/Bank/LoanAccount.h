#include "CheckingAccount.h"


class LoanAccount : public BankAccount{

private:
    double loanInterestRate = 0;
    
public:
    LoanAccount(int uniqueNum, double loanAmount, double loanInterestRate);
    void applyInterest();
};
