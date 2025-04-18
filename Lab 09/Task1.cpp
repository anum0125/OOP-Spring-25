# include <iostream>
using namespace std;

class Vehicle
{
    protected:
        string model;
        double rate;

    public:
        Vehicle(string m, double r): model(m), rate(r){}
        Vehicle(){}
        virtual double getDailyRate() = 0;

        virtual void displayDetails() = 0;

};

class Car: public Vehicle
{
    public:
        Car(string m, double r): Vehicle(m, r){}

        Car(){}

        double getDailyRate() override
        {
            return rate;
        }

        void displayDetails() override
        {
            cout << "The model of the car is: " << model << endl;
            cout << "The rental rate of the car is: " << rate << endl;
        }
};

class Bike: public Vehicle
{
    public:
        Bike(string m, double r): Vehicle(m, r){}

        double getDailyRate() override
        {
            return rate;
        }

        void displayDetails() override
        {
            cout << "The model of the bike is: " << model << endl;
            cout << "The rental rate of the bike is: " << rate << endl;
        }
};

int main()
{
    Vehicle* array[2];
    
    Car c1("Honda", 2500);
    Bike b1("Unique", 500);

    array[0] = &c1;
    array[1] = &b1;
    
    for (int i = 0; i < 2; i++)
    {
        array[i]->displayDetails();
        cout << "Rate: " << array[i]->getDailyRate() << "\n" << endl;

    }

  
}
