#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        cerr << "Wrong! Format: LeftFileName RightFileName OutputFileName" << endl;
        return(EXIT_FAILURE);
    }

    const string LeftFileName = argv[1];
    const string RightFileName = argv[2];
    const string OutputFileName = argv[3];
    if(LeftFileName == OutputFileName || RightFileName == OutputFileName)
    {
        cerr << "Output filename can't be the same with Input filename." <<endl;
    }
    ifstream FinLeft(LeftFileName);
    if(!FinLeft)
    {
        cerr << LeftFileName << " open failed." << endl;
    }
    ifstream FinRight(RightFileName);
    if(!FinRight)
    {
        cerr << RightFileName << " open failed." << endl;
    }
    ofstream Fout(OutputFileName);
    if(!Fout)
    {
        cerr << OutputFileName << " open failed." << endl;
    }
    cout << "Copy " << LeftFileName << " and " << RightFileName << " into " << OutputFileName << " ." << endl;
    string left,right;
    while(FinLeft.good()&&FinRight.good())
    {
        getline(FinLeft,left);
        Fout << left;
        Fout << " ";
        getline(FinRight,right);
        Fout << right;
        Fout << '\r'<<'\n';
    }
    if(FinLeft.eof()&&FinRight.eof())
    {
        while(FinRight.good())
        {
            getline(FinRight,right);
            Fout << right;
            Fout << endl;
        }
    }
    if(!FinLeft.eof()&& FinRight.eof())
    {
        while(FinLeft.good())
        {
            getline(FinLeft,left);
            Fout << left;
            Fout << endl;
        }
    }
    if(FinLeft.eof()&&FinRight.eof())
    {
        cout << "Finish!" << endl;
    }else
    {
        cout << "Something wrong." << endl;
    }

    return (EXIT_SUCCESS);
}
