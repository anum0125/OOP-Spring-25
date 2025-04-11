#include <iostream>
using namespace std;

class Fraction 
{
    private:
        int numerator;
        int denominator;

    public:
        Fraction(){}

        Fraction(int n, int d) : numerator(n) 
        {
            if (d == 0) 
            {
                cout << "Denominator cannot be zero." << endl;
                denominator = 1;
            }
            else
            {
                denominator = d;
            }
        }

        Fraction operator+(const Fraction& other) const 
        {
            int num = numerator * other.denominator + other.numerator * denominator;
            int den = denominator * other.denominator;
            return Fraction(num, den);
        }

        Fraction operator-(const Fraction& other) const 
        {
            int num = numerator * other.denominator - other.numerator * denominator;
            int den = denominator * other.denominator;
            return Fraction(num, den);
        }

        Fraction operator*(const Fraction& other) const 
        {
            return Fraction(numerator * other.numerator, denominator * other.denominator);
        }

        Fraction operator/(const Fraction& other) const
        {
            return Fraction(numerator * other.denominator, denominator * other.numerator);
        }

        friend ostream& operator<<(ostream& os, const Fraction& f) 
        {
            os << f.numerator << "/" << f.denominator;
            return os;
        }
    };

int main() {
    Fraction f1(2, 5);   
    Fraction f2(3, 4);   

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    return 0;
}

