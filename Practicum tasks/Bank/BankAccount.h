

class BankAccount{
    
protected:
    int uniqueNum = 0;
    double balance = 0;
    
public:
    BankAccount() = default;
    BankAccount(int uniqueNum, double balance);
    
    void deposit(double amount);
    virtual void withdraw(double amount);
    double getBalance() const;
    
    
};
