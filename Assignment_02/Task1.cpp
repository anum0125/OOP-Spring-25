#include <iostream>
#include <string>
using namespace std;

class TransportUser 
{
    protected:
        string name;
        string ID;
        int fees_paid; 
        string stop;
        int point;
        int* Attendance;
        int attendance_days;

    public:
        TransportUser(string name, string ID, string stop) 
            : name(name), ID(ID), stop(stop), fees_paid(0), point(-1), Attendance(nullptr), attendance_days(0) {}

        virtual ~TransportUser()
        {
            delete[] Attendance;
        }

        void markAttendance(int day) 
        {
            if (day > 0 && day <= attendance_days) 
            {
                Attendance[day-1] = 1;
                cout << "Attendance marked for day " << day << endl;
            } 
            else 
            {
                cout << "Invalid day for attendance marking" << endl;
            }
        }

        int getFeesPaid() const { return fees_paid; }
        void setFeesPaid(int f) { fees_paid = f; }
        void setPoint(int p) { point = p; }
        int getPoint() const { return point; }
        string getID() const { return ID; }
        string getStop() const { return stop; }
        string getName() const { return name; }

        virtual void viewDetails() const = 0; 
        virtual void calculateFees() = 0;     

        void initializeAttendance(int days) 
        {
            delete[] Attendance;
            attendance_days = days;
            Attendance = new int[days];
            for (int i = 0; i < days; i++) 
            {
                Attendance[i] = 0;
            }
        }

    
        bool operator==(const TransportUser& other) const 
        {
            return this->ID == other.ID;
        }
};

class Student : public TransportUser 
{
    private:
        string semester;

    public:
        Student(string name, string ID, string stop, string semester) 
            : TransportUser(name, ID, stop), semester(semester) 
            {
                cout << "Enter the days of semester: ";
                int days;
                cin >> days;
                initializeAttendance(days);
            }

        void viewDetails() const override 
        {
            cout << "----- Student Details -----" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << ID << endl;
            cout << "Semester: " << semester << endl;
            cout << "Stop: " << stop << endl;
            cout << "Fees Status: " << (fees_paid ? "Paid" : "Not Paid") << endl;
            if (point != -1) 
            {
                cout << "Assigned to Bus Route: " << point << endl;
            }
        }

        void calculateFees() override 
        {
            cout << "Calculating semester fees for student " << name << endl;
            fees_paid = 1; 
        }
};

class Teacher : public TransportUser 
{
    private:
        int months;

    public:
        Teacher(string name, string ID, string stop) 
            : TransportUser(name, ID, stop), months(0) 
            {
                cout << "Enter the days in current month: ";
                int days;
                cin >> days;
                initializeAttendance(days);
            }

        void viewDetails() const override 
        {
            cout << "----- Teacher Details -----" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << ID << endl;
            cout << "Months of service: " << months << endl;
            cout << "Stop: " << stop << endl;
            cout << "Fees Status: " << (fees_paid ? "Paid" : "Not Paid") << endl;
            if (point != -1) 
            {
                cout << "Assigned to Bus Route: " << point << endl;
            }
        }

        void calculateFees() override 
        {
            // Teachers pay monthly
            cout << "Calculating monthly fees for teacher " << name << endl;
            months++;
            fees_paid = 1;
        }
};

class Staff : public TransportUser 
{
    private:
        int months;

    public:
        Staff(string name, string ID, string stop) 
            : TransportUser(name, ID, stop), months(0) 
            {
                cout << "Enter the days in current month: " << endl;
                int days;
                cin >> days;
                initializeAttendance(days);
            }

        void viewDetails() const override 
        {
            cout << "----- Staff Details -----" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << ID << endl;
            cout << "Months of service: " << months << endl;
            cout << "Stop: " << stop << endl;
            cout << "Fees Status: " << (fees_paid ? "Paid" : "Not Paid") << endl;
            if (point != -1) 
            {
                cout << "Assigned to Bus Route: " << point << endl;
            }
        }

        void calculateFees() override 
        {
            // Staff pay monthly
            cout << "Calculating monthly fees for staff " << name << endl;
            months++;
            fees_paid = 1; 
        }
};

class Bus 
{
    private:
        string name;
        static int counter;
        int id;
        int max_stops;
        int current_stops;
        int max_users;
        int current_users;
        string* stops;
        TransportUser** users;

    public:
        Bus(string name, int max_stops, int max_users) 
            : name(name), max_stops(max_stops), current_stops(0), 
            max_users(max_users), current_users(0) 
            {
                id = counter++;
                stops = new string[max_stops];
                users = new TransportUser*[max_users];
            }

        ~Bus() 
        {
            delete[] stops;
            delete[] users;
        }

        void AddStop(string stop) 
        {
            if (current_stops < max_stops) 
            {
                stops[current_stops++] = stop;
                cout << "Stop '" << stop << "' added to bus " << id << endl;
            } 
            else 
            {
                cout << "Cannot add more stops. Maximum limit reached." << endl;
            }
        }

        bool hasStop(const string& stop) const 
        {
            for (int i = 0; i < current_stops; i++) 
            {
                if (stops[i] == stop) return true;
            }
            return false;
        }

        void AddUser(TransportUser& user) 
        {
            if (current_users >= max_users) 
            {
                cout << "Bus is full. Cannot add more users." << endl;
                return;
            }

            if (!user.getFeesPaid()) 
            {
                cout << "User " << user.getName() << " hasn't paid fees." << endl;
                return;
            }

            if (!hasStop(user.getStop())) 
            {
                cout << "Bus doesn't serve stop " << user.getStop() << endl;
                return;
            }

            for (int i = 0; i < current_users; i++) 
            {
                if (*users[i] == user) 
                {
                    cout << "User already registered on this bus." << endl;
                    return;
                }
            }

            users[current_users++] = &user;
            user.setPoint(id);
            cout << "User " << user.getName() << " added to bus " << id << endl;
        }

        void removeUser(string ID) 
        {
            for (int i = 0; i < current_users; i++) 
            {
                if (users[i]->getID() == ID) 
                {
                    users[i]->setPoint(-1);
                    for (int j = i; j < current_users - 1; j++) 
                    {
                        users[j] = users[j+1];
                    }
                    current_users--;
                    cout << "User with ID " << ID << " removed from bus " << id << endl;
                    return;
                }
            }
            cout << "User with ID " << ID << " not found on this bus." << endl;
        }

        void viewDetails() const 
        {
            cout << "\n----- Bus " << id << " Details -----" << endl;
            cout << "Driver: " << name << endl;
            cout << "Stops (" << current_stops << "/" << max_stops << "):" << endl;
            for (int i = 0; i < current_stops; i++) 
            {
                cout << "  " << i+1 << ". " << stops[i] << endl;
            }
            
            cout << "\nRegistered Users (" << current_users << "/" << max_users << "):" << endl;
            for (int i = 0; i < current_users; i++) 
            {
                users[i]->viewDetails();
                cout << endl;
            }
        }

        bool operator==(const Bus& other) const 
        {
            if (this->current_stops != other.current_stops)
            {
                return false;
            }
            for (int i = 0; i < current_stops; i++) 
            {
                if (this->stops[i] != other.stops[i]) return false;
            }
            
            return true;
        }
};

int Bus::counter = 0;

class PointSystem 
{
    private:
        string name;
        Bus** buses;
        int max_buses;
        int current_buses;

    public:
        PointSystem(string name, int max_buses) 
            : name(name), max_buses(max_buses), current_buses(0) 
            {
                buses = new Bus*[max_buses];
            }

        ~PointSystem() 
        {
            delete[] buses;
        }

        void registerBus(Bus* bus) 
        {
            if (current_buses >= max_buses) 
            {
                cout << "Cannot register more buses. Maximum limit reached." << endl;
                return;
            }

            for (int i = 0; i < current_buses; i++) 
            {
                if (*buses[i] == *bus) 
                {
                    cout << "Bus with same route already exists in the system." << endl;
                    return;
                }
            }
            
            buses[current_buses++] = bus;
            cout << "Bus registered in point system." << endl;
        }

        void initializeFees() 
        {
            cout << "Initializing fees for all users..." << endl;
            // In a real system, we would iterate through all users on all buses
            // and reset their fees status
        }

        void viewDetails() const 
        {
            cout << "\n===== " << name << " Point System =====" << endl;
            cout << "Registered Buses: " << current_buses << "/" << max_buses << endl;
            
            for (int i = 0; i < current_buses; i++) 
            {
                buses[i]->viewDetails();
            }
        }
};

int main() 
{
    cout << "Name: Anum Baig" << endl;
    cout << "24K-0843\n" << endl;
    
    PointSystem ps("FAST Transportation", 5);
    
    Bus bus1("Jadoon", 5, 10);
    bus1.AddStop("A");
    bus1.AddStop("B");
    bus1.AddStop("C");
    
    Bus bus2("Nadeem", 5, 10);
    bus2.AddStop("D");
    bus2.AddStop("E");
    bus2.AddStop("F");
    
    ps.registerBus(&bus1);
    ps.registerBus(&bus2);
    
    Student student1("Anum", "k240843", "A", "Fall 2023");
    student1.calculateFees();
    
    Student student2("Esha", "k240909", "B", "Fall 2023");
    student2.calculateFees();
    
    Teacher teacher1("Dr. Smith", "t1001", "C");
    teacher1.calculateFees();
    
    Staff staff1("Mr. Johnson", "s2001", "D");
    staff1.calculateFees();

    bus1.AddUser(student1);
    bus1.AddUser(student2);
    bus1.AddUser(teacher1);
    bus2.AddUser(staff1);
    
    Student student3("Talaal", "k219878", "C", "Fall 2023");
    bus1.AddUser(student3);

    student1.markAttendance(1);
    teacher1.markAttendance(1);
    staff1.markAttendance(1);

    bus1.removeUser("k240843");

    ps.viewDetails();

    Bus bus3("Ali", 5, 10);
    bus3.AddStop("A");
    bus3.AddStop("B");
    bus3.AddStop("C");
    
    if (bus1 == bus3) 
    {
        cout << "\nBus1 and Bus3 have the same route!" << endl;
    } 
    else 
    {
        cout << "\nBus1 and Bus3 have different routes." << endl;
    }
    
    if (student1 == student2) 
    {
        cout << "Student1 and Student2 are the same!" << endl;
    } 
    else 
    {
        cout << "Student1 and Student2 are different." << endl;
    }
    
    return 0;
}
