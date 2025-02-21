# include <iostream>
# include <string>

using namespace std;

 class Car
 {
    int *registration_number;
    string model;
    string owner;
    static int CarCounter;

    public:

    Car(string m, string o) : model(m), owner(o)
    {
        registration_number = new int(++CarCounter);
    }

    Car (Car &obj)
    {
        registration_number = obj.registration_number;
        model = obj.model;
        cout << "Enter the name of the owner of car " << CarCounter+1 << ": " << endl;
        getline(cin, owner);
    }

    ~Car()
    {
        cout << "The object has been destructed." << endl;
        delete[] registration_number;
    }

    void display()
    {
        cout << "------------------------------------------" << endl;
        cout << "Registration Number: " << *registration_number << endl;
        cout << "Model: " << model << endl;
        cout << "Owner: " << owner << endl;
        cout << "Address of the object: " << registration_number <<endl;
        cout << "-------------------------------------------" << endl;
    }
 };

 int Car :: CarCounter = 0;

 int main()
 {
    Car car1("Honda", "Anum");
    Car car2(car1);

    car1.display();
    car2.display();
 }
