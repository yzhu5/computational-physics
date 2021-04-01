#include <iostream>

using namespace std;

int main()
{
    using namespace std;
    string input;
    unsigned total = 0;
    cout << "Enter a line: " << endl;
    getline(cin, input);
    while(cin &&"" != input)
    {
        cout << "\"" << input << "\" contains " ;
        cout << input.size() << " characters" << endl;
        total += input.size();
        cout << total << " characters total" << endl;
        cout << "Enter next line (empty line to quit): "<< endl;
        getline(cin ,input);
    }
    cout << "Bye." << endl;
    return 0;
}
