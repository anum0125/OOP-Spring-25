# include <iostream>
# include <fstream>
# include <string>

using namespace std;

class updateRecord
{
    private:
        string fileName;

    public:
        updateRecord(const string name): fileName(name){}
        
        void writeToFile(const char* data) 
        {
            ofstream outFile(fileName, ios::binary | ios::app);
            if (!outFile) 
            {
                cerr << "Error opening file for writing." << endl;
                return;
            }
    
            outFile.write(data, 5);
            outFile.close();
        }

        void updateSecondBlock(const char* newData) 
        {
            fstream file(fileName, ios::in | ios::out | ios::binary);
            if (!file) 
            {
                cerr << "Error opening file for updating." << endl;
                return;
            }
            file.seekp(5); 
            file.write(newData, 5); 
            file.close();
        }

        void displayContent(const char* fileName)
        {
            ifstream inFile;
            inFile.open(fileName);
            if (!inFile)
            {
                cerr << "Error opening file for reading!" << endl;
            }

            char ch;
            while(inFile.get(ch))
            {
                cout << ch;
            }
            inFile.close();
        }


};

int main()
{
    updateRecord r1("config.txt");
    r1.writeToFile("AAAAA");
    r1.writeToFile("BBBBB");
    r1.writeToFile("CCCCC");
    cout << "Original Data: " << endl;
    r1.displayContent("config.txt");

    cout << "\nUpdated Data: " << endl; 
    r1.updateSecondBlock("XXXXX");
    r1.displayContent("config.txt");

    return 0;
}
