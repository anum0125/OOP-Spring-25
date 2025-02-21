# include <iostream>
# include <string>

using namespace std;

class Product
{
    string name;
    int id;
    static int counter;
    float price;

    public:

    Product(string name, float price) : name(name), price(price), id(counter++){}

    Product(){}

    ~Product(){}

    void viewDetails()
    {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Product Price: " << price << endl;
        cout << "-------------------------------------" << endl;
    }

    float getPrice()
    {
        return price;
    }

    string getName()
    {
        return name;
    }
};

class GroceryStore
{
    string name;
    int max;
    static int count;
    Product *p;
    Product *productArray;

    public:

    GroceryStore(string name) : name(name)
    {
        cout << "Enter the maximum number of products which can be stored: " << endl;
        cin >> max;

        productArray = new Product[max];
    }

    ~GroceryStore()
    {
        delete[] productArray;
    }

    void Add(Product &p)
    {
        if (count < max)
        {
            productArray[count] = p;
            count++; 
            cout << "\nProduct has been added!" << endl;
        }
        else
        {
            cout << "\nFull capacity has been reached. Cannot add more products." << endl;
        }
    }

    void Search(string name)
    {
        bool found = false;
        int i = 0;

        while ((i < count) && (found == false))
        {
            if (productArray[i].getName() == name)
            {
                found = true;
                cout << "\n" << endl;
                productArray[i].viewDetails();
            }
            else
            {
                i++;
            }
        }
        if (found == false)
        {
            cout << "\nThe product was not found." << endl;
        }
    }

    void sort()
    {
        for(int i = 0; i < count - 1; i++) 
        {
            for(int j = i + 1; j < count; j++) 
            {
                if(productArray[j].getPrice() < productArray[i].getPrice())
                {
                    Product temp = productArray[i];
                    productArray[i] = productArray[j];
                    productArray[j] = temp;
                }
            }
        }

        cout << "The inventory has been sorted in ascending order according to the price." << endl;
    }

    void display()
    {
        cout << "\nGrocery Name: " << name << endl;
        cout << "-------------------------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            productArray[i].viewDetails();
        }

    }
};

int Product :: counter = 0;
int GroceryStore :: count = 0;

int main()
{
    GroceryStore g1("Express Store");

    Product p1("Shampoo", 945);
    Product p2("Deodrant", 1200);
    Product p3("Soap", 60);
    Product p4("Conditioner", 1000);

    g1.Add(p1);
    g1.Add(p2);
    g1.Add(p3);
    g1.Add(p4);

    g1.sort();

    g1.Search("Deodrant");
    g1.Search("Scrub");

    g1.display();


}
