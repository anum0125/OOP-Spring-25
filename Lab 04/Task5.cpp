# include <iostream>
# include <string>

using namespace std;

class Book
{
    string title;
    double price;
    int *stock = new int;
    int bookID;
    static int bookCounter;

    public:

    Book(string t, double p, int *s) : title(t), price(p), stock(s), bookID(++bookCounter){}

    void display()
    {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << *stock << endl;
        cout << "--------------------------------------" << endl;
    }

    int getCounter()
    {
        return bookCounter;
    }

    Book(Book &obj)
    {
        this->title = obj.title;
        this->price = obj.price;
        this->stock = new int;
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
        cin.ignore();
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
};

int Book::bookCounter = 0;

int main()
{
    int *s = new int;
    *s = 30;
    Book b1("Harry Potter", 950.0, s);
    Book b2("Great Gatsby", 870, s);

    b1.display();


    b2.display();




    
}
