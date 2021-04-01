#include <iostream>
#include <string>
#include "golf.h"

using namespace std;

int main()
{
	const unsigned	Gsize = 2;
	golf	golfs[Gsize];
	unsigned	numGolfs = 0;
	while (numGolfs < Gsize && setgolf(golfs[numGolfs])) {
		++numGolfs;
	}

	for (unsigned i = 0; i < numGolfs; ++i) {
		showgolf(golfs[i]);
		cout << endl;
	}


	cout << endl;

    return 0;
}
