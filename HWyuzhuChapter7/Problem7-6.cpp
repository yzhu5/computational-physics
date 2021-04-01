#include <iostream>
using namespace std;

double* FillArray(double* arr, int Size)
{
    double temp;
    int i = 0;
    while(i < Size)
    {
        cout << "Enter value #" << i+1 << ": ";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Input process terminated.\n";
            break;
        }
        else if(temp < 0)
        {
            break;
        }
        arr[i] = temp;
        i++;

     }
     return arr;
}

void ShowArray(double arr[], unsigned Size)
{
    cout << "The double array is: " << endl;
    for(unsigned i = 0; i < Size; i++)
    {
        cout << arr[i] << ' ' << endl;
    }
    cout << endl;
}

void ReverseArray(double arr[], unsigned Size)
{
    cout << "Reverse the array" << endl;
    for (int i = 0; i < Size/2; i++)
    {
        double temp = arr[i];
        arr[i] = arr[Size -1 -i];
        arr[Size -1 -i] = temp;
    }
}




int main()
{
    unsigned Size = 10;
    double arr[Size];
    FillArray(arr, Size);
    ShowArray(arr,Size);
    ReverseArray(arr, Size);
    ShowArray(arr, Size);

    return 0;
}
