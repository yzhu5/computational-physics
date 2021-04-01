#include <iostream>
#include "sales.h"

using namespace std;

int main()
{
	using namespace SALES;

	Sales	sales1;
	double	salesLst[] = {1.1,2.2,3.3,4.4,5.5,6.6};
	setSales(sales1, salesLst, sizeof(salesLst)/sizeof(salesLst[0]));
	showSales(sales1);

	Sales	sales2;
	setSales(sales2);
	showSales(sales2);


	cout << endl;
    return 0;
}
