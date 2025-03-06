# include <iostream>
# include <string>
using namespace std;

class Account
{
    protected:
        int accountNumber;
        float balance;

    public:
        Account(int a, float b): accountNumber(a), balance(b) {}

        void virtual displayDetails()
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingAccount: public Account
{
    private: 
        float interestRate;

    public: 
        SavingAccount(int a, float b, float i): Account(a, b), interestRate(i) {}

        void displayDetails() override
        {
            Account :: displayDetails();
            cout << "Interest Rate: " << interestRate << endl;
        }
};

class CheckingAccount: public Account
{
    private:
        float overdraftLimit;

    public:
        CheckingAccount(int a, float b, float o): Account(a, b), overdraftLimit(o) {}

        void displayDetails() override 
        {
            Account :: displayDetails();
            cout << "Overdraft Limit: " << overdraftLimit << endl;
        }
};

int main()
{
    SavingAccount s1(101, 5000.0, 4.5);
    cout << "Saving Account Details: " << endl;
    s1.displayDetails();

    CheckingAccount c1(102, 2000.0, 500.0);
    cout << "\nChecking Account Details: " << endl;
    c1.displayDetails();
}


