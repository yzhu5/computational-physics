#include <iostream>
#include "sales.h"



namespace SALES
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    double Sales::CalAve()
    {
        double sum = 0;
        for(unsigned i = 0; i < size; i++)
        {
            sum += sales[i];
        }
        double ave = sum/size;
        return(ave);
    }

    double Sales::CalMax()
    {
        unsigned idxMax = 0;
        for(unsigned i = 0; i < size; i++)
        {
            if(sales[i] > sales[idxMax])
        {
            idxMax = i;
        }
        }
        return sales[idxMax];
    }
    double Sales::CalMin()
    {
        unsigned idxMin = 0;
        for(unsigned i = 0; i < size; i++)
        {
            if(sales[i] < sales[idxMin])
            {
                idxMin = i;
            }
        }
        return (sales[idxMin]);
    }

    Sales::Sales(double arr[], int n)
    {
        unsigned times = n < QUARTERS ? (unsigned)n : QUARTERS;
        for(unsigned i = 0; i < times; i++)
        {
            sales[i] = arr[i];
        }
        for(unsigned i = times; i < QUARTERS; i++)
        {
            sales[i] = 0;
        }
        size = times;
        average = CalAve();
        max = CalMax();
        min = CalMin();
    }

    void Sales::setSales(void)
    {
        cout << "Please input " << QUARTERS << " sale records: " ;
        size = QUARTERS;
        for(unsigned i = 0; i < QUARTERS; i++)
            {cin >> sales[i];
        if(!cin){
            size = i;
            break;
        }
            }
        for(unsigned i = (unsigned)size; i < QUARTERS; i++)
        {
            sales[i] = 0;
        }

        average = CalAve();
        max = CalMax();
        min = CalMin();
    }

    void Sales::showSales()
    {
        cout << "sales: ";
        for(const auto& e : sales)
        {
            cout << e << ' ';
        }
        cout << endl;
        cout << "average: " << average << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;

    }

}
