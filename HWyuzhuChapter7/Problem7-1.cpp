#include <iostream>

using namespace std;

double CalHarmonicMean(unsigned x, unsigned y);

double CalHarmonicMean(unsigned x, unsigned y)
{
    return(2.0*x*y/(x+y));
}

int main()
{
    while(true)
    {
        unsigned x, y;
        cout << "Please enter a pair of  positive integer numbers(0 to exit):";
        cin >> x >> y;
        if(0 == x||0 == y)
        {
            cout << "bye." << endl;
        }
        else{
        cout << "Harmonic Mean for " << x << " and " << y << " is: " << CalHarmonicMean(x, y) << endl;
        }
        cout << endl;
        return(0);
        }
}
