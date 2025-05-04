# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
using namespace std;

class readFile
{
    private:
        ifstream file;
        string filename;

    public:
        readFile(string n): filename(n)
        {
            file.open(filename);
        }

        bool isOpen()
        {
            return file.is_open();
        }

        int convertToInteger(string word)
        {
            return stoi(word);
        }
        
        void parsing(string myLine)
        {
            istringstream line(myLine);
            string Type, ID, Name, year, ExtraData, Certification;
            int Year;

            getline(line, Type, ',');
            getline(line, ID, ',');
            getline(line, Name, ',');
            getline(line, year, ',');
            getline(line, ExtraData, ',');
            getline(line, Certification, ',');

            // converting year to int using stoi

            Year = convertToInteger(year);

            cout << "Type: " << Type << endl;
            cout << "ID: " << ID << endl;
            cout << "Name: " << Name << endl;
            cout << "Year: " << Year << " (integer)" <<endl; // integer
            cout << "ExtraData: " << ExtraData << endl;
            cout << "Certification: " << Certification << "\n" << endl;
                
        }

        void readingFile()
        {
            int i = 1;
            string line;
            while(getline(file, line))
            {
                cout << "Vehicle " << i << ": " << endl;
                parsing(line);
                i++;
            }
        }

        ~readFile()
        {
            if (file.is_open())
            {
                file.close();
            }
        }
};

int main()
{
    readFile vehicleFile("vehicles.txt");

    if (vehicleFile.isOpen())
    {
        vehicleFile.readingFile();
    }
    else
    {
        cout << "File could not be opened." << endl;
    }

    return 0;
    
}
