# include <iostream>
using namespace std;

class User;

const int hashValue = 5381;

int generateHash(string password)
{
    int hash = hashValue;
    for (char c : password)
    {
        hash = (hash * 33) + c;
    }
    return hash;
}

class User
{
    protected:
        string name, id, email;
        int hashedPassword;
        string listOfPermissions[2];

    public:
        User(string n, string ID, string e, int h): name(n), id(ID), email(e), hashedPassword(h)
        {
            for (int i = 0; i < 2; i++)
            {
                listOfPermissions[i] = "";
            }
        }

        User(){}

        bool AuthenticateUser(string password)
        {
            return (hashedPassword == generateHash(password));
        }

        virtual void display()
        {
            cout << "\nUser Name: " << name << endl;
            cout << "User ID: " << id << endl;
            cout << "User Email: " << email << endl;
            cout << "List of Permissions: " << endl;
            if (listOfPermissions[0] == " ")
            {
                cout << "No Permissions Granted..." << endl;
            }
            else
            {
                int i = 0;
                while (listOfPermissions[i] != " " && i < 2)
                {
                    cout << i+1 << ": " << listOfPermissions[i] << endl;
                    i++;
                }
            }
        }

        bool AccessLab()
        {
            int i = 0;
            while (listOfPermissions[i] != " " && i < 2)
            {
                if (listOfPermissions[i] == "Lab is Accessible!")
                {
                    cout << "User " << id << " has access to the Lab!" << endl;
                    return true;
                }
                i++;
            }
            cout << "User " << id << " does not has access to the Lab!" << endl;
            return false;
        }

        string* getList()
        {
            return listOfPermissions;
        }

        string getID()
        {
            return id;
        }
};

bool authenticateAndPerformAction(User* user, string action)
{
    string *listOfPermissions = user->getList();
    int i = 0;
    while ((listOfPermissions[i]) != "" && i < 2)
    {
        if (listOfPermissions[i] == action)
        {
            cout << "User " << user->getID() << " has access to perform this Task!" << endl;
            return true;
        }
        i++;
    }
    cout << "User " << user->getID() << " does not has access to perform this Task!" << endl;
    return false;
}

class Student: public User
{
    protected:
        int listOfAssignment[10]; // Assuming max 10 assignments  

    public:
        Student(string n, string id, string e, int h): User(n, id, e, h)
        {
            listOfPermissions[0] = " Submit Assignment";

        }

        Student(){}

        void display() override
        {
            cout << "The User is a Student!" << endl;
            User :: display();
        }

        void assignAssignment(int index)
        {
            if (index >= 0 && index < 10) 
            {
                listOfAssignment[index] = 0;
                cout << "Assignment " << index << " assigned successfully." << endl;
            } 
            else 
            {
                cout << "Invalid assignment index." << endl;
            }
        }

        void submitAssignment(int index)
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
            {
                if (index >= 0 && index < 10) 
                {
                    if (listOfAssignment[index] == 0)
                    {
                        listOfAssignment[index] = 0;
                        cout << "Assignment " << index << " assigned successfully." << endl;
                    }
                    else if (listOfAssignment[index] == 1)
                    {
                        cout << "The Assignment has already been submitted." << endl;
                    }
                    else
                    {
                        cout << "No Assigned Work." << endl;
                    }
                } 
                else 
                {
                    cout << "Invalid assignment index." << endl;
                }
            }
            else
            {
                cout << "Incorrect Password." << endl;
            }
            
        }
};

class TA: public Student
{
    private:
        Student ListOfStudents[10]; // max 10 student can be assigned
        string ListOfProjects[2]; // can work on max 2 projects 
        int currentProjects;
        int currentStudents;

    public:
        TA(string n, string id, string e, int h): Student(n, id, e, h), currentProjects(0), currentStudents(0){}

        void display() override
        {
            cout << "The User is a TA!" << endl;
            User :: display();
            if (currentProjects == 0)
            {
                cout << "Currently not working on any Project." << endl;
            }
            else
            {
                cout << "List Of Projects: " << endl;
                for (int i = 0; i < currentProjects; i++)
                {
                    cout << i+1 << ": " << ListOfProjects[i] << endl;
                }
            }

            if (currentStudents == 0)
            {
                cout << "Currently No Student Assigned." << endl;
            }
            else
            {
                cout << "List of Assigned Students: " << endl;
                for (int i = 0; i < currentProjects; i++)
                {
                    cout << i+1 << ": " << ListOfProjects[i] << endl;
                }
            }
            
        }

        void newProject()
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
            {
                if (currentProjects < 2)
                {
                    cout << "TA: " << name << " can start working on a new Project!" << endl;
                    cout << "Enter the name of the Project: " << endl;
                    getline(cin, ListOfProjects[currentProjects]);
                    currentProjects++;
                }
                else
                {
                    cout << "TA: " << name << " is already working on two Projects" << endl;
                    cout << "Cannot work on a new Project!" << endl;
                }
            }
            else
            {
                cout << "Incorrect Password." << endl;
            }
        }

        void assignStudent(Student &s)
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
            {
                if (currentStudents < 10)
                {
                    ListOfStudents[currentStudents] = s;
                    currentStudents++;
                    cout << "Student has been assigned to TA " << name << endl; 
                }
                else
                {
                    cout << "TA has already been assigned 10 Students." << endl;
                    cout << "Cannot assign more Students." << endl;
                }
            }
            else
            {
                cout << "Incorrect Password" << endl;
            }
        }
};

class Professor: public User
{
    public:
        Professor(string n, string id, string e, int h): User(n, id, e, h){}

        void display() override
        {
            cout << "The User is a Professor!" << endl;
            User :: display();
        }


};
