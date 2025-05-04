# include <iostream>
# include <fstream>
# include <string>
using namespace std;

class getPointerPosition
{
    private:
        string fileName;

    public:
        getPointerPosition(string n): fileName(n){}
        

        void writeToFile(string line)
        {
            ofstream outFile(fileName, ios::app);
            outFile << line << endl;
            outFile.close();
        }

        streampos getPosition(ifstream &file)
        {
            return file.tellg();
        }

        void readingFile()
        {
            ifstream inFile(fileName);
            string line;
            while(getline(inFile, line))
            {
                cout << line << endl;
                cout << "Current position of the get pointer: " << getPosition(inFile) << endl;
            }

            inFile.close();
        }

};

int main()
{
    getPointerPosition p1("large_log.txt");
    
    p1.writeToFile("This is the first part of the log");
    p1.writeToFile("This is the second part of the log");
    p1.writeToFile("And the third");

    p1.readingFile();
}
