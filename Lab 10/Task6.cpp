# include <iostream>
# include <string>
# include <fstream>
# include <cstring>

using namespace std;

class InventoryItem
{
    private:
        int ID;
        char itemName[20];

    public:
        InventoryItem() : ID(0)
        {
            itemName[0] = '\0';
        }

        InventoryItem(int id, const char* name): ID(id)
        {
            strncpy(itemName, name, sizeof(itemName)-1);
            itemName[sizeof(itemName) - 1] = '\0';
        } 

        void writeToFile(const char* fileName)
        {
            ofstream outFile(fileName, ios::binary | ios::app);
            if (!outFile)
            {
                cerr << "Error occured opening file for writing" << endl;
                return;
            }
            outFile.write((char*)&ID, sizeof(ID));
            outFile.write((char*)&itemName, sizeof(itemName));

            outFile.close();
        }

        bool readFile(ifstream &inFile)
        {
            inFile.read((char*)&ID, sizeof(ID));
            if (!inFile) return false;

            inFile.read((char*)&itemName, sizeof(itemName));
            return inFile.good();
        }

        void displayData()
        {
            cout << "Item ID: " << ID << endl;
            cout << "Item Name: " << itemName << endl;
        }

};

int main()
{
    InventoryItem item1(101, "Soaps");
    item1.writeToFile("inventory.dat");

    InventoryItem item2(102, "Chips");
    item2.writeToFile("inventory.dat");

    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile)
    {
        cerr << "Error occured opening file for reading" << endl;
        return 1;
    }

    InventoryItem item;
    while (item.readFile(inFile)) 
    {
        item.displayData();
    }

    inFile.close();
    
    return 0;
}
