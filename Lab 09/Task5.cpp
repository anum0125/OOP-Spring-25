#include <iostream>
using namespace std;

class Activity 
{
    public:
        virtual double calculateCaloriesBurned() = 0; 
};

class Running : public Activity 
{
    private:
        double distance; // km
        double time;     // min

    public:
        Running(double dist, double t) : distance(dist), time(t) {}

        double calculateCaloriesBurned() override 
        {
            // Basic formula: calories = 1.036 * weight (assume 70kg) * distance ---> from internet
            double calories = 1.036 * 70 * distance;
            return calories;
        }
};

class Cycling : public Activity 
{
    private:
        double speed; // km/h
        double time;  // hrs

    public:
        Cycling(double s, double t) : speed(s), time(t) {}

        double calculateCaloriesBurned() override {
            // Basic formula: calories = MET value * weight * time (hours) ---> from internet
            // MET varies with speed; assume MET = 8.0 for moderate cycling ---> from internet
            double MET = 8.0;
            double calories = MET * 70 * time;
            return calories;
        }
};

int main() 
{
    Running run(5.0, 30.0);    
    Cycling cycle(20.0, 1.0);   

    cout << "Calories burned while running: " << run.calculateCaloriesBurned() << " kcal" << endl;
    cout << "Calories burned while cycling: " << cycle.calculateCaloriesBurned() << " kcal" << endl;

    return 0;
}
