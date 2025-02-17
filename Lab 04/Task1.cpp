
# include <iostream>
# include <string>
# include <cstring>

using namespace std;

class Book
{
    string title;
    double price;
    int *stock = new int;

    public:
 
    Book()
    {
        title = "Unknown";
        price = 0.0;
        *stock = 30;
    }

    void deleteStock()
    {
        delete[] stock;
    }

    void lowStockWarning()
    {
        if (*stock < 5)
        {
            cout << "Low stock warning for " << title << endl;
        }
    }

    void updateBookDetails()
    {
        
        cout << "Enter the updated title of the book: " << endl;
        cin.ignore();
        getline(cin, title);
        cout << "Enter the updated price of the book: " << endl;
        cin >> price;
        cout << "Enter the updated stock of the book: " << endl;
        cin >> *stock;
        lowStockWarning();
        cout << "Book Details Updated." << endl;
    }
    

    void Purchase()
    {
        cout << "Enter the quantity of the book you want to buy: " << endl;
        int q;
        cin >> q;
        if (*stock >= q)
        {
            *stock -= q;
            cout << "You have purchased the book: " << endl;
            lowStockWarning();
        }
        else
        {
            cout << q << "units of books are not available." << endl;
        }
    }
         

};

int main()
{
    Book b1;
    Book b2;

    b1.updateBookDetails();
    b1.Purchase();


    b1.deleteStock();
}
