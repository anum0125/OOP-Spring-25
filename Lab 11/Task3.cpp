#include <iostream>
#include <exception>
#include <string>
using namespace std;

class FileException : public exception 
{
    public:
        virtual const char* what() const noexcept override 
        {
            return "FileException - General file error.";
        }
};

class FileNotFoundException : public FileException 
{
    public:
        const char* what() const noexcept override 
        {
            return "FileNotFoundException - File not found!";
        }
};

class PermissionDeniedException : public FileException 
{
    public:
        const char* what() const noexcept override 
        {
            return "PermissionDeniedException - Access denied!";
        }
};


void readFile(const string& filename) 
{
    if (filename == "missing.txt")
        throw FileNotFoundException();
    else if (filename == "secret.txt")
        throw PermissionDeniedException();
    else
        cout << "Reading '" << filename << "' successfully." << endl;
}

int main() 
{
    string filename;

    for (int i = 0; i < 3; i++) 
    {
        cout << "Enter filename: " << endl;
        cin >> filename;

        try 
        {
            readFile(filename);
        }
        catch (const FileNotFoundException& e) 
        {
            cout << e.what() << endl;
        }
        catch (const PermissionDeniedException& e) 
        {
            cout << e.what() << endl;
        }
        catch (const FileException& e) 
        {
            cout << e.what() << endl;
        }
    }

}
