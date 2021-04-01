#include <iostream>
#include <array>
#include <string>
#include <cstring>

using namespace std;

void Problem1();
void Problem2();
void Problem3();
void Problem4();
void Problem5();
void Problem6();
void Problem7();
void Problem8();
void Problem9();
void Problem10();

void Problem1()
{
	cout << "Problem1:" << endl;
	int num1, num2;
	int sum = 0;
	cout << "Please enter the first number: ";
	cin >> num1;
	cout << "Please enter the second number: ";
	cin >> num2;
	for(int i = num1; i<=num2; i++)
	{
		sum +=i;
	}
	cout << "The sum from number " << num1 << " to " << num2 <<" is: " << sum << endl;
	cout << endl;

}

void Problem2()
{
	cout <<"Problem2:"<< endl;
	const int ArSize = 100;
	array<long double, ArSize+1> factorials;
	factorials[0] = factorials[1] = 1;
	for(int i = 2; i <= ArSize; i++)
	{
		factorials[i] = i*factorials[i-1];
	}
	for(int i = 0; i<= ArSize; i++)
	{
		cout << i << "! = " << factorials[i] << endl;
	}
	cout << endl;
}

void Problem3()
{
    cout << "Problem3:" << endl;
    double num = 0;
    double sum = 0;
    while(1)
    {
        cout << "Please enter a number(0 to exit): ";
        cin >> num;
        if(num == 0)
            break;
        sum += num;
        cout << "Until now, the sum of all numbers is: " << sum << endl;
    }
    cout << "Done." << endl;
    cout << endl;
}

void Problem4()
{
    cout << "Problem4:" << endl;
    double DaphneAccount = 100.0;
    double CleoAccount = 100.0;
    int years = 0;
    do{
        DaphneAccount += 10.0;
        CleoAccount += CleoAccount * 0.05;
        ++years;
        cout << years <<" year(s) " <<", Daphne: " << DaphneAccount <<", Cleo: " << CleoAccount << endl;
    }
    while(DaphneAccount >= CleoAccount);
    cout << "After " << years << " years, Cleo's investment exceed Daphne's investment, Daphne's investment is: " << DaphneAccount << ", Cleo's investment is: " << CleoAccount <<"." << endl;
    cout << endl;

}

void Problem5()
{
    cout << "Problem5:" << endl;
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October", "November", "December"};
    int Sales[12];
    int TotalSales = 0;
    cout << "Enter the sales of number of book <C++ for fools> each month: " << endl;
    for(int i = 0; i < 12; i++)
    {
        cout << month[i] <<": ";
        cin >> Sales[i];
        TotalSales +=Sales[i];
    }
    cout << "The total sales for this year is: " << TotalSales << endl;
    for(int i = 0; i < 12; i++)
    {
        cout << month[i] << ": " << Sales[i] << endl;
    }
    cout << endl;
}

void Problem6()
{
    cout << "Problem6:" << endl;
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October", "November", "December"};
    int Sales[3][12];
    int Year[3] = {0};
    int TotalSales = 0;
    for(int j = 0; j < 3; j ++)
    {
    cout << "Enter the sales of number of book <C++ for fools> each month for year "<< j+1 << ": " << endl;
    for(int i = 0; i < 12; i++)
    {
        cout << month[i] <<": ";
        cin >> Sales[j][i];
        Year[j] +=Sales[j][i];
    }
        TotalSales += Year[j];
    }
    for(int j = 0; j < 3; j++)
    {
    cout << "The total sales for year "<<j+1<< " is: " << Year[j] << endl;
    for(int i = 0; i < 12; i++)
    {
        cout << month[i] << ": " << Sales[j][i] << endl;
    }
    }
    cout << "The total sales for these 3 years is: " << TotalSales << endl;
    cout << endl;

}

void Problem7()
{
    cout << "Problem7:" <<endl;
    typedef struct AutoMobile{
    string make;
    int year;
    }AutoMobile;

    int num = 0;
    cout << "How many cars do you wish to catalog? ";
    cin >> num;
    cin.get();
    AutoMobile *cars = new AutoMobile[num];
    for(int i = 0; i < num; i++)
    {
        cout << "Car #"<< i+1 <<": " <<endl;
        cout << "Please enter the make:";
        getline(cin, cars[i].make);
        cout << "Please enter the year make: ";
        cin >> cars[i].year;
        cin.get();
    }
    cout << "Here is your collection:" << endl;
    for(int i = 0; i < num; i++)
    {
        cout <<cars[i].year << " " << cars[i].make <<endl;
    }
    cout << endl;
}

void Problem8()
{
    cout << "Problem8:" << endl;
    int WordNum = 0;
    char InputWords[200];

    cout << "Enter words (to stop, type the word done): " << endl;
    while(cin >> InputWords)
    {
        if(strcmp(InputWords, "done"))
        {
            WordNum++;
        }
        else
            break;
    }

    cout << "You entered a total of " << WordNum << " words." << endl;
    cout << endl;
}

void Problem9()
{
    cout << "Problem9:" << endl;
    int WordNum = 0;
    string InputWords;

    cout << "Enter words (to stop, type the word done): " << endl;
    while(cin >> InputWords)
    {
        if(InputWords != "done")
        {
            WordNum++;
        }
        else
            break;
    }

    cout << "You entered a total of " << WordNum << " words." << endl;
    cout << endl;
}

void Problem10()
{
    cout << "Problem10:" << endl;
    int row = 0;
    cout << "Enter number of rows: ";
    cin >>row;
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if(j<row-i-1)
                cout << ".";
            else
                cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
	Problem1();
	Problem2();
	Problem3();
	Problem4();
	Problem5();
	Problem6();
	Problem7();
	Problem8();
	Problem9();
	Problem10();

	return 0;
}
