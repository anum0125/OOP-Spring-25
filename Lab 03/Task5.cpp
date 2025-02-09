# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>

using namespace std;

class GroceryStore
{
    string items[100];
    float prices[100];
    int inventoryStock[100];
    int currentItems;

    public:
        GroceryStore()
        {
            currentItems = 0;
            for (int i = 0; i < 100; i++)
            {
                items[i] = " ";
                prices[i] = 0.00;
                inventoryStock[i] = 0;
            }
        }

        void addItems()
        {
            if (currentItems < 100)
            {
                cout << "Enter the new item: " << endl;
                getline(cin, items[currentItems]);

                cout << "Enter the price of the item: " << endl;
                cin >> prices[currentItems];

                cout << "Enter the inventory stock of the product: " << endl;
                cin >> inventoryStock[currentItems];
                cin.ignore();

                currentItems++;
                cout << "New Item Added." << endl;
            }
            else
            {
                cout << "Current Items have a reached a maximum of 100. Cannot add new items." << endl;
            }
        }

        void updatePrice()
        {
            string findItem;
            cout << "Enter the name of the item whose price is to be changed: " << endl;
            getline(cin, findItem);

            int found = 0, i = 0; 
            while (found == 0 && i < currentItems)
            {
                if (findItem == items[i])
                {
                    cout << "Enter the updated price of the item:" << endl;
                    cin >> prices[i];
                    cin.ignore();
                    found = 1;
                    cout << "Price Updated." << endl;
                }
                i++;
            }
            if (found == 0)
            {
                cout << "Item was not found." << endl;
            }
        }

        void updateInventory()
        {
            string findItem;
            cout << "Enter the name of the item you want to update inventory of: " << endl;
            getline(cin, findItem);

            int found = 0, i = 0; 
            while (found == 0 && i < currentItems)
            {
                if (findItem == items[i])
                {
                    cout << "Enter the updated inventory stock of the item:" << endl;
                    cin >> inventoryStock[i];
                    cin.ignore();
                    found = 1;
                    cout << "Inventory Updated." << endl;
                }
                i++;
            }
            if (found == 0)
            {
                cout << "Item was not found." << endl;
            }
        }

        void displayInventory()
        {
            for (int i = 0; i < currentItems; i++)
            {
                cout << "\nItem: " << items[i] << endl;
                cout << "Price per unit: " << prices[i] << " dollars" << endl;
                cout << "Inventory Stock: " << inventoryStock[i] << " units" <<  endl;
            }
        }

        void generateReceipt()
        {
             cout << "\nList of items: " << endl;
             for (int i = 0; i < currentItems; i++)
             {
                if (inventoryStock[i] > 0)
                {
                    cout << "\nkItem Number: " << i << endl;
                    cout << "Item name: " << items[i] << endl;
                    cout << "Price " << prices[i] << endl;
                }
             }
             int end = 0;
             int totalItems;
             cout << "\nEnter the number of items you want to buy: " << endl;
             cin >> totalItems;
             string receipt[totalItems][3];
             int i = 0;
             int total = 0;
             while (i < totalItems)
             {
                int item_num;
                cout << "\nItem # " << i+1 << endl;
                cout << "\nEnter the number of the item you want to buy from the list above: " << endl;
                cin >> item_num;
                float quantity;
                cout << "Enter the quantity of the item you want to buy: " << endl;
                cin >> quantity;
                if (inventoryStock[item_num] > quantity)
                {
                    receipt[i][0] = items[item_num];
                    receipt[i][1] = to_string(quantity);
                    receipt[i][2] = to_string(quantity * prices[item_num]);
                    total += quantity * prices[item_num];
                    inventoryStock[item_num] -= quantity; 
                }

                
             }
             cout << "  Items    |   Quantity   | Price  " << endl;
             for (int i = 0; i < totalItems; i++)
             {
                cout << receipt[i][0] << " | " << receipt[i][1] << " | " << receipt[i][2] << " | " << endl;
             }
             cout << "\nTotal Bill: " << total << endl;

        }


};

int main()
{
    GroceryStore grocery;
    
    int end = 0;
    while (end == 0)
    {
        cout << "\nOptions" << endl;
        cout << "1: Add an item" << endl;
        cout << "2: Update the price of an item" << endl;
        cout << "3: Update the inventory stock of an item" << endl;
        cout << "4: Display inventory" << endl;
        cout << "5: Generate a receipt for a customer" << endl;
        cout << "6: Exit" << endl;

        int option;
        cout << "Enter your choice: " << endl;
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            grocery.addItems();
            break;

        case 2:
            grocery.updatePrice();
            break;

        case 3: 
            grocery.updateInventory();
            break;

        case 4:
            grocery.displayInventory();
            break;

        case 5:
            grocery.generateReceipt();
            break;

        case 6:
            cout << "Program Exited." << endl;
            end = 1;
            break;
        
        default:
            cout << "Invalid Input.";
            break;
        }
    }
}
