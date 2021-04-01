#include <iostream>
#include "list.h"
using namespace std;

int main()
{

    List ls;
    ls.visit(show);
    cout << ls.isEmpty() << endl;
    List::Item arr[3] = {1,2,3};
    List ls1(arr, 3);
    cout << ls.isEmpty() << ' ' << ls.isFull() <<endl;
    ls1.visit(show);
    cout << endl;
    ls1.append(4);
    ls1.visit(show);

    return 0;
}
