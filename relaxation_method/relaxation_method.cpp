#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//d^2f(x,y) = -g(x,y)/c
//x--[0,Lx], y--[0,Ly]
//(a) g(x,y) = 0, f(0,y) = f(Lx,y) = f(x,0) = 0, f(x, Ly) = 1, Lx = 1, Ly = 1.5;
//(b) g(x,y) = 1, f(0,y) = f(Lx,y) = f(x,0) = f(x, Ly) = 0, Lx = Ly = 1;


 // Set Initial Value;
const double Lx = 1;
const double Ly = 1.5;
const double Delta = 0.01;
double Delta2 = Delta*Delta;
const int Nx = Lx/Delta;
const int Ny = Ly/Delta;
double S[Nx][Ny];
double n[Nx][Ny];
double nCopy[Nx][Ny];

int main()
{
    //Set Initial S(x,y);
    for(int i = 0; i < Nx; i++)
    {
        for(int j = 0; j< Ny; j++)
        {
            S[i][j] = 0;
        }
    }
    for(int i = 0; i < Nx; i++)
    {
        n[i][0] = 0;
        n[i][Ny-1] = 1;
    }
    for(int j = 0; j <Ny; j++)
    {
        n[0][j] = 0;
        n[Nx-1][j] = 0;
    }
    double del = 1e-3;
    double du = 2*del;
    double p = 0;
    double q = 1-p;
    int k = 0;
    int nmax = 1000;
    while(du > del&&k < nmax)
    {
        //cout << "test" << endl;
        du = 0;
            for(int i = 1; i < Nx-1; i++)
            {
                for(int j = 1; j < Ny-1; j++)
                {
                    double fi = n[i][j];
                    n[i][j] = p*n[i][j] + q*(0.25*(n[i+1][j] + n[i-1][j] + n[i][j+1]+n[i][j-1]) + 0.5*Delta2*S[i][j]);
                    fi = n[i][j] - fi;
                    du += fi*fi;
                }
                du = sqrt(du/((Nx-1+Ny-1)));
            }
            cout << k++ << endl;
    }
    cout << "test" << endl;

    ofstream outxyz;
    outxyz.open("xyz.txt",ios::app);
    for(int i = 0; i < Nx; i++)
    {
        for(int j = 0; j < Ny; j++)
        {
            double x = Delta*i;
            double y = Delta*j;
            outxyz << x <<' ' << y << ' ' << n[i][j] << endl;
        }
    }
    return 1;
}




