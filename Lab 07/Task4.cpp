# include <iostream>
#include <string>
using namespace std;

class Person 
{
    protected:
        string name, id, address, phoneNumber, email;
    public:
        Person(string n, string i, string a, string p, string e)
            : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    
        virtual void displayInfo() = 0;
    
        virtual void updateInfo(string newAddress, string newPhone, string newEmail) 
        {
            address = newAddress;
            phoneNumber = newPhone;
            email = newEmail;
        }
    
        string getName() 
        {
            return name;
        }
    
        virtual ~Person() {}
};

class Student : public Person 
{
private:
    string coursesEnrolled[5];
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, string courses[], double g, int year)
        : Person(n, i, a, p, e), GPA(g), enrollmentYear(year) 
    {
        for (int j = 0; j < 5; j++)
        {
            coursesEnrolled[j] = courses[j];
        }
    }

    void displayInfo() override 
    {
        cout << "Student: " << name << " | ID: " << id << " | GPA: " << GPA << " | Year: " << enrollmentYear << endl;
    }

    void updateInfo(string newAddress, string newPhone, string newEmail) override
    {
        Person::updateInfo(newAddress, newPhone, newEmail); 
        cout << "Student info updated!" << endl;
    }
};

class Professor : public Person
{
    private:
        string department;
        string coursesTaught[3];
        double salary;
    public:
        Professor(string n, string i, string a, string p, string e, string dept, string courses[], double s)
            : Person(n, i, a, p, e), department(dept), salary(s) 
        {
            for (int j = 0; j < 3; j++)
            {
                coursesTaught[j] = courses[j];
            }
        }
    
        void displayInfo() override 
        {
            cout << "Professor: " << name << " | Department: " << department << " | Salary: $" << salary << endl;
        }
    
        void updateInfo(string newAddress, string newPhone, string newEmail) override
        {
            Person::updateInfo(newAddress, newPhone, newEmail); 
            cout << "Professor info updated!" << endl;
        }
};

class Staff : public Person 
{
    private:
        string department, position;
        double salary;
    public:
        Staff(string n, string i, string a, string p, string e, string dept, string pos, double s)
            : Person(n, i, a, p, e), department(dept), position(pos), salary(s) {}
    
        void displayInfo() override 
        {
            cout << "Staff: " << name << " | Position: " << position << " | Salary: $" << salary << endl;
        }
    
        void updateInfo(string newAddress, string newPhone, string newEmail) override
        {
            Person::updateInfo(newAddress, newPhone, newEmail); 
            cout << "Staff info updated!" << endl;
        }
};



class Course
{
    private:
        string courseId, courseName, instructor, schedule;
        int credits;
    public:
        Course(string id, string name, string instr, string sched, int c)
            : courseId(id), courseName(name), instructor(instr), schedule(sched), credits(c) {}
    
        void registerStudent(Student& student) 
        {
            cout << "Student " << student.getName() << " registered in " << courseName << endl;
        }
    
        void calculateGrades() 
        {
            cout << "Calculating grades for " << courseName << endl;
        }
    
        void displayCourse() 
        {
            cout << "Course: " << courseName << " | Instructor: " << instructor << " | Credits: " << credits << endl;
        }
};

int main() 
{
    string studentCourses[5] = {"Math", "Physics", "Chemistry", "English", "History"};
    Student student1("Alice", "S123", "123 St", "555-1234", "alice@mail.com", studentCourses, 3.8, 2022);

    string profCourses[3] = {"Algebra", "Calculus", "Statistics"};
    Professor professor1("Dr. Bob", "P456", "456 Ave", "555-5678", "bob@mail.com", "Mathematics", profCourses, 80000);

    Staff staff1("Charlie", "ST789", "789 Blvd", "555-9012", "charlie@mail.com", "Admin", "Manager", 50000);

    Course course1("C101", "Computer Science", "Dr. Smith", "MWF 10:00 AM", 4);

    student1.displayInfo();
    professor1.displayInfo();
    staff1.displayInfo();
    course1.displayCourse();

    student1.updateInfo("456 St", "555-9999", "alice_new@mail.com");
    professor1.updateInfo("789 Ave", "555-8888", "bob_new@mail.com");
    staff1.updateInfo("321 Blvd", "555-7777", "charlie_new@mail.com");

    cout << "\nAfter updating info:\n";
    student1.displayInfo();
    professor1.displayInfo();
    staff1.displayInfo();

    return 0;
}
