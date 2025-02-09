# include <iostream>
# include <string>

using namespace std;

class MarkerPen
{
        string brand;
        string color;
        float inkLevel;
        int refillabilty;
        float max;

    public:

        void setAttributes(string b, string c, float i, int r, float m)
        {
            brand = b;
            color = c;
            inkLevel = i;
            refillabilty = r;
            max = m;
        }

        void write(float h)
        {
            inkLevel -= h * 0.5; // using the marker for one hour consumes 0.5 ml of ink
            if (inkLevel < 0.5)
            {
                cout << "\nThe ink is about to end.";
            } 
            else
            { 
                cout << "The current ink level allows you to use the marker for approximately " << inkLevel/0.5 << "hours." << endl;
            }
        }

        void refill(float ml)
        {
            inkLevel += ml;
            if (inkLevel > 6)
            {
                inkLevel = 6;
                cout << "\nThe marker can take a maximum of " << max << "ml." << endl;
                cout << "The marker has been fully refilled to " << max << "ml." << endl;
            }
            else
            {
                cout << "The current ink level is: " << inkLevel << "ml." << endl;
            }
            cout << "The current ink level allows you to use the marker for approximately " << inkLevel/0.5 << "hours." << endl;
        }

        void checkStatus()
        {
            cout << "The current ink level is: " << inkLevel << "ml." << endl;
            cout << "The current ink level allows you to use the marker for approximately " << inkLevel/0.5 << "hours." << endl;
        }
};

int main()
{
    MarkerPen pen;

    string b, c;
    int r; 
    float i, m;
    cout << "Enter the brand of the marker: " << endl;
    getline(cin, b);
    cout << "Enter the color of the marker: " << endl;
    getline(cin, c);
    cout << "Is the marker refillable?" << endl;
    cout << "0: Not Refillable, 1: Refillable " << endl;
    cin >> r;
    while (r != 0 && r != 1)
    {
        cout << "Invalid Input." << endl;
        cout << "Is the marker refillable?" << endl;
        cout << "0: Not Refillable, 1: Refillable " << endl;
        cin >> r;
    }
    cout << "Enter the maximum ink capacity of the marker (in ml) : " << endl;
    cin >> m;
    cout << "Enter the current ink level of the marker (in ml): " << endl;
    cin >> i;

    pen.setAttributes(b, c, i, r, m);

    int end = 0;
    while (end == 0)
    {
        cout << "\nMenu" << endl;
        cout << "1: Write" << endl;
        cout << "2: Refill" << endl;
        cout << "3: Check Status" << endl;
        cout << "4: Exit" << endl;

        int choice;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            float h;
            cout << "For how many hours did you use the marker?" << endl;
            cin >> h;
            pen.write(h);
            break;

        case 2:
            float ml;
            cout << "How many ml of ink did you use to refill the marker?" << endl;
            cin >> ml;
            pen.refill(ml);
            break;

        case 3: 
            pen.checkStatus();
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
