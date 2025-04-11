# include <iostream>
using namespace std;

class Student
{
    string name;
    float grades[3] = {0.0}; // 1: Calculus, 2: OOP, 3: DLD

    public:
        Student(){}

        Student(string n): name(n)
        {
            cout << name << " Grade Details: " << endl;
            cout << "\nEnter marks for Calculus: ";
            cin >> grades[0];
            cout << "\nEnter marks for OOP: ";
            cin >> grades[1];
            cout << "\nEnter marks for DLD: ";
            cin >> grades[2];
            cout << "\n";
        };

        friend class Teacher;

        friend float calculateAverageGrade(Student const &s);

};

class Teacher
{
    string name;

    public:
        Teacher(){}

        Teacher(string n): name(n){}
        
        void displayGrades(Student const &s)
        {
            cout << "\nCalculus: " << s.grades[0] << endl;
            cout << "OOP: " << s.grades[1] << endl;
            cout << "DLD: " << s.grades[2] << endl; 
        }

        void updateGrade(Student &s)
        {
            int choice;
            cout << "\nWhich subject's grades do you want to change?" << endl;
            cout << "1: Calculus" << endl;
            cout << "2: OOP" << endl;
            cout << "3: DLD" << endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    cout << "Enter the updated marks of calculus: " << endl;
                    cin >> s.grades[0];
                    cout << "Marks Updated!" << endl;
                    break;
                
                case 2:
                    cout << "Enter the updated marks of OOP: " << endl;
                    cin >> s.grades[1];
                    cout << "Marks Updated!" << endl;
                    break;

                case 3:
                    cout << "Enter the updated marks of DLD: " << endl;
                    cin >> s.grades[2];
                    cout << "Marks Updated!" << endl;
                    break;

                default:
                    cout << "Invalid Option!" << endl;
            }
        }
};

float calculateAverageGrade(Student const &s)
{
    float average = 0.0;
    for (int i = 0; i < 3; i++)
    {
        average += s.grades[i];
    }

    return average/3;
}

int main()
{
    Student s1("Ahmed Ali");
    Teacher t1("Aliya Mahmood");

    t1.displayGrades(s1);
    t1.updateGrade(s1);

    cout << "\nUpdated average grade is: " << calculateAverageGrade(s1) << endl;


}
