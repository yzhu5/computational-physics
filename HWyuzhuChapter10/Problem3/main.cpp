#include <string>
#include <iostream>
#include "golf.h"

using namespace std;

int main()
{
	const unsigned	Gsize = 2;
	golf	golfs[Gsize];
	unsigned	numGolfs = 0;
	while (numGolfs < Gsize && golfs[numGolfs].setgolf()) {
		++numGolfs;
	}

	for (unsigned i = 0; i < numGolfs; ++i) {
		golfs[i].showgolf();
		cout << endl;
	}


	cout << endl;
    return 0;
}
