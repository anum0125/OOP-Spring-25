# include <iostream>
using namespace std;

class humidity;

class temperature
{
    float temperature_in_celsius;

    public: 
        temperature(float t): temperature_in_celsius(t){}

        temperature(){}

        friend float calculateHeatIndex(temperature const &t, humidity const &h);
};

class humidity
{
    float humidity_in_percentage;

    public:
        humidity(float h): humidity_in_percentage(h){}

        humidity(){}

        friend float calculateHeatIndex(const temperature &t, const humidity &h);
};

float calculateHeatIndex(const temperature &t, const humidity &h)
{
    float heatIndex = (t.temperature_in_celsius + 0.33) * (h.humidity_in_percentage - 0.7);
    return heatIndex;
}

int main()
{
    temperature t1(32); // 32 degree celsius
    humidity h1(70); // 70% humidity

    float heatIndex = calculateHeatIndex(t1, h1);
    cout << "The calculated heat index is: " << heatIndex << endl;
}
