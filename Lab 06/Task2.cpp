# include <iostream>
# include <string>

using namespace std;

class Vehicle
{
    protected:
        string brand;
        int speed;

    public:
        Vehicle(string b, int s) : brand(b), speed(s) {}

        void virtual displayDetails()
        {
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
        }
};

class Car: public Vehicle
{
    protected: 
        int seats;

    public:
        Car(string b, int sp, int s) : Vehicle(b, sp), seats(s) {}

        void displayDetails() override
        {
            Vehicle :: displayDetails();
            cout << "Seating Capacity: " << seats << endl;
        }
};

class ElectricCar: public Car
{
    private:
        int batteryLife;

    public: 
        ElectricCar(string b, int sp, int s, int bl): Car(b, sp, s), batteryLife(bl) {}

        void displayDetails() override
        {
            Car ::displayDetails();
            cout << "Battery Life: " << batteryLife << endl;
        }
};

int main()
{
    ElectricCar myElectricCar("Tesla", 150, 5, 12);

    cout << "Electric Car Details:" << endl;
    myElectricCar.displayDetails();
}
