# include <iostream>
# include <string>
# include <cstring>

using namespace std;

class Planner
{
    string january[31];
    string february[29];
    string march[31];
    string april[30];
    string may[31];
    string june[30];
    string july[31];
    string august[31];
    string september[30];
    string october[31];
    string november[30];
    string december[31];

    public:

        Planner()
        {
            for (int i = 0; i < 31; i++)
            {
                january[i] = march[i] = may[i] = july[i] = august[i] = october[i] = november[i] = " ";

                if (i < 30)
                {
                    april[i] = june[i] = september[i] = december[i] = " ";
                }
                if (i < 29)
                {
                    february[i] = " ";
                }
            }
        }

        string* monthArray(int month_num, int *max)
        {
            switch(month_num)
            {
                case 1:
                    *max = 31;
                    return january;
                    break;
                
                case 2:
                    *max = 29;
                    return february;
                    break;

                case 3:
                    *max = 31;
                    return march;
                    break;

                case 4:
                    *max = 30;
                    return april;
                    break;

                case 5:
                    *max = 31;
                    return may;
                    break;

                case 6:
                    *max = 30;
                    return june;
                    break;

                case 7:
                    *max = 31;
                    return july;
                    break;

                case 8:
                    *max = 31;
                    return august;
                    break;

                case 9:
                    *max = 30;
                    return september;
                    break;

                case 10:
                    *max = 31;
                    return october;
                    break;

                case 11:
                    *max = 30;
                    return november;
                    break;

                case 12:
                    *max = 31;
                    return december;
                    break;

                default:
                    cout << "Invalid Input." << endl;

            }
        }

        void add()
        {
            int choice;
            cout << "Choose the month in which you want to add a booking: " << endl;
            cout << "1: January" << endl;
            cout << "2: February" << endl;
            cout << "3: March" << endl;
            cout << "4: April" << endl;
            cout << "5: May" << endl;
            cout << "6: June" << endl;
            cout << "7: July" << endl;
            cout << "8: August" << endl;
            cout << "9: September" << endl;
            cout << "10: October" << endl;
            cout << "11: November" << endl;
            cout << "12: December" << endl;
            
            cin >> choice;

            while (choice > 12 || choice < 1)
            {
                cout << "Choose a number between 1-12 (included)" << endl;
            }
            int *max;
            string *month = monthArray(choice, max);

            int date;
            cout << "Enter the date when you want to add a booking: " << endl;
            cin >> date;

            while (date < 1 || date > *max)
            {
                cout << "Invalid date. Enter a date between 1 and " << max << " (included)" << endl;
                cin >> date;
            }

            cin.ignore();

            if (month[date-1] == " ")
            {
                cout << "Enter the booking: " << endl;
                getline(cin, month[date-1]);
                cout << "\nBooking Added." << endl;
            }
            else
            {
                cout << "The day is already reserved." << endl;
            }
        }

        void remove()
        {
            int choice;
            cout << "Choose the month in which you want to remove a booking: " << endl;
            cout << "1: January" << endl;
            cout << "2: February" << endl;
            cout << "3: March" << endl;
            cout << "4: April" << endl;
            cout << "5: May" << endl;
            cout << "6: June" << endl;
            cout << "7: July" << endl;
            cout << "8: August" << endl;
            cout << "9: September" << endl;
            cout << "10: October" << endl;
            cout << "11: November" << endl;
            cout << "12: December" << endl;
            
            cin >> choice;

            while (choice > 12 || choice < 1)
            {
                cout << "Choose a number between 1-12 (included)" << endl;
            }
            int *max;
            string *month = monthArray(choice, max);

            int date;
            cout << "Enter the date when you want to remove a booking: " << endl;
            cin >> date;

            while (date < 1 || date > *max)
            {
                cout << "Invalid date. Enter a date between 1 and " << max << " (included)" << endl;
                cin >> date;
            }

            if (month[date-1] == " ")
            {
                cout << "The day is already free." << endl;
            }
            else
            {
                month[date-1] = " ";
                cout << "The reservation has been removed." << endl;
            }
        }

        void update()
        {
            int choice;
            cout << "Choose the month in which you want to update a booking: " << endl;
            cout << "1: January" << endl;
            cout << "2: February" << endl;
            cout << "3: March" << endl;
            cout << "4: April" << endl;
            cout << "5: May" << endl;
            cout << "6: June" << endl;
            cout << "7: July" << endl;
            cout << "8: August" << endl;
            cout << "9: September" << endl;
            cout << "10: October" << endl;
            cout << "11: November" << endl;
            cout << "12: December" << endl;
            
            cin >> choice;

            while (choice > 12 || choice < 1)
            {
                cout << "Choose a number between 1-12 (included)" << endl;
            }
            int *max;
            string *month = monthArray(choice, max);

            int date;
            cout << "Enter the date when you want to update a booking: " << endl;
            cin >> date;

            while (date < 1 || date > *max)
            {
                cout << "Invalid date. Enter a date between 1 and " << max << " (included)" << endl;
                cin >> date;
            }

            cin.ignore();

            if (month[date-1] != " ")
            {
                cout << "Enter the updated booking: " << endl;
                getline(cin, month[date-1]);
                cout << "\nBooking Added." << endl;
            }
            else
            {
                cout << "The day is not reserved." << endl;
            }
        }

        void display()
        {
            string array[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

            for (int j = 0; j < 12; j++)
            {
                cout << "\n" << array[j] << endl;

                int max;
                string *month = monthArray(j+1, &max);
                {
                    for (int i = 0; i < max; i++)
                    {
                        if (month[i] != " " )
                        {
                            cout << array[j] << " " << i+1 << " is reserved." << endl;
                            cout << "Booking: " << month[i] << endl;
                        }
                        else
                        {
                            cout << array[j] << " " <<  i+1 << " is not reserved." << endl;
                        }
                    }
                }
            }
        }
};

int main()
{
    Planner planning;
    
    int end = 0;
    while (end == 0)
    {
        cout << "\nMenu" << endl;
        cout << "1: Add a Booking" << endl;
        cout << "2: Remove a Booking" << endl;
        cout << "3: Update a Booking" << endl;
        cout << "4: Display your schedule" << endl;
        cout << "5: Exit" << endl;

        int option;
        cout << "Enter your choice: " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            planning.add();
            break;

        case 2:
            planning.remove();
            break;

        case 3: 
            planning.update();
            break;

        case 4:
            planning.display();
            break;

        case 5:
            cout << "Program Exited." << endl;
            end = 1;
            break;
        
        default:
            cout << "Invalid Input.";
            break;
        }
    }
}
