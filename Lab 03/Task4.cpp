# include <iostream>
# include <string>

using namespace std;

class Laptop
{
    string brand;
    string model;
    string processor;
    int RAM;
    int storage;
    int on_off;

    public:

        Laptop()
        {
            cout << "Enter the brand of the laptop: " << endl;
            getline(cin, brand);
            cout << "Enter the model of the laptop: " << endl;
            getline(cin, model);
            cout << "Enter the processor of the laptop: " << endl;
            getline(cin, processor);
            cout << "Enter the RAM of the laptop: " << endl;
            cin >> RAM;
            cout << "Enter the storage capacity of the laptop: " << endl;
            cin >> storage;

            cin.ignore();
        }

        void setOn_Off(int n)
        {
            if (n == 0 || n == 1)
            {
                on_off = n;
                if (n == 0)
                {
                    cout << "Laptop turned off." << endl;
                }
                else
                {
                    cout << "Laptop turned on." << endl;
                }
            }
            else
            {
                cout << "Invalid Input." << endl;
            }
        }

        int getOn_Off()
        {
            return on_off;
        }

        void display()
        {
            cout << "--------------------------------------------------" << endl;
            cout << "The brand of the laptop: " << brand << endl;
            cout << "The model of the laptop: " << model << endl;
            cout << "The processor of the laptop: " << processor << endl;
            cout << "The RAM of the laptop: "<< RAM << endl;
            cout << "The storage capacity of the laptop: " << storage << endl;
            cout << "--------------------------------------------------" << endl;
        }

        void runProgram()
        {
            string programs[5][2] = 
            {
                {"Calculator", "0"},
                {"Calender", "0"},
                {"Clash of Clans", "0"},
                {"Fitness App", "0"},
                {"Whatsapp", "0"}
            };
        
            cout << "Menu: " << endl;
            for (int i = 0; i < 5; i++) 
            {
                cout << i + 1 << ": " << programs[i][0] << endl;
            }

            int choice;
            cout << "Enter the application you want to run. (1-5)" << endl;
            cin >> choice;
            while (choice > 5 || choice < 1)
            {
                cout << "Invalid Input." << endl;
                cout << "You can only enter a number between 1-5 (included). Try Again." << endl;
                cin >> choice;
            }
            int found = 0;

            programs[choice-1][1] = '0';

            cout << "\nCurrently running programs: " << endl;
            cout << "\n" << programs[choice-1][0] << "is actively running." << endl;
            for(int i = 0; i < 5; i++)
            {
                if (programs[i][1] == "1" && i != choice-1)
                {
                    cout << programs[i][0] << "is running in background." << endl;
                }
            }



        }


        
};

int main()
{
    Laptop Bilal;
    Laptop Ayesha;
    
    int end = 0;
    while (end == 0)
    {
        int person;
        cout <<  "Whose Laptop is being operated? 1 or 2 " << endl;
        cout << "1: Ayesha" << endl;
        cout << "Bilal" << endl;
        cin >> person;

        switch (person)
        {
            case 1:
                cout << "\nMenu" << endl;
                cout << "1: Turn on or Turn Off the Laptop." << endl;
                cout << "2: Display the Specification of the Laptop" << endl;
                cout << "3: Run a Program" << endl;
                cout << "4: Compare the specifications" << endl;
                cout << "5: Exit" << endl;
    
                int option;
                cout << "Enter your choice: " << endl;
                cin >> option;
        
                switch (option)
                {
                case 1:
                    Ayesha.getOn_Off();
                    break;
        
                case 2:
                    Ayesha.display();
                    break;
        
                case 3: 
                    Ayesha.runProgram();
                    break;
        
                case 4:
                    Ayesha.display();
                    Bilal.display();
                    break;
        
                case 5:
                    cout << "Program Exited." << endl;
                    end = 1;
                    break;
                
                default:
                    cout << "Invalid Input.";
                    break;
                }
                break;

            case 2:
                cout << "\nMenu" << endl;
                cout << "1: Turn on or Turn Off the Laptop." << endl;
                cout << "2: Display the Specification of the Laptop" << endl;
                cout << "3: Run a Program" << endl;
                cout << "4: Compare the specifications" << endl;
                cout << "5: Exit" << endl;
        
                int option;
                cout << "Enter your choice: " << endl;
                cin >> option;
        
                switch (option)
                {
                case 1:
                    Bilal.getOn_Off();
                    break;
        
                case 2:
                    Bilal.display();
                    break;
        
                case 3: 
                    Bilal.runProgram();
                    break;
        
                case 4:
                    Bilal.display();
                    Ayesha.display();
                    break;
        
                case 5:
                    cout << "Program Exited." << endl;
                    end = 1;
                    break;
                
                default:
                    cout << "Invalid Input.";
                    break;
                }
                break;

            default:
                cout << "Invalid Input. You can only enter 1 or 1" << endl;

        

        }
    }
}
