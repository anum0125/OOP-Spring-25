# include <iostream>
# include <string>

using namespace std;

class Book
{
    string title;
    double price;
    int *stock = new int;

    public:

    Book(string t, double p, int* s)
    {
        title = t;
        price = p;
        stock = s;
    }

    Book(Book &obj)
    {
        title = obj.title;
        price = obj.price;
        stock = new int;
        (*stock) = *(obj.stock); 
    }

    ~Book()
    {
        cout << "\nBook: " << title << " is destructed." << endl;
        delete[] stock;
    }


    double applyDiscount(int quantity)
    {
        if (quantity < 0)
        {
            cout << "Invalid Input." << endl;
            return 0;
        }
        else
        {
            if (quantity > 5 && quantity < 10)
            {
                return ((price*quantity)*0.95);
            }
            else if (quantity > 10)
            {
                return ((price*quantity)*0.9);
            }
            else
            {
                return price*quantity;
            }
        }
        
    }
    
    void lowStockWarning()
    {
        if (*stock < 5)
        {
            cout << "Low stock warning for " << title << endl;
            cout << "Re-maintain the inventory." << endl;
        }
    }

    void updateBookDetails()
    {
        
        cout << "Enter the updated title of the book: " << endl;
        getline(cin, title);
        cout << "Enter the updated price of the book: " << endl;
        cin >> price;
        cout << "Enter the updated stock of the book: " << endl;
        cin >> *stock;
        cout << "Book Details Updated.\n" << endl;
        lowStockWarning();
        
    }

    void Purchase()
    {
        cout << "Enter the quantity of the book you want to buy: " << endl;
        int q;
        cin >> q;
        if (*stock >= q)
        {
            *stock -= q;

            double bill = applyDiscount(q);
            if (q > 5)
            {
                cout << "\nYou availed a discount of " << (price*q)-bill << "!" << endl;
            }
            cout << "Your total bill is: " << bill << endl;
            
            cout << "\nYou have purchased the book: " << endl;
            lowStockWarning();
        }
        else
        {
            cout << q << " units of books are not available." << endl;
            cout << "The maximum available quantity is " << *stock << endl;
        }
    }

    void display()
    {
        cout << "\nTitle of the Book " << title << endl;
        cout << "Price of the Book " << price << endl;
        cout << "Stock Available of the Book " << (*stock) << endl;
        cout << "Address of Book: " << this << endl;
        cout << "---------------------------------------" << endl;
    }
};

int main()

{
    int* s = new int;
    *s = 10;
    Book b1("Harry Potter", 950.0, s);

    Book b2 = b1;
    b2.updateBookDetails();

    b1.display();
    b2.display();

    delete[] s;

}
