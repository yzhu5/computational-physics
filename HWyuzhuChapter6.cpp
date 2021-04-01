#include <iostream>
#include <fstream>
#include <cctype>

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

void Problem1()
{
	cout << "Problem1: "<< endl;
	cout << "Input symbols(@ to exit): " << endl;
	char ch;
	while((ch = cin.get()) != '@')
	{
		if(isdigit(ch))
		{
			continue;
		}

		if(islower(ch))
		{
			ch = (char)toupper(ch);
		}
		else if(isupper(ch))
		{
			ch = (char)tolower(ch);
		}
		cout << ch << endl;
	}
	cout << endl;
}

void Problem2()
{
    cout << "Problem2: " <<endl;
    cout << "Input 10 numbers(non-numeric to exit):" << endl;
    const unsigned int Size = 10;
    double Donation[Size];
    double sum = 0;
    unsigned int counter = 0;
    while(counter < Size && cin >> Donation[counter])
    {
        sum +=Donation[counter++];
    }
    double Average = double(sum/counter);
    unsigned int LargeThanAve = 0;
    for(int i = 0; i < counter; i++)
    {
        if(Donation[i] > Average)
        {
            ++LargeThanAve;
        }
    }

    cout << "The average of the numbers is: " << Average <<" . There are " << LargeThanAve <<" numbers in the array larger than the average." << endl;
    cin.get();
    cout << endl;
}

void Problem3()
{
    cout << "Problem3: " << endl;
    cout << "Please enter one of the following choices: " << endl;
    cout << "c) carnivore\t" << "p) pianist" << endl;
    cout << "t) tree\t\t" << "g) game" << endl;
    bool exit = false;
    char ch;
    while(cin >> ch && !exit){
    switch(ch){
    case'c':
        {
            cout << "I am a carnivore." << endl;
        }
        exit = true;
        break;
    case 'p':
        {
            cout << "I am not a pianist." << endl;
        }
        exit = true;
        break;
    case't':
        {
            cout << "I want to be a tree." << endl;
        }
        exit = true;
        break;
    case 'g':
        {
            cout << "I can play the game." << endl;
        }
        exit = true;
        break;
    default:
        cout << "Please enter a c, p ,t,t or g: ";
        break;

    }
    }

    cout << endl;

}

void Problem4()
{
    cout << "Problem4:"<< endl;
    enum Preference {fullname, title, bopname};
    struct Bop
    {
        char fullname[100];
        char title[100];
        char bopname[100];
        Preference preference;
    };
    Bop bops[] = {{"Xiao Hong","Apple","Dr.Hong",title},
                {"Xiao Lan", "HuaWei","Dr.Lan",bopname},
                {"Xiao Hei","Google","Dr.Hei",fullname},
                {"Xiao Fen","MI","Dr.Fen",title}};
    bool Display = true;
    while(Display)
    {
        cout << "Benevolent Order of Programmers Report" << endl;
		cout << "a. display by name" << "\t" << "b. display by title" << endl;
		cout << "c. display by bopname" << "\t" << "d. display by preference" << endl;
		cout << "q. quit" << endl;
    char ch;
    if(!(cin >> ch))
    {
        Display = false;
        break;
    }
    switch(ch){
        case'a':
            {
                for(const auto& e:bops)
                {
                    cout << e.fullname << endl;
                };
            }
            break;
        case'b':
        {
            for(const auto& e: bops)
            {
                cout << e.title << endl;
            };
        }
        break;
        case 'c':
            {
                for(const auto& e : bops)
                {
                    cout << e.bopname << endl;
                };
            }
            break;
        case 'd':
            {
                for(const auto& e : bops)
                {
                    if(fullname == e.preference)
                    {
                        cout << e.fullname << endl;
                    }else if(title ==e.preference)
                    {
                        cout << e.title << endl;
                    }else if(bopname == e.preference)
                    {
                        cout << e.bopname << endl;
                    }else
                    {
                        ;
                    }
                }
            }
            break;
        case 'q':
            {
                cout << "Bye!" <<endl;
                Display = false;
            }
            break;

            default:
            {
                cout << "Error." << endl;
            }
            break;
    }
    }
    cout << endl;
}

void Problem5()
{
    cout <<" Problem5: " << endl;
    double tvarp;
    cout << "Please enter your total income: " << endl;
    if(cin >>tvarp && tvarp >=0)
    {
        double FourSection[4] = {5000, 10000, 20000};
        if(tvarp <= 5000)
        {
            FourSection[0] = tvarp;
            FourSection[1] = FourSection[2] = FourSection[3] = 0;
        }else if((tvarp -= 5000) <=10000)
        {
            FourSection[1] = tvarp;
            FourSection[2] = FourSection[3] = 0;
        } else if((tvarp -= 10000) <= 20000)
        {
            FourSection[2] = tvarp;
            FourSection[3] = 0;
        }
        else
        {
            FourSection[3] = tvarp - 20000;
        }

        cout << "Here is the income tax:" << endl;
        cout << FourSection[0] << " * 0% + " << FourSection[1] << " * 10% + " << FourSection[2] << " * 15% + " << FourSection[3] << " * 20% " << " = " << FourSection[0] * 0 + FourSection[1] * 0.1 + FourSection[2] * 0.15 + FourSection[3] * 0.2 << endl;
	}
	cout << endl;
}

void Problem6()
{
    cout << "Problem6: "<< endl;
    struct Donor
    {
        string name;
        double amount;
    };
    cout << "Please enter the number of contributors: ";
    unsigned num;
    cin >> num;
    Donor* const pdonor = new Donor[num];
    for(int i = 0; i < num; i++)
    {
        cout << "Please enter the name of contributor: ";
        cin >> pdonor[i].name;
        cout << "Please enter the amount of contribution: ";
        cin >> pdonor[i].amount;
    }
    cout << "Name of Grand Patrons: " << endl;
    int counter = 0;
    for(int i = 0; i < num; i++)
    {

        if(pdonor[i].amount >= 10000)
        {
            cout << pdonor[i].name << endl;
            counter++;
        }
    }
    if(!counter)
    {
        cout << "none." << endl;
    }
    cout << "Name of Patrons: " << endl;
    counter = 0;
    for(int i = 0; i < num; i++)
    {
        if(pdonor[i].amount < 10000)
        {
            cout << pdonor[i].name << endl;
            counter++;
        }
    }
    if(!counter)
    {
        cout << "none." << endl;
    }
    cout << endl;
}

void Problem7()
{
    cout << "Problem7: " << endl;
    unsigned Vowels = 0, Consonants = 0, Others = 0;
    cout << "Enter words(q to exit)";
    string	word;
	while (cin>>word&& "q" != word) {
		char&	FirstChar = word[0];
		if (!isalpha(FirstChar)) {
			++Others;
		} else if (	'a' == FirstChar || 'A' == FirstChar ||
					'e' == FirstChar || 'E' == FirstChar ||
					'i' == FirstChar || 'I' == FirstChar ||
					'o' == FirstChar || 'O' == FirstChar ||
					'u' == FirstChar || 'U' == FirstChar)
        {
			++Vowels;
		} else {
			++Consonants;
		}
		cin.get();
	}
	cin.get();
	cout << Vowels << " words beginning with vowels" << endl;
	cout << Consonants <<" words beginning with consonants" << endl;
	cout << Others << " others" << endl;
	cout << endl;
}

void Problem8()
{
    cout << "Problem8: " << endl;
    string FileName;
    ofstream inFile;
    int num = 0;
    char ch = 0;
    cout << "Enter the file name: ";
    getline(cin, FileName);
    inFile.open(FileName.c_str());
    for(int i = 0; i<1; i++)
    {
        inFile << "abc"<<endl;
    }
    ifstream inFil;
    inFil.open(FileName.c_str());
    while((ch = inFil.get())!=EOF)
    {
        num++;
    }
    num;
    cout << "There are " << num << " characters in " << FileName << " file." << endl;
    cout << endl;
}

void Problem9()
{
    cout << "Problem9:" << endl;
    string FileName;
    ofstream inFile;
    cout << "Enter the file name: ";
    getline(cin, FileName);
    inFile.open(FileName.c_str());
    inFile << "4" << endl;
    inFile << "Sam Stone" << endl;
    inFile << "2000" << endl;
    inFile << "Freida Flass" << endl;
    inFile << "100500" << endl;
    inFile << "Tammy Tubbs" << endl;
    inFile << "5000" << endl;
    inFile << "Rich Raptor" << endl;
    inFile << "55000" << endl;

    struct Donor
    {
        string name;
        double amount;
    };

    ifstream ifs;
    ifs.open(FileName.c_str());
    unsigned num;
    ifs >> num;
    Donor* const pdonor = new Donor[num];
    for(int i = 0; i < num; i++)
    {
        ifs.get();
        getline(ifs,pdonor[i].name);
        ifs >> pdonor[i].amount;
    }
    cout << "Name of Grand Patrons: " << endl;
    int counter = 0;
    for(int i = 0; i < num; i++)
    {

        if(pdonor[i].amount >= 10000)
        {
            cout << pdonor[i].name << endl;
            counter++;
        }
    }
    if(!counter)
    {
        cout << "none." << endl;
    }
    cout << "Name of Patrons: " << endl;
    counter = 0;
    for(int i = 0; i < num; i++)
    {
        if(pdonor[i].amount < 10000)
        {
            cout << pdonor[i].name << endl;
            counter++;
        }
    }
    if(!counter)
    {
        cout << "none." << endl;
    }
    cout << endl;
}


int main()
{
	int i;
	bool Display = true;
	while(Display)
    {
            cout << "Enter problem number:";
            if(!(cin >> i))
    {
        Display = false;
        break;
    }
        cin.get();
		switch(i){
		case 1:
		Problem1();
		break;
		case 2:
		Problem2();
		break;
		case 3:
		Problem3();
		break;
		case 4:
		Problem4();
		break;
		case 5:
		Problem5();
		break;
		case 6:
		Problem6();
		break;
		case 7:
		Problem7();
		break;
		case 8:
		Problem8();
		break;
		case 9:
		Problem9();
		break;
		default:
		cout <<"Please enter 1,2,3,4,5,6,7,8,9:";
		break;
	}
    }
	return 0;
}
