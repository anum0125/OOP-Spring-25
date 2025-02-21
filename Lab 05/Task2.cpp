# include <iostream>
# include <string>

using namespace std;

class Patient
{
    int* id;
    int num;
    string name;
    float* results;
    static int counter;

    public:

    Patient(string name)
    {
        cout << "Enter the number of results: " << endl;
        cin >> num;
        results = new float[num];
        for (int i = 0; i < num; i++)
        {
            cout << "Enter result " << i+1 << ": " << endl;
            cin >> results[i];
        }

        id = new int (++counter);
        this->name = name;
    }

    Patient(Patient &obj)
    {
        name = obj.name;
        id = new int(*obj.id);
        num = obj.num;
        results = new float[num];
        for (int i = 0; i < num; i++)
        {
            results[i] = obj.results[i];
        }
    }

    ~Patient()
    {
        delete[] results;
        delete[] id;
    }

    void display()
    {   cout << "-------------------------------------" << endl;
        cout << "Patient's ID: " << *id << endl;
        cout << "Patient's Name: " << name << endl;
        cout << "Results: " << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "result " << i+1 << ": " << results[i] <<endl;
        }
        cout << "\nAddress of the object: " << id << endl;
        cout << "-------------------------------------" << endl;
    }
};

int Patient :: counter = 0;

int main()
{
    Patient patient1("Anum");
    Patient patient2 = patient1;

    patient1.display();
    patient2.display();
}
