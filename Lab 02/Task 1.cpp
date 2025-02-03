# include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "\n";

    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> array[i];
    }

    int sum = array[0];
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        sum += array[i];
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    cout << "\n";
    cout << "The total sum of the array is: " << sum << endl;
    cout << "The average is: " << (double)sum/size << endl;
    cout << "The maximum value in the array is: " << max << endl;

    delete [] array;
}
