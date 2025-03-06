 # include <iostream>
 # include <string>

 using namespace std;

 class Employee
 {
    protected:

        string name;
        float salary;

    public:

        Employee(string name, float salary) : name(name), salary(salary) {}

        virtual void displayDetails()
        {
            cout << "The name of the employee: " << name << endl;
            cout << "Salary of the employee: " << salary << endl;
        }
};

class Manager: public Employee
{
    private:

        float bonus;

    public:

        Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}

        void displayDetails() override
        {
            Employee :: displayDetails();
            cout << "Bonus for the employee: " << bonus << endl;
        }

};

int main()
{
    string n;
    float s, b;

    cout << "Enter the name of the manager: " << endl;
    cin >> n;

    cout << "Enter the salary of the manager: " << endl;
    cin >> s;

    cout << "Enter the bonus for the manager: " << endl;
    cin >> b;


    Manager m1(n, s, b);

    cout << "\nManager Details:" << endl;
    m1.displayDetails();
}
