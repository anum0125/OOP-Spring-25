# include <iostream>
# include <exception>
using namespace std;

class InvalidValueException: public exception
{
  public:
    const char* what() const noexcept override
    {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void validateAge(int age)
{
    try
    {
        if (age < 0 || age > 120)
        {
            throw InvalidValueException();
        }
        cout << "Age is valid: " << age << endl;
        
    }
    catch(const InvalidValueException &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;
    validateAge(age);
}
