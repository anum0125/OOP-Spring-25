# include <iostream>
# include <string>

using namespace std;

class Movie
{
    string title;
    string director;
    int duration; // in minutes
    
    public:

    Movie(string t, string d, int du) : title(t), director(d), duration(du){}
    
    Movie(){}

    ~Movie(){}

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "-------------------------------------" << endl;
    }
};

class CinemaHall
{
    string name;
    Movie *movies;
    Movie m;
    int max;
    static int counter;

    public:

    CinemaHall(string name) : name(name)
    {
        cout << "Enter the maximum number of Movies which can be screened: " << endl;
        cin >> max;

        movies = new Movie[max];
    }

    ~CinemaHall(){}

    void Add(Movie m)
    {
        if (counter < max)
        {
            movies[counter] = m;
            counter++; 
            cout << "\nMovie has been added!" << endl;
        }
        else
        {
            cout << "\nFull capacity has been reached. Cannot screen more movies." << endl;
        }
    }

    void display()
    {
        cout << "--------------------------------------" << endl;
        cout << "Movie Hall Name: " << name << endl;
        cout << "Details of Movies: " << endl;
        for (int i = 0; i < counter; i++)
        {
            movies[i].display();
        }
    }
};

int CinemaHall :: counter = 0;

int main()
{
    CinemaHall c1("Nueplex");

    Movie m1("Harry Potter and the Philosopher's Stone", "Chris Columbus", 152);
    Movie m2("Home Alone 2: Lost in New York", "Chris Columbus", 120);
    Movie m3("The Hobbit: The Desolation of Smaug", "Peter Jackson", 161);

    c1.Add(m1);
    c1.Add(m2);
    c1.Add(m3);

    c1.display();
}
