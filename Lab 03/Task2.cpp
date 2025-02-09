# include <iostream>
# include <string>

using namespace std;

class TeaMug
{
    string brand;
    float capactiy;
    float currentFillLevel;

    public:
        TeaMug()
        {
            cout << "Enter the brand of the mug: " << endl;
            getline(cin, brand);
            cout << "Enter the maximum tea level capacity of the mug (in ml) : " << endl;
            cin >> capactiy;
            cout << "Enter the current tea level in the mug (in ml): " << endl;
            cin >> currentFillLevel;
        }

        void takesSips(int sips)
        {
            currentFillLevel -= (sips * 10);
            if (currentFillLevel < 30)
            {
                cout << "The tea is about to end." << endl;
            }
            else
            {
                cout << "The current fill level of the tea mug is " << currentFillLevel << " ml" << endl;
            }
        }

        void refill(float ml)
        {
            currentFillLevel += ml;
            if (currentFillLevel > capactiy)
            {
                currentFillLevel = capactiy;
                cout << "Some tea is spilled." << endl;
                cout << "The current fill level of the tea mug is filled to full capacity." << endl;
            }
            else
            {
                cout << "The current fill level of the tea mug is " << currentFillLevel << " ml" << endl;
            }
        }

        void checkStatus()
        {
            if (currentFillLevel < 30)
            {
                cout << "The tea is about to end." << endl;
            }
            cout << "The current fill level of the tea mug is " << currentFillLevel << " ml" << endl;
        }
};

int main()
{
    TeaMug mug;

    int end = 0;
    while (end == 0)
    {
        cout << "\nMenu" << endl;
        cout << "1: Took some sips" << endl;
        cout << "2: Refill" << endl;
        cout << "3: Check Status" << endl;
        cout << "4: Exit" << endl;

        int choice;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int s;
            cout << "How many sips did you take?" << endl;
            cin >> s;
            mug.takesSips(s);
            break;

        case 2:
            float ml;
            cout << "How many ml of tea did you use to refill the mug?" << endl;
            cin >> ml;
            mug.refill(ml);
            break;

        case 3: 
            mug.checkStatus();
            break;

        case 4:
            cout << "Program Exited." << endl;
            end = 1;
            break;
        
        default:
            cout << "Invalid Input.";
            break;
        }
    }

}
