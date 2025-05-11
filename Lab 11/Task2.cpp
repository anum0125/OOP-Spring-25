#include <iostream>
#include <exception>
using namespace std;


class StackOverflowException : public exception 
{
    public:
        const char* what() const noexcept override 
        {
            return "StackOverflowException - Stack is full!";
        }
};


class StackUnderflowException : public exception 
{
    public:
        const char* what() const noexcept override 
        {
            return "StackUnderflowException - Stack is empty!";
        }
};


template <typename T>
class Stack 
{
    private:
        int capacity;
        int top;
        T* arr;

    public:
        Stack(int size) : capacity(size), top(-1) {
            arr = new T[capacity];
        }

        ~Stack() 
        {
            delete[] arr;
        }

        void push(T value) 
        {
            if (top >= capacity - 1)
            {
                throw StackOverflowException();
            }
            arr[++top] = value;
        }

        T pop() 
        {
            if (top < 0)
            {
                throw StackUnderflowException();
            }
            return arr[top--];
        }
};

int main() {
    Stack<int> stack(3);

    try 
    {
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4); 
    } 
    catch (const exception& e) 
    {
        cout << e.what() << endl;
    }

    try {
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop(); 
    } 
    catch (const exception& e) 
    {
        cout << e.what() << endl;
    }

    return 0;
}
