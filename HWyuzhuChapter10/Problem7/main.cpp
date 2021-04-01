#include <iostream>
#include <cstring>

using namespace std;

class Plorg
{
	private:
		static const unsigned size = 20;
		char name[size];
		unsigned ci;

	public:
		Plorg (const char* name = "Plorg");
		void SetCI (unsigned ContentmentIdx);
		void showPlorg (void) const;
};

Plorg::Plorg (const char* Name)
{
	ci = 50;
	strncpy(name, Name, size-1);
	name[size-1] = '\0';
}

void Plorg::SetCI(unsigned contentment_idx)
{
	ci = contentment_idx;
}

void Plorg::showPlorg (void) const
{
	cout << name << ' ' << ci << endl;
}

int
main (void)
{
	Plorg	plorg;
	plorg.showPlorg();
	plorg.SetCI(5);
	plorg.showPlorg();
	return (0);
}
