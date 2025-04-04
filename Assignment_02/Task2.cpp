# include <iostream>
using namespace std;


class Visitor;

class Ghost
{
    protected:
        string workerName;
        int scareLevel;

    public:
        Ghost(string w, int s): workerName(w), scareLevel(s){}

        Ghost(){}

        virtual void PerformHaunting()
        {
            cout << "Haunting Performed!" << endl;
        }

        Ghost operator +(Ghost g1)
        {
            Ghost temp;
            temp.scareLevel = this->scareLevel + g1.scareLevel;
            if (temp.scareLevel > 10)
            {
                temp.scareLevel = 10;
            }
            temp.workerName = this->workerName + " and " + g1.workerName;
            return temp;
        }

        friend ostream& operator<<(ostream& out, const Ghost& g);

        int getScareLevel() 
        {
            return scareLevel;
        }

};

ostream& operator<<(ostream& out, const Ghost& g) 
{
    out << "The name of the worker playing the ghost: " << g.workerName << endl;
    out << "The scare level of the Ghost: " << g.scareLevel << endl;
    return out; 
}

class Poltergeists: virtual public Ghost
{
    public:
        Poltergeists(string w, int s): Ghost(w, s){}


        void PerformHaunting() override
        {
            cout << "Haunting Performed By Moving Objects!" << endl;
        }
};

class Banshees: public Ghost
{
    public:
        Banshees(string w, int s): Ghost(w, s){}

        void PerformHaunting() override
        {
            cout << "Haunting Performed By Screaming Loudly!" << endl;
        }
};

class ShadowGhosts: virtual public Ghost
{
    public:
        ShadowGhosts(string w, int s): Ghost(w, s){}

        void PerformHaunting() override
        {
            cout << "Haunting Performed By Whispering Creepily!" << endl;
        }
};

class ShadowPoltergeist: public Poltergeists, public ShadowGhosts
{
    public:
        ShadowPoltergeist(string w, int s): Ghost(w, s), Poltergeists(w, s), ShadowGhosts(w, s){}

        void PerformHaunting() override
        {
            cout << "Haunting Performed By Whispering Creepily And Moving Objects!" << endl;
        }
};

class HauntedHouse
{
    string name;
    Ghost **arrayOfGhosts; //array of ghost pointers
    int numberOfGhosts; //must have atleast 3 ghosts

    public:

        HauntedHouse(string n, int g): name(n), numberOfGhosts(g)
        {

            cout << "Enter details for " << numberOfGhosts << " ghosts:\n";

            for (int i = 0; i < numberOfGhosts-1; i++)
            {
                int choice;
                string worker;
                int scare;

                cout << "\nChoose type of ghost " << i + 1 << ":\n";
                cout << "1. Poltergeist\n2. Banshee\n3. ShadowGhost\n4. ShadowPoltergeist\n";
                cout << "Enter choice: ";
                cin >> choice;

                cin.ignore();
                cout << "Enter name for ghost " << i + 1 << ": ";
                getline(cin, worker);

                cout << "Enter scare level for ghost " << i + 1 << ": ";
                cin >> scare;

                switch (choice)
                {
                case 1:
                    arrayOfGhosts[i] = new Poltergeists(worker, scare);
                    break;
                case 2:
                    arrayOfGhosts[i] = new Banshees(worker, scare);
                    break;
                case 3:
                    arrayOfGhosts[i] = new ShadowGhosts(worker, scare);
                    break;
                case 4:
                    arrayOfGhosts[i] = new ShadowPoltergeist(worker, scare);
                    break;
                default:
                    cout << "Invalid choice! Defaulting to basic Ghost.\n";
                    arrayOfGhosts[i] = new Ghost(worker, scare);
                }
            }

            arrayOfGhosts[numberOfGhosts-1] = new Ghost(*arrayOfGhosts[0] + *arrayOfGhosts[1]);

        }                      

        friend void Visit(Visitor visitors[], int numVisitors, HauntedHouse& house);  
        
        void showDetails()
        {
            cout << "Haunted House Name: " << name << endl;
            cout << "Number of Ghosts: " << numberOfGhosts << endl;
            cout << "Ghosts Details: " << endl;
            for (int i = 0; i < numberOfGhosts; i++)
            {
                cout << "\nGhost " << i+1 << endl;
                cout << *arrayOfGhosts[i] << endl;
            }
        }

        ~HauntedHouse()
        {
            for (int i = 0; i < numberOfGhosts; i++)
            {
                delete arrayOfGhosts[i]; 
            }
            delete[] arrayOfGhosts;
            cout << "HauntedHouse: " << name << " destroyed." << endl;
        }

};

class Visitor
{
    string name;
    int bravery;

    public:
        Visitor(string n, int b): name(n), bravery(b){}

        Visitor(){}

        friend void Visit(Visitor visitors[], int numVisitors, HauntedHouse& house);
};

void Visit(Visitor v[], int numVisitors, HauntedHouse& h)
{
    cout << "Haunted House: " << h.name << endl;
    for (int i = 0; i < numVisitors; i++)
    {
        cout << "\nVisitor " << i+1 << endl;
        cout << v[i].name << " Enters the Haunted House!" << endl;
        for (int j = 0; j < h.numberOfGhosts; j++)
        {
            h.arrayOfGhosts[j]->PerformHaunting();
            cout << "Ghost's " << j+1 << " Scare Level: " << h.arrayOfGhosts[j]->getScareLevel() << endl;
            if (h.arrayOfGhosts[j]->getScareLevel() <= v[i].bravery) 
            {
                cout << v[i].name << " laughs and taunts the ghost!" << endl;
            }
            else if(h.arrayOfGhosts[j]->getScareLevel() > v[i].bravery+2)
            {
                cout << v[i].name << " gets a shaky voice..." << endl;
            }
            else  
            {
                cout << v[i].name << " screams and runs away!" << endl;
            }
                    
        }
    }
}

int main()
{
    cout << "\nHaunted House 1: \n";
    HauntedHouse h1("ShadowMoor Asylum", 3);
    Visitor visitorsArray1[3];
    
    Visitor v1("Alexander", 7);
    Visitor v2("Ella", 9);
    Visitor v3("Anna", 2);

    visitorsArray1[0] = v1;
    visitorsArray1[1] = v2;
    visitorsArray1[2] = v3;

    h1.showDetails();

    Visit(visitorsArray1, 3, h1);

    cout << "\nHaunted House 2: \n";

    HauntedHouse h2("Abracadabra", 3);
    Visitor visitorsArray2[3];
    
    Visitor v4("Ali", 7);
    Visitor v5("Ayesha", 9);
    Visitor v6("Ahmed", 2);

    visitorsArray2[0] = v4;
    visitorsArray2[1] = v5;
    visitorsArray2[2] = v6;

    h2.showDetails();

    Visit(visitorsArray2, 3, h2);

    cout << "\nHaunted House 3: \n";

    HauntedHouse h3("Avada Kedavra", 3);
    Visitor visitorsArray3[3];
    
    Visitor v7("Kenan", 7);
    Visitor v8("Leyla", 9);
    Visitor v9("Selin", 2);

    visitorsArray3[0] = v7;
    visitorsArray3[1] = v8;
    visitorsArray3[2] = v9;

    h3.showDetails();

    Visit(visitorsArray3, 3, h3);
}
