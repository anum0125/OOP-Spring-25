# include <iostream>
# include <fstream>
# include <string>
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

        void readingFile()
        {
            string line;
            while(getline(file, line))
            {
                cout << line << endl;
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
    readFile vehicleFile("vehicle.txt");

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
