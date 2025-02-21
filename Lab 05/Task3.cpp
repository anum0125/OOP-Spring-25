# include <iostream>
# include <string>

using namespace std;

class Professor
{
    string name;
    string department;

    public: 

    Professor() : name(""), department("") {}

    Professor(string n, string d)
    {
        name = n;
        department = d;
    }

    ~Professor(){}

    void display()
    {
        cout << "-------------------------------------" << endl;
        cout << "Professor's Name: " << name << endl;
        cout << "Professor's Department: " << department << endl;
        cout << "-------------------------------------" << endl;
    }

    string getName()
    {
        return name;
    }

    string getDepartment()
    {
        return department;
    }

};

class University
{
    Professor *professorsArray;
    Professor *p;
    int max;
    static int counter;

    public:

    University()
    {
        cout << "Enter the maximum number of professors in each department: " << endl;
        cin >> max;
        cin.ignore();

        professorsArray = new Professor[max];
    }

    ~University()
    {
        delete[] professorsArray;
    }

    void addProfessor(Professor &p)
    {
        if (counter < max)
        {
            professorsArray[counter] = p;
            counter++;
            cout << "Professor Added!" << endl;
        }
        else
        {
            cout << "The maximum capacity of professors has been reached. Cannot add more professors!" << endl;
        }
    }

    void viewDetails()
    {
        for (int i = 0; i < counter; i++)
        {
            cout << "-------------------------------------" << endl;
            cout << "Professor's Name: " << professorsArray[i].getName() << endl;
            cout << "Professor's Department: " << professorsArray[i].getDepartment() << endl; 
            cout << "-------------------------------------" << endl;
        }
    }
};



int University :: counter = 0;

int main()
{
    University FAST;

    Professor p1("Ali", "ComputerScience");
    Professor p2("Ayesha", "DS");
    Professor p3("Aliya", "AI");
    Professor p4("Ahmed", "SE");

    FAST.addProfessor(p1);
    FAST.addProfessor(p2);
    FAST.addProfessor(p3);
    FAST.addProfessor(p4);

    FAST.viewDetails();

}
