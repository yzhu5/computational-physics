#include <iostream>
#include <cstring>
#include "golf.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void setgolf (golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf (golf & g)
{
	cout << "Please input full name: ";
	string	strTemp;
	getline(cin, strTemp);
	if ("" == strTemp) {
		return (0);
	}
	strcpy(g.fullname, strTemp.c_str());

	cout << "Please input the handicap: ";
	int	n;
	cin >> n;
	cin.get();
	if (!n) {
		return (0);
	}
	g.handicap = n;

	return (1);
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << g.fullname << '\t' << g.handicap;
}
