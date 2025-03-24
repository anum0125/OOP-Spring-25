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
        void convertTo(double targetRate)
        {
            double temp = convertToBase();
            cout << "Converted to Target Currency!" << endl;
            cout <<  "Targeted Currency: " << temp / targetRate << endl;
        }
        virtual void displayCurrency() = 0;

        virtual ~Currency() {}
};

class Dollar : public Currency 
{
    public:
        Dollar(double amt, double rate) : Currency(amt, "USD", "$", rate) {}

        double convertToBase() override 
        {
            cout << "Dollar converted to Base Currency!" << endl;
            cout << "Base Currency: " << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }

        void displayCurrency() override 
        {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Euro : public Currency 
{
    public:
        Euro(double amt, double rate) : Currency(amt, "EUR", "€", rate) {}

        double convertToBase() override 
        {
            cout << "Euro converted to Base Currency!" << endl;
            cout << "Base Currency: " << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }

        void displayCurrency() override 
        {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Rupee : public Currency 
{
    public:
        Rupee(double amt, double rate) : Currency(amt, "INR", "₹", rate) {}

        double convertToBase() override 
        {
            cout << "Rupee converted to Base Currency!" << endl;
            cout << "Base Currency: " << amount * exchangeRate << endl;
            return amount * exchangeRate;
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
        new Dollar(100, 20),
        new Euro(85, 25),
        new Rupee(7500, 10)
    };

    int size = sizeof(currencies) / sizeof(currencies[0]);

    for (int i = 0; i < size; i++) 
    {
        currencies[i]->displayCurrency();
        currencies[i]->convertTo(1.5);
        cout << "----------------------" << endl;
        delete currencies[i];
    }

    return 0;
}
