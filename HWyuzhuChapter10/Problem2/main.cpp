#include <iostream>
#include <cstring>

using namespace std;

class Person {

    private:
        static const unsigned LIMIT = 25;
        string lname;       // Person’s last name
        char fname[LIMIT];  // Person’s first name

    public:
        Person() {lname = ""; fname[0] = '\0';  }; // #1
        Person(const string & ln, const char * fn = "Heyyou");   // #2
        // the following methods display lname and fname
        void Show();        // firstname lastname format
        void FormalShow();  // lastname, firstname format
    };


Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show()
{
	cout << fname << ' ' << lname << endl;
}

void Person::FormalShow()
{
	cout << lname << ", " << fname << endl;
}
int main()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormalShow();
	two.Show();
	three.Show();
    return 0;
}
