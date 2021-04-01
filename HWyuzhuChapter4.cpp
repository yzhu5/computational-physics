#include <iostream>
#include <array>
#include <cstring>
#include <string>

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
	cout << "Problem1:" <<endl;
	char FirstName[200];
	char LastName[200];
	char letter;
	int age;
	cout << "What is your first name? ";
	cin.getline(FirstName, 200);
	cout << "What is your last name? ";
	cin.getline(LastName, 200);
	cout << "What letter grade do you deserve? ";
	cin >> letter;
	cout <<"What is your age? ";
	cin >> age;
	cout << "Name: " << LastName << ", " << FirstName << endl;
	cout << "Grade: " << char(letter+1) << endl;
	cout << "age: " << age << endl;
    cin.get();
    cout << endl;

}

void Problem2()
{
	cout << "Problem2:" <<endl;
	string FirstName;
	string LastName;
	char letter;
	int age;
	cout << "What is your first name? ";
	getline(cin,FirstName);
	cout << "What is your last name? ";
	getline(cin,LastName);
	cout << "What letter grade do you deserve? ";
	cin >> letter;
	cout <<"What is your age? ";
	cin >> age;
	cout << "Name: " << LastName << ", " << FirstName << endl;
	cout << "Grade: " << char(letter+1) << endl;
	cout << "age: " << age << endl;
	cin.get();
	cout << endl;
}

void Problem3()
{
	cout << "Problem3:" <<endl;
	char FirstName[100];
	char LastName[100];
	cout << "Enter your first name: ";
	cin.getline(FirstName,100);
	cout << "enter your last name: ";
	cin.getline(LastName,100);
	cout << "Here is the information in a single string: " << LastName << ", " << FirstName << endl;
    cout << endl;
}

void Problem4()
{
    cout << "Problem4:" <<endl;
	string FirstName;
	string LastName;
	cout << "Enter your first name: ";
	cin >> FirstName;
	cout << "enter your last name: ";
	cin >> LastName;
	string FullName = LastName + ", " + FirstName;
	cout << "Here is the information in a single string: " << FullName << endl;
    cout << endl;
}

void Problem5()
{
	cout << "Problem5:" <<endl;
	typedef struct CandyBar{
			string name;
			double weight;
			int calories;
	}CandyBar;

	CandyBar snack = {"Mocha Munch", 2.3,350};
	cout << "name: " << snack.name << endl;
	cout << "weight: " << snack.weight << endl;
	cout << "calories: " << snack.calories << endl;
	cout <<endl;
}

void Problem6()
{
	cout << "Problem6:" <<endl;
	typedef struct CandyBar{
		string name;
		double weight;
		int calories;
	}CandyBar;
	CandyBar candybars[3];
	candybars[0] = {"large", 5.0,500};
	candybars[1] = {"medium", 3.0, 300};
	candybars[2] = {"small", 1.0, 100};
	cout <<"Here is the information of three candybars:" << endl;
	cout <<"brand name 	size 	calories"<<endl;
	for(int i = 0; i<3; i++){
		cout <<candybars[i].name <<"	        " <<candybars[i].weight << "	" << candybars[i].calories <<endl;
	}
	cout << endl;

}

void Problem7()
{
	cout << "Problem7:" <<endl;
	typedef struct Pizza{
		string name;
		double diameter;
		double weight;
	}Pizza;
	Pizza pizza;
	cin.get();
	cout << "Enter the name of the pizza company: ";
	getline(cin, pizza.name);
	cout << "Enter the diameter of the pizza: ";
	cin >> pizza.diameter;
	cout << "Enter the weight of the pizza: ";
	cin >>pizza.weight;
	cout <<  "Here is the information of this pizza:"<<endl;
	cout << "The nam of the pizza company: " <<pizza.name<<endl;
	cout << "The diameter of the pizza: " << pizza.diameter << endl;
	cout << "The weight of the pizza: " << pizza.weight << endl;
    cout << endl;
}

void Problem8()
{
	cout << "Problem8:" <<endl;
	typedef struct Pizza{
		string name;
		double diameter;
		double weight;
	}Pizza;

	Pizza *pizza = new Pizza;
	cout << "Enter the diameter of this pizza: ";
	cin >> pizza->diameter;
	cin.get();
	cout << "Enter the name of pizza company: ";
	getline(cin, pizza->name);
	cout << "Enter the weight of this pizza: ";
	cin >>pizza->weight;
	cout <<  "Here is the information of this pizza:"<<endl;
	cout << "The nam of the pizza company: " <<pizza->name<<endl;
	cout << "The diameter of the pizza: " << pizza->diameter << endl;
	cout << "The weight of the pizza: " << pizza->weight << endl;
    cout << endl;
}

void Problem9()
{
	cout << "Problem9:" <<endl;
	typedef struct CandyBar{
		string name;
		double weight;
		int calories;
	}CandyBar;
	CandyBar *candybars = new CandyBar[3]{
		{"large", 5.0,500},
		{"medium", 3.0, 300},
		{"small", 1.0, 100},
	};
	cout <<"Here is the information of three candybars:" << endl;
	cout <<"brand name 	size 	calories"<<endl;
	for(int i = 0; i<3; i++){
		cout <<candybars[i].name <<"	        " <<candybars[i].weight << "	" << candybars[i].calories <<endl;
	}
	cout << endl;

}

void Problem10()
{
	cout << "Problem10:" <<endl;
	array<double,3> Times;
	double AverageTime;
	cout << "Enter three times for the 40-yd dash: " << endl;
	cout << "First time: ";
	cin >> Times[0];
	cout << "Second time: ";
	cin >> Times[1];
	cout << "Third time; ";
	cin >> Times[2];
	AverageTime = (Times[0]+Times[1]+Times[2])/3.0;
	cout << "Three results:" << Times[0] << ", "<<Times[1] <<", " <<Times[2] << endl;
	cout <<"The average time is: " << AverageTime << endl;
	cout << endl;
}



int main(){

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
