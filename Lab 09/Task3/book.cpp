# include "Book.h"
# include <iostream>
using namespace std;

int main()
{
    Book b1("Harry Potter", "JK Rowling", "92AD06LP86Q");
    cout << "Book Details: " << endl;
    cout << "Title: " << b1.getTitle() << endl;
    cout << "Author: " << b1.getAuthor() << endl;
    cout << "ISBN: " << b1.getISBN() << endl;

    return 0;
}
