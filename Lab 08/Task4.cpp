# include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Currency 
{
    private:
        float amount;

    public:
        Currency() : amount(0.0f){}

        Currency(float a): amount(a) {}

        Currency operator-() const 
        {
            return Currency(-amount);
        }

        Currency operator+(const Currency& other) const 
        {
            return Currency(amount + other.amount);
        }

        Currency operator-(const Currency& other) const 
        {
            return Currency(amount - other.amount);
        }

        Currency& operator+=(const Currency& other) 
        {
            amount += other.amount;
            return *this;
        }

        Currency& operator-=(const Currency& other) 
        {
            amount -= other.amount;
            return *this;
        }

        friend ostream& operator<<(ostream& os, const Currency& c) 
        {
            os << c.amount << "$";
            return os;
        }
    };

    int main() 
    {
        Currency price(100.0);
        Currency tax(15.0);
        Currency discount(10.0);

        Currency total = price + tax;
        cout << "Total (Price + Tax): " << total << endl;

        Currency finalAmount = total - discount;
        cout << "Final Amount (After Discount): " << finalAmount << endl;

        total -= discount;
        cout << "Total after -= discount: " << total << endl;

        total += tax;
        cout << "Total after += tax: " << total << endl;

        Currency negated = -price;
        cout << "Negated Price: " << negated << endl;

        return 0;
}

