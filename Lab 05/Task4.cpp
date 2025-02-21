# include <iostream>
# include <string>

using namespace std;

class Battery
{
    int capacity;

    public:

    Battery(int capacity) : capacity(capacity){}

    void displayBatterySpecifications()
    {
        cout << "The capacity of the battery is: " << capacity << " mAh" << endl;
        cout << "--------------------------------------------" << endl;
    }
};

class SmartPhone
{
    string model;
    int RAM;
    int ROM;
    Battery b;

    public:

    SmartPhone(string model, int RAM, int ROM, Battery b) : model(model), RAM(RAM), ROM(ROM), b(b){}

    ~SmartPhone()
    {
        
    }

    void diplay()
    {
        cout << "--------------------------------------------" << endl;
        cout << "SmartPhones Specifications: " << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << RAM << endl;
        cout << "ROM: " << ROM << endl;
        b.displayBatterySpecifications();
    }
};

int main()
{
    Battery b1(6000);
    SmartPhone s1("S24 5G", 8, 256, b1);
    s1.diplay();
}
