#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter a sentence(at lest include one #):" << endl;
    int counter = 0;
    char ch;
    while(ch = cin.get()!='$')
    {
        counter++;
    }
    cin.putback(ch);
    while(cin.get()!= '\n')
        continue;


    cout << "There are " << counter << " characters before $." << endl;
    return 0;
}
