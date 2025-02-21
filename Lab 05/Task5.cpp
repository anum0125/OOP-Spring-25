# include <iostream>
# include <string>

using namespace std;

class TourGuide
{
    string name;
    int yearsOfExperience;
    string specialization;

    public:

    TourGuide(string n, int y, string s) : name(n), yearsOfExperience(y), specialization(s){}

    TourGuide(){}

    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Years Of Experience: " << yearsOfExperience << endl;
        cout << "specialization: " << specialization << endl;
        cout << "--------------------------------------" << endl;
    }
};

class TravelAgency
{
    string name;
    int max;
    static int counter;
    TourGuide *tourGuideArray;
    TourGuide *t;

    public:

    TravelAgency(string name):name(name)
    {
        cout << "Enter the maximum number of Tour Guides which can be hired: " << endl;
        cin >> max;

        tourGuideArray = new TourGuide[max];
    }

    void Add(TourGuide &t)
    {
        if (counter < max)
        {
            tourGuideArray[counter] = t;
            counter++; 
            cout << "\nTour Guide has been added!" << endl;
        }
        else
        {
            cout << "\nFull capacity has been reached. Cannot hire more tour guides." << endl;
        }
    }

    void display()
    {
        cout << "--------------------------------------" << endl;
        cout << "Travel Agency: " << name << endl;
        cout << "Details of Tour Guides: " << endl;
        for (int i = 0; i < counter; i++)
        {
            tourGuideArray[i].displayDetails();
        }
    }
};

int TravelAgency :: counter = 0;

int main()
{
    TravelAgency t1("SkyWays");

    TourGuide g1("Halsey", 3, "Restaurants");
    TourGuide g2("Ali", 4, "Diverse Languages");
    TourGuide g3("Jonathan", 1, "Outdoor Activities");

    t1.Add(g1);
    t1.Add(g2);
    t1.Add(g3);

    t1.display();

}
