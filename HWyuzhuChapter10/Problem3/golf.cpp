#include <iostream>
#include <cstring>
#include "golf.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

golf::golf(const char * name, int hc)
{
	strcpy(fullname, name);
	handicap = hc;
}

int golf::setgolf (void)
{
	cout << "Please input full name: ";
	string	strTemp;
	getline(cin, strTemp);
	if ("" == strTemp) {
		return (0);
	}

	cout << "Please input the handicap: ";
	int	n;
	cin >> n;
	cin.get();
	if (!n) {
		return (0);
	}
	*this = golf(strTemp.c_str(), n);

	return (1);
}

void golf::sethandicap(int hc)
{
	handicap = hc;
}

void golf::showgolf(void)
{
	cout << fullname << '\t' << handicap;
}
