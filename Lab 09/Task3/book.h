# ifndef Book
# define BOOK

# include <iostream>
using namespace std;

class Book
{
    string title;
    string author;
    string ISBN;

    public:
        Book(){}

        Book(string t, string a, string i): title(t), author(a), ISBN(i){}

        string getTitle()
        {
            return title;
        }

        string getAuthor()
        {
            return author;
        }

        string getISBN()
        {
            return ISBN;
        }
};

class Library
{
    private:
        Book array[10]; // Assuming 10 books // Composition
        int static bookCount;

    public:
        Library(){};

        void addBook(Book &b1)
        {
            if (bookCount > 10)
            {
                cout << "Limit Reached! Cannot add more books" << endl;
            }
            else
            {
                array[bookCount] = b1;
                cout << "Book Added!" << endl;
                bookCount++;
            }
        }

        void removeBook(string ISBN)
        {
            int index;
            for (int i = 0; i < bookCount; i++)
            {
                if (array[i].getISBN() == ISBN)
                {
                    for (int j = i; j < bookCount; j++)
                    {
                        array[j] = array[j+1];
                        bookCount--;
                        cout << "Book Removed!" << endl;
                    }
                }
            }
        }

        void searchBook(string ISBN)
        {
            for (int i = 0; i < bookCount; i++)
            {
                if (array[i].getISBN() == ISBN)
                {
                    cout << "Book Found at index: " << i << endl;
                    break;
                }
            }
            cout << "Book Not Found!" << endl;
        }

};

int Library :: bookCount = 0;

# endif
