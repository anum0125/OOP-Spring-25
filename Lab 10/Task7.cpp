# include <iostream>
# include <fstream>
# include <string>
using namespace std;

class tellPosition
{
    ofstream outfile;
    string fileName;

    public:
        tellPosition(string name): fileName(name)
        {
            outfile.open(fileName);
        }

        bool isOpen()
        {
            return outfile.is_open();
        }

        void writeToFile(string line)
        {
            outfile << line << endl;
        }

        streampos currentPosition()
        {
            return outfile.tellp();
        }

        ~tellPosition()
        {
            outfile.close();
        }
};

int main()
{
    ofstream("sensor_log.txt");

    tellPosition t1("sensor_log.txt");
    if (!t1.isOpen())
    {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    t1.writeToFile("Sensor 1: 25.5 C");
    cout << "Current Position of the pointer: " << t1.currentPosition() << endl;

    t1.writeToFile("Sensor 2: 98.1 %RH");
    cout << "Current Position of the pointer: " << t1.currentPosition() << endl;

    return 0;
};
