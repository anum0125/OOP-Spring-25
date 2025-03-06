# include <iostream>
# include <string>
using namespace std;

class Device
{
    protected:
        int deviceID;
        bool status;

    public:
        Device(int d, bool s): deviceID(d), status(s) {}

        void virtual displayDetails()
        {
            cout << "Device ID: " << deviceID << endl;
            cout << "Status: " << status << endl;
        }

};

class SmartPhone: public Device
{
    protected:
        float screenSize;

    public:
        SmartPhone(int d, bool s, float ss): Device(d,s), screenSize(ss) {}
        
        void displayDetails() override
        {
            Device :: displayDetails();
            cout << "Screen Size: " << screenSize << endl;
        }
};

class SmartWatch: public Device
{
    protected:
        bool heartRateMonitor;

    public:
        SmartWatch(int d, bool s, bool h): Device(d,s), heartRateMonitor(h) {}
        
        void displayDetails() override
        {
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
        }
};

class SmartWearable: public SmartPhone, public SmartWatch
{
    protected:
        int stepCounter;

    public: 
        SmartWearable(int d, bool s, float ss, bool h, int sc): SmartPhone(d, s, ss), SmartWatch(d, s, h), stepCounter(sc) {}

        void displayDetails() override
        {
            SmartPhone :: displayDetails();
            SmartWatch :: displayDetails();
            cout << "Step Counter: " << stepCounter << endl;
        }
};

int main()
{
    SmartWearable w1(1001, true, 5.5, true, 5000);
    
    cout << "Smart Wearable Device Details:" << endl;
    w1.displayDetails();
}
