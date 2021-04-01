#include <iostream>
using namespace std;

unsigned Factorial(unsigned num)
{
    return((0 == num)? 1 : num*Factorial(num-1));
}

int main()
{
    while(true)
    {
        cout << "Please enter a number(smaller than 20): ";
        unsigned n;
        cin >> n;
        if(!cin || n > 20)
        {
            break;
        }
        cout << n <<"! is " << Factorial(n) << endl;
    }
    cout << endl;
    return 0;
}
