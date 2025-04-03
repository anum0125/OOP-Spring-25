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
        string listOfPermissions[3];

    public:
        User(string n, string ID, string e, int h): name(n), id(ID), email(e), hashedPassword(h)
        {
            for (int i = 0; i < 3; i++)
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
                while (listOfPermissions[i] != "" && i < 2)
                {
                    cout << i+1 << ": " << listOfPermissions[i] << endl;
                    i++;
                }
            }
        }

        bool AccessLab()
        {
            int i = 0;
            while (listOfPermissions[i] != "" && i < 3)
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
            listOfPermissions[1] = "Display Information";
            
        }

        Student(){}

        string getName()
        {
            return name;
        }

        string getID()
        {
            return id;
        }

        void display() override
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
            {
                cout << "The User is a Student!" << endl;
                User :: display();
            }
            else
            {
                cout << "Incorrect Password!" << endl;
            }
           
        }

        void assignAssignment(int index)
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
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
            else
            {
                cout << "Incorrect Password!" << endl;
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
                        listOfAssignment[index] = 1;
                        cout << "Assignment " << index << " submitted successfully." << endl;
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
        TA(string n, string id, string e, int h): Student(n, id, e, h), currentProjects(0), currentStudents(0)
        {
            listOfPermissions[0] = "Work on a new Project";
            listOfPermissions[1] = "Display Projects";
            listOfPermissions[2] = "Have a new Student Assigned";
        }

        void display() override
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
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
                    for (int i = 0; i < currentStudents; i++)
                    {
                        cout << i+1 << ": "<< endl;
                        cout << "Name: " << ListOfStudents[i].getName() << endl;
                        cout << "ID: " << ListOfStudents[i].getID() << endl;
                    }
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
        Professor(string n, string id, string e, int h): User(n, id, e, h)
        {
            listOfPermissions[0] = "Access the lab";
            listOfPermissions[1] = "Display Information";
        }

        void display() override
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
            {
                cout << "The User is a Professor!" << endl;
                User :: display();
            }
        }
            

        void NewProject()
        {
            cin.ignore();
            string password;
            cout << "Enter  your password: " << endl;
            getline(cin, password);
            if (AuthenticateUser(password) == 1)
            {
                cout << "You can work with a TA on a Project!" << endl;
            }
        }


};

int main() {
    // Create sample users
    Student student("Alice", "S001", "alice@uni.edu", generateHash("alice123"));
    TA ta("Bob", "T001", "bob@uni.edu", generateHash("bob123"));
    Professor professor("Dr. Smith", "P001", "smith@uni.edu", generateHash("smith123"));
    
    User* currentUser = nullptr;
    int choice;
    string inputId, inputPassword;

    while (true) {
        if (currentUser == nullptr) {
            // Login system
            cout << "\n===== University System Login =====" << endl;
            cout << "1. Login" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter ID: ";
                cin >> inputId;
                cout << "Enter password: ";
                cin.ignore();
                getline(cin, inputPassword);

                // Check against all user types
                if (student.getID() == inputId && student.AuthenticateUser(inputPassword)) {
                    currentUser = &student;
                } 
                else if (ta.getID() == inputId && ta.AuthenticateUser(inputPassword)) {
                    currentUser = &ta;
                } 
                else if (professor.getID() == inputId && professor.AuthenticateUser(inputPassword)) {
                    currentUser = &professor;
                } 
                else {
                    cout << "Invalid credentials!" << endl;
                }
            } 
            else if (choice == 2) {
                break;
            }
        } 
        else {
            // Main menu for logged in users
            cout << "\n===== Main Menu =====" << endl;
            cout << "Logged in as: " << currentUser->getID() << endl;
            cout << "1. View Profile" << endl;
            cout << "2. Check Lab Access" << endl;
            cout << "3. Perform Action" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    currentUser->display();
                    break;
                case 2:
                    currentUser->AccessLab();
                    break;
                case 3: {
                    // Display all possible actions
                    cout << "\nAvailable Actions:" << endl;
                    cout << "1. Submit Assignment" << endl;
                    cout << "2. Display Information" << endl;
                    cout << "3. Work on a new Project" << endl;
                    cout << "4. Display Projects" << endl;
                    cout << "5. Have a new Student Assigned" << endl;
                    cout << "6. Access the lab" << endl;
                    
                    int actionChoice;
                    cout << "Select action: ";
                    cin >> actionChoice;
                    
                    // Map action numbers to permission strings
                    string actionMap[] = {
                        "Submit Assignment",
                        "Display Information",
                        "Work on a new Project",
                        "Display Projects",
                        "Have a new Student Assigned",
                        "Access the lab"
                    };
                    
                    if (actionChoice >= 1 && actionChoice <= 6) {
                        string selectedAction = actionMap[actionChoice-1];
                        
                        // Check if user has permission for this action
                        bool hasPermission = false;
                        string* permissions = currentUser->getList();
                        for (int i = 0; i < 3 && permissions[i] != ""; i++) {
                            if (permissions[i] == selectedAction) {
                                hasPermission = true;
                                break;
                            }
                        }
                        
                        if (hasPermission) {
                            cout << "Performing action: " << selectedAction << endl;
                            
                            // Execute the action
                            if (selectedAction == "Submit Assignment") {
                                int assignmentNum;
                                cout << "Enter assignment number (0-9): ";
                                cin >> assignmentNum;
                                ((Student*)currentUser)->submitAssignment(assignmentNum);
                            }
                            else if (selectedAction == "Work on a new Project") {
                                ((TA*)currentUser)->newProject();
                            }
                            else if (selectedAction == "Have a new Student Assigned") {
                                string studentId;
                                cout << "Enter student ID to assign: ";
                                cin >> studentId;
                                if (studentId == student.getID()) {
                                    ((TA*)currentUser)->assignStudent(student);
                                } else {
                                    cout << "Student not found!" << endl;
                                }
                            }
                            else if (selectedAction == "Access the lab") {
                                currentUser->AccessLab();
                            }
                            else {
                                currentUser->display();
                            }
                        } else {
                            cout << "You don't have permission for this action!" << endl;
                        }
                    } else {
                        cout << "Invalid action choice!" << endl;
                    }
                    break;
                }
                case 0:
                    currentUser = nullptr;
                    cout << "Logged out successfully." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
    }

    return 0;
}
