#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    float balance;
    string accountHolderName;
    string accountType;
    float transactions[10][2]; //0: deposit ,1: withdraw
    int transactionCount;
    
public:
    Account(string a, float b, string ah, string at) : accountNumber(a), balance(b), accountHolderName(ah), accountType(at), transactionCount(0) {}
        
    void deposit(float amount) 
	{
        balance += amount;
        cout << "Deposited: " << amount << endl;
        
        if (transactionCount < 10) 
		{
            transactions[transactionCount][0] = 0;
            transactions[transactionCount][1] = amount;
            transactionCount++;
        } 
		else 
		{
            for (int i = 0; i < 9; i++) 
			{
                transactions[i][0] = transactions[i+1][0];
                transactions[i][1] = transactions[i+1][1];
            }
            transactions[9][0] = 0;
            transactions[9][1] = amount;
        }
    }
    
    virtual void withdraw(float amount) 
	{
        if (amount > balance) 
		{
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        
        if (transactionCount < 10) 
		{
            transactions[transactionCount][0] = 1;
            transactions[transactionCount][1] = amount;
            transactionCount++;
        } 
		else 
		{
            for (int i = 0; i < 9; i++) 
			{
                transactions[i][0] = transactions[i+1][0];
                transactions[i][1] = transactions[i+1][1];
            }
            transactions[9][0] = 1;
            transactions[9][1] = amount;
        }
    }
    
    virtual void calculateInterest() 
	{
        float interest = 0;
        if (balance > 50000) 
		{
            interest = balance * 0.1;
        } 
		else if (balance > 30000) 
		{
            interest = balance * 0.075;
        } 
		else if (balance > 20000) 
		{
            interest = balance * 0.05;
        } 
		else if (balance > 10000) 
		{
            interest = balance * 0.025;
        }
        
        if (interest > 0) 
		{
            balance += interest;
            cout << "Interest added: " << interest << endl;
        } 
		else 
		{
            cout << "No interest earned" << endl;
        }
    }
    
    void printStatement() 
	{
        cout << "\n--- Account Statement ---" << endl;
        getAccountInfo();
        cout << "\nLast 10 transactions:" << endl;
        for (int i = 0; i < transactionCount; i++) 
		{
            cout << (transactions[i][0] == 0 ? "Deposit" : "Withdraw") << ": " << transactions[i][1] << endl;
        }
    }
    
    void getAccountInfo() 
	{
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account 
{
	private:
		float interestRate;
		float minimumBalance;
		
	public:
		SavingsAccount(string a, float b, string ah, string at, float i, float m) : Account(a, b, ah, at), interestRate(i), minimumBalance(m) {}
			
		void withdraw(float amount) override 
		{
			if (balance - amount < minimumBalance) 
			{
				cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
				return;
			}
			Account::withdraw(amount);
		}
		
		void calculateInterest() override 
		{
			float interest = balance * interestRate;
			balance += interest;
			cout << "Savings interest added: " << interest << endl;
		}
};

class CheckingAccount : public Account 
{
	public:
		CheckingAccount(string a, float b, string ah, string at) : Account(a, b, ah, at) {}
			
		void withdraw(float amount) override 
		{
			Account::withdraw(amount);
		}
};

class FixedDepositAccount : public Account 
{
	private:
		string maturityDate;
		float fixedInterestRate;
		
	public:
		FixedDepositAccount(string a, float b, string ah, string at, string m, float f) : Account(a, b, ah, at), maturityDate(m), fixedInterestRate(f) {}
			
		void withdraw(float amount) override 
		{
			cout << "Cannot withdraw from Fixed Deposit before maturity date (" << maturityDate << ")" << endl;
		}
		
		void calculateInterest() override 
		{
			float interest = balance * fixedInterestRate;
			balance += interest;
			cout << "Fixed deposit interest added: " << interest << endl;
		}
};

int main() {
    SavingsAccount sa("SA123", 10000, "John Doe", "Savings", 0.05, 1000);
    CheckingAccount ca("CA456", 5000, "Jane Smith", "Checking");
    FixedDepositAccount fd("FD789", 20000, "Bob Johnson", "Fixed Deposit", "2025-12-31", 0.08);
    
    sa.deposit(5000);
    sa.withdraw(2000);
    sa.calculateInterest();
    sa.printStatement();
    
    ca.deposit(1000);
    ca.withdraw(3000);
    ca.printStatement();
    
    fd.deposit(5000);
    fd.withdraw(1000); 
    fd.calculateInterest();
    fd.printStatement();
    
    return 0;
}
