# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
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
            size_t pos = word.find(':');
            if (pos != string::npos)
            {
                string afterColon = word.substr(pos+1);
                return stoi(afterColon);
            }
            cout << "No colon founded!" << endl;
            return 0;
        }

        float convertToFloat(string word)
        {
            size_t pos = word.find(':');
            if (pos != string::npos)
            {
                string afterColon = word.substr(pos+1);
                return stof(afterColon);
            }
            cout << "No colon founded!" << endl;
            return 0;
        }

        pair<int, int> conversionForHybrid(string word)
        {
            size_t pos1 = word.find(':');
            size_t pos2 = word.find('|');
            size_t pos3 = word.find(':', pos2);

            if (pos1 != string::npos && pos2 != string::npos)
            {
                string afterFirstColon = word.substr(pos1+1, pos2-1);
                string afterSecondColon = word.substr(pos3+1);
                return { stoi(afterFirstColon), stoi(afterSecondColon) };
            }
            else
            {
                cout << "No colon or pipe found!" << endl;
                return {0,0};
            }
        }

        void parsing(string myLine)
        {
            istringstream line(myLine);
            string Type, ID, ExtraData;

            getline(line, Type, ',');
            getline(line, ID, ',');
            getline(line, ExtraData, ',');
            getline(line, ExtraData, ',');
            getline(line, ExtraData, ',');

            if (Type == "AutonomousCar")
            {
                float extracted = convertToFloat(ExtraData);
                cout << "ID: " << ID << endl;
                cout << "Extracted SW Value: " << extracted << endl;
            }
            else if (Type == "ElectricVehicle")
            {
                int extracted = convertToInteger(ExtraData);
                cout << "ID: " << ID << endl;
                cout << "Extracted Battery Value: " << extracted << endl;
            }
            else if (Type == "HybridTruck")
            {
                pair<int, int> extracted = conversionForHybrid(ExtraData);
                cout << "ID: " << ID << endl;
                cout << "Extracted Cargo Value: " << extracted.first << endl;
                cout << "Extracted Battery Value: " << extracted.second << endl;
            }
            
        }

        void readingFile()
        {
            int i = 1;
            string line;
            while(getline(file, line))
            {
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
