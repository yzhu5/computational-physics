#include <iostream>
#include <fstream>

using namespace std;

int
main (int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Format:command file_name" << endl;
		return (EXIT_FAILURE);
	}

	ofstream	file_out(argv[1]);
	string	Input;
	cout << "Please write a sentence(Ctrl + z to exit):" << endl;
	while (getline(cin, Input)) {
		file_out << Input << endl;
	}


	return (EXIT_SUCCESS);
}

