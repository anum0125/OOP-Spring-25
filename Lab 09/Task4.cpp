#include <iostream>
using namespace std;


class PaymentMethod 
{
    public:
        virtual bool processPayment(double amount) = 0; 
};


class CreditCard : public PaymentMethod 
{
private:
    string cardNumber;

public:
    CreditCard(string cardNum) : cardNumber(cardNum) {}

    bool processPayment(double amount) override
    {
        cout << "Processing credit card payment of $" << amount << " using card: " << cardNumber << endl;
        return true; 
    }
};

class DigitalWallet : public PaymentMethod 
{
    private:
        double balance;

    public:
        DigitalWallet(double Balance) : balance(Balance) {}

        bool processPayment(double amount) override 
        {
            if (balance >= amount) 
            {
                balance -= amount;
                cout << "Digital wallet payment of $" << amount << " processed. Remaining balance: $" << balance << endl;
                return true;
            } 
            else 
            {
                cout << "Digital wallet payment failed. Insufficient balance." << endl;
                return false;
            }
        }

        double getBalance() const 
        {
            return balance;
        }
};

int main() 
{
    CreditCard myCard("23A90KLP69796");
    DigitalWallet myWallet(100.0);

    myCard.processPayment(50.0);
    myWallet.processPayment(30.0);
    myWallet.processPayment(80.0); 

    return 0;
}
