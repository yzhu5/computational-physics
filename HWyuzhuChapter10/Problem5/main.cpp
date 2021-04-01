#include <iostream>
#include <cctype>
#include "stack.h"
using namespace std;

int main()
{
    Stack mi;
    char ch;
    Item item;
    double total = 0;

    cout << "Please enter a char(a to add a customer, p to pop a customer, q to quit): " << endl;
    while(cin >> ch && tolower(ch) != 'q')
    {
        while(cin.get()!= '\n')
        {
            continue;
        }
        ch = tolower(ch);
        if(ch == 'a')
        {
            if(mi.isfull())
            {
                cout << "Stack is full." << endl;
            }else
            {
            cout << "Please enter a customer name: ";
            cin.getline(item.fullname, 35);
            cout << "Please enter payment: ";
            cin >> item.payment;
            mi.push(item);
            }
        }else if(ch == 'p')
        {
            if(mi.isempty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                mi.pop(item);
                total +=item.payment;
                cout << "total is " << total << " ." << endl;
            }
        }
       cout << "Please enter a char(a to add a customer, p to pop a customer, q to quit): " << endl;
    }


    return 0;
}
