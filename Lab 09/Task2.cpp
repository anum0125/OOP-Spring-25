# include <iostream>
using namespace std;

class SmartDevice
{
    public:

        SmartDevice(){}
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool getStatus() = 0; 
};

class LightBulb: public SmartDevice
{
    private:
        bool isOn;
        int brightness;

    public:
        LightBulb(bool i, int b):isOn(i), brightness(b){}

        void turnOn()
        {
            if (isOn == true)
            {
                cout << "The light bulb is already turned on!" << endl;
            }
            else
            {
                isOn = true;
                cout << "The light bulb has been turned on!" << endl;
            }
            
        }

        void turnOff()
        {
            if (isOn == false)
            {
                cout << "The light bulb is already turned off!" << endl;
            }
            else
            {
                isOn = true;
                cout << "The light bulb has been turned off!" << endl;
            }
            
        }

        bool getStatus()
        {
            return isOn;
        }
};

class Thermostat: public SmartDevice
{
    private:
        bool isOn;
        double temperature;

    public:
        Thermostat(bool i, double t): isOn(i), temperature(t){}

        void turnOn()
        {
            if (isOn == true)
            {
                cout << "The Thermostat is already turned on!" << endl;
            }
            else
            {
                isOn = true;
                cout << "The Thermostat has been turned on!" << endl;
            }
            
        }

        void turnOff()
        {
            if (isOn == false)
            {
                cout << "The Thermostat is already turned off!" << endl;
            }
            else
            {
                isOn = true;
                cout << "The Thermostat has been turned off!" << endl;
            }
            
        }
        
        bool getStatus()
        {
            return isOn;
        }
};

int main()
{
    LightBulb l1(false, 75);
    Thermostat t1(true, 54.2f);

    l1.turnOn();
    t1.turnOff();

    cout << "Light Bulb's Status: " << l1.getStatus() << endl;
    cout << "Thermostats's Status: " << t1.getStatus() << endl;
}
