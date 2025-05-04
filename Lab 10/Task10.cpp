#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class skipLine 
{
    private:
        string fileName;

    public:
        skipLine(string n) : fileName(n) {}

        void writeToFile(const char* line) 
        {
            ofstream outFile(fileName, ios::app);
            if (!outFile) 
            {
                cerr << "Error opening the file to write!" << endl;
                return;
            }
            outFile << line << endl;
            outFile.close();
        }

        void readSpecificRecord(int recordNumber) 
        {
            ifstream inFile(fileName);
            if (!inFile) 
            {
                cerr << "Error opening the file to read!" << endl;
                return;
            }

            string line;
            int currentLine = 1;

            while (getline(inFile, line)) 
            {
                if (currentLine == recordNumber) 
                {
                    cout << line << endl;
                    break;
                }
                currentLine++;
            }

            if (currentLine < recordNumber) 
            {
                cerr << "Record number out of range." << endl;
            }

            inFile.close();
        }
};

int main() 
{
    skipLine s1("data_records.txt");

    s1.writeToFile("Record 1");
    s1.writeToFile("Record 2");
    s1.writeToFile("Record 3");
    s1.writeToFile("Record 4");

    s1.readSpecificRecord(3); 

    return 0;
}
