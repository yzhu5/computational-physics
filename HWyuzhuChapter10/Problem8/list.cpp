#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;
List::List(const Item arr[], unsigned n)
{
    if(arr == NULL)
    {
        L = 0;
    }
    L = size < n?size : n;
    for(unsigned i = 0; i < L; i++)
    {
        ll[i] = arr[i];
    }
}

bool List::isFull(void) const
{
    return(size == L);
}
bool List::isEmpty(void) const
{
    return(L == 0);
}
bool List::append(const Item& item)
{
    if(isFull())
    {
        return false;
    }
    ll[L++] = item;
    return true;
}
void List::visit(void(*pf)(Item& item))
{
    for(unsigned i = 0; i < L; i++)
    {
        (*pf)(ll[i]);
    }
}
void show(List::Item& item)
{
    cout << item << ' ';
}




