# include <iostream>
# include <exception>
using namespace std;


class InsufficientFundsException
{
    float withdraw;
    float deficit;

    public:
        InsufficientFundsException(float w, float d): withdraw(w), deficit(d){}

        void what()
        {
            cout << "Withdraw $" << withdraw << ": InsufficientFundsException - Deficit: $" << deficit << endl;
        }
};

template<typename T>
class BankAccount
{
    public: 

        T balance;

        BankAccount(T balance): balance(balance){}

        void Deposit(T amount)
        {
            cout << "Amount Deposited!" << endl;
            balance += amount;
        }

        void Withdrawal(T amount)
        {
            try 
            {
                if (amount > balance)
                {
                    throw InsufficientFundsException(amount, amount-balance);
                    cout << "Amount Withdrawn!" << endl;
                    balance -= amount;
                }
            }
            catch(InsufficientFundsException &i)
            {
                i.what();
            }
        }
};

int main()
{
    BankAccount b1(500);
    b1.Withdrawal(750);
}
