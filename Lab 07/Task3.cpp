#include <iostream>
#include <string>
using namespace std;

class Currency 
{
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate;
    public:
        Currency(double amt, string code, string symbol, double rate)
            : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

        virtual double convertToBase() = 0;
        virtual double convertTo(double targetRate) = 0;
        virtual void displayCurrency() = 0;

        virtual ~Currency() {}
};

class Dollar : public Currency 
{
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

        double convertToBase() override 
        {
            return amount * exchangeRate;
        }

        double convertTo(double targetRate) override 
        {
            return convertToBase() / targetRate;
        }

        void displayCurrency() override 
        {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Euro : public Currency 
{
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

        double convertToBase() override 
        {
            return amount * exchangeRate;
        }

        double convertTo(double targetRate) override 
        {
            return convertToBase() / targetRate;
        }

        void displayCurrency() override 
        {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Rupee : public Currency 
{
    public:
        Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}

        double convertToBase() override 
        {
            return amount * exchangeRate;
        }

        double convertTo(double targetRate) override 
        {
            return convertToBase() / targetRate;
        }

        void displayCurrency() override 
        {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

int main() 
{
    Currency* currencies[] = 
    {
        new Dollar(100),
        new Euro(85),
        new Rupee(7500)
    };

    int size = sizeof(currencies) / sizeof(currencies[0]);

    for (int i = 0; i < size; i++) 
    {
        currencies[i]->displayCurrency();
        cout << "Converted to base: " << currencies[i]->convertToBase() << endl;
        cout << "Converted to USD: " << currencies[i]->convertTo(1.0) << endl;
        cout << "----------------------" << endl;
        delete currencies[i];
    }

    return 0;
}
