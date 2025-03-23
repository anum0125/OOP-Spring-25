#include <iostream>
using namespace std;

class Media 
{
    protected:
        string title, publicationDate, uniqueID, publisher;
    public:
        Media(string t, string pd, string id, string pub)
            : title(t), publicationDate(pd), uniqueID(id), publisher(pub) {}

        virtual void displayInfo() = 0;
        virtual void checkOut() { cout << title << " has been checked out." << endl; }
        virtual void returnItem() { cout << title << " has been returned." << endl; }
        virtual ~Media() {}
};

class Book : public Media 
{
    private:
        string author, ISBN;
        int numberOfPages;
    public:
        Book(string t, string pd, string id, string pub, string a, string isbn, int pages)
            : Media(t, pd, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

        void displayInfo() override 
        {
            cout << "Book: " << title << " | Author: " << author << " | ISBN: " << ISBN << " | Pages: " << numberOfPages << endl;
        }
};

class DVD : public Media 
{
    private:
        string director;
        double duration;
        double rating;
    public:
        DVD(string t, string pd, string id, string pub, string d, double dur, double r)
            : Media(t, pd, id, pub), director(d), duration(dur), rating(r) {}

        void displayInfo() override 
        {
            cout << "DVD: " << title << " | Director: " << director << " | Duration: " << duration << " hrs | Rating: " << rating << endl;
        }
};

class CD : public Media 
{
    private:
        string artist, genre;
        int numberOfTracks;
    public:
        CD(string t, string pd, string id, string pub, string art, int tracks, string g)
            : Media(t, pd, id, pub), artist(art), numberOfTracks(tracks), genre(g) {}

        void displayInfo() override 
        {
            cout << "CD: " << title << " | Artist: " << artist << " | Tracks: " << numberOfTracks << " | Genre: " << genre << endl;
        }
};

void searchMedia(string title) 
{
    cout << "Searching for media with title: " << title << endl;
}

void searchMedia(string author, bool isBook) 
{
    cout << "Searching for books by author: " << author << endl;
}

void searchMedia(int year) 
{
    cout << "Searching for media published in year: " << year << endl;
}

int main() 
{
    Book book1("C++ Programming", "2020", "B101", "Tech Press", "John Doe", "123-456789", 350);
    DVD dvd1("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 2.5, 9.0);
    CD cd1("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", 9, "Pop");

    book1.displayInfo();
    dvd1.displayInfo();
    cd1.displayInfo();

    book1.checkOut();
    book1.returnItem();
    
    searchMedia("C++ Programming");
    searchMedia("John Doe", true);
    searchMedia(2010);
    
    return 0;
}
