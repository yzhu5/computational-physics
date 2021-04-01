#include <iostream>
#include <string>

// constant data
const int Seasons = 4;
const char* Snames[] = {"Spring", "Summer", "Fall", "Winter"};

struct Expenses
{
	double	arr[Seasons];
};


void fill(Expenses* pexpenses)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pexpenses->arr[i];
	}
}

void show(Expenses expenses)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << expenses.arr[i] << endl;
		total += expenses.arr[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

int main()
{
	Expenses expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}
