# include <iostream>
using namespace std;

class Account
{
	protected:
		string accountNumber;
		float balance;
		string accountHolderName;
		string accountType;
        float array[10][2];
        int index;
		
	public:
		Account(string a, float b, string ah, string at): accountNumber(a), balance(b), accountHolderName(ah), accountType(at){index = 0}
		
		void deposit(float amount)
		{
			balance += amount;
			cout << "Current Balance: " << balance << endl;
            if (index < 9)
            {
                array[0][index] = 0;
                array[1][index] = amount;
            }
            else if (index == 9)
            {
                index = 0;
                array[0][index] = 0;
                array[1][index] = amount;
            }
            index++;
		}
		
		void withdraw(float amount)
		{
			if (amount > balance)
			{
				cout << "Insufficient Balance!" << endl;
			}
			else
			{
				balance -= amount;
			}
			cout << "Current Balance: " << balance << endl;
             if (index < 9)
            {
                array[0][index] = 1;
                array[1][index] = amount;
            }
            else if (index == 9)
            {
                index = 0;
                array[0][index] = 1;
                array[1][index] = amount;
            }
            index++;
		}
		
		void calculateInterest()
		{
			if (balance > 50000)
			{
				balance += balance*0.1;
				cout << "Interest Income: " << balance*0.1 << endl;
			}
			else if (balance > 20000)
			{
				balance += balance*0.075;
				cout << "Interest Income: " << balance*0.1 << endl;
			}
			else if (balance > 30000)
			{
				balance += balance*0.05;
				cout << "Interest Income: " << balance*0.1 << endl;
			}
			else if (balance > 30000)
			{
				balance += balance*0.025;
				cout << "Interest Income: " << balance*0.1 << endl;
			}
			else
			{
				cout << "No Interest Income Received!" << endl;
			}
		}

        void printStatement()
        {
            for (int i = 0; i < 9; i++)
            {
                
            }
        }
		
		void getAccountInfo()
		{
			cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Type: " << accountType << endl;
            cout << "Current Balance: " << balance << endl;
		}
};
		
class SavingsAccount: public Account
{
	 private:
		float interestRate;
		float minimumBalance;

    public:
        SavingsAccount(string a, float b, string ah, string at, float  i, float m): Account(a, b, ah, at), interestRate(i), minimumBalance(m){}
};
		
class CheckingAccount: public Account
{
	private:

    public:
        CheckingAccount(string a, float b, string ah, string at): Account(a, b, ah, at){}
};
		
class FixedDepositAccount: public Account
{
	private:
		string maturityDate;
		float fixedInterestRate;

    public:
        FixedDepositAccount(string a, float b, string ah, string at, string m, float f): Account(a, b, ah, at), maturityDate(m), fixedInterestRate(f){}
				
};
