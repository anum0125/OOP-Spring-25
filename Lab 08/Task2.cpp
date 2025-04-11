# include <iostream>
using namespace std;

class Book
{
    string title;
    float price;

    public:
        Book(){}

        Book(string t, float p): title(t), price(p){}

        friend class Manager;
};

class Manager
{
    string name;
    int id;

    public:
        Manager(){}

        Manager(string n, int i): name(n), id(i){}

        void displayBookDetails(Book const &b) const
        {
            cout << "\nBook Details: " << endl;
            cout << "\nTitle of the Book: " << b.title << endl;
            cout << "Price of the Book: $" << b.price << endl;
        }

        void modifyPrice(Book &b)
        {
            cout << "\nEnter the modified/discounted price: " << endl;
            cin >> b.price;
        }
};

int main()
{
    Book b1("Harry Potter and the Goblet of Fire", 45.5);
    Manager m1("Sarah Williams", 2011);

    m1.displayBookDetails(b1);
    m1.modifyPrice(b1);
    m1.displayBookDetails(b1);
}


