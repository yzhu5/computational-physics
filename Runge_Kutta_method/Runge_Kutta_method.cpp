#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

    double C1 = 4.455*pow(10,15); //constant
    double MG = 1.989*6.672*pow(10,19); // mass * G

    double FuncTheta(double t, double r, double theta);
    double FuncR(double t, double r, double q);
    double FuncQ(double t, double r, double q);

int main()
{

    /*
    Equations:
    dtheta/dt = C1/(r^2)
    dr/dt = q
    dq/dt = (C1^2/r^3 - MG/r^2)
    */

    double year = 365*24*3600;//time for one year
    int n = 365*24;//steps
    double h = year/n;

    // build arrays
    vector <double> q(n);
    double r[n];
    double theta[n];
    double t[n];
    double x[n];
    double y[n];
    //initial conditions
    q[0] = 0;
    r[0] = 1.521*pow(10,11);
    theta[0] = 0;
    x[0] = r[0]*cos(theta[0]);
    y[0] = r[0]*sin(theta[0]);
    cout <<"Aphelion: "<<endl;
    cout <<"Angle: " << theta[0]<<endl;
    cout << "Radius: " << r[0] << endl;
    //cout << C1/pow(r[0],2) << endl;
    for(int i = 0; i < n - 1; i++)
    {
        t[i] = h*i;
        double kt1,kt2,kt3,kt4,kr1,kr2,kr3,kr4,kq1,kq2,kq3,kq4;
        kt1 = FuncTheta(t[i],r[i],theta[i]);
        kr1 = FuncR(t[i],r[i],q[i]);
        kq1 = FuncQ(t[i],r[i],q[i]);
        kt2 = FuncTheta(t[i]+h/2,r[i]+kr1*h/2,q[i]+kt1*h/2);
        kr2 = FuncR(t[i]+h/2,r[i]+kr1*h/2,q[i]+kq1*h/2);
        kq2 = FuncQ(t[i]+h/2,r[i]+kr1*h/2,q[i]+kq1*h/2);
        kt3 = FuncTheta(t[i]+h/2,r[i]+kr2*h/2,q[i]+kt2*h/2);
        kr3 = FuncR(t[i]+h/2,r[i]+kr2*h/2,q[i]+kq2*h/2);
        kq3 = FuncQ(t[i]+h/2,r[i]+kr2*h/2,q[i]+kq2*h/2);
        kt4 = FuncTheta(t[i]+h,r[i]+kr3*h,q[i]+kt3*h);
        kr4 = FuncR(t[i]+h,r[i]+kr3*h,q[i]+kq3*h);
        kq4 = FuncQ(t[i]+h,r[i]+kr3*h,q[i]+kq3*h);
        q[i+1] = q[i] + (kq1 + 2*kq2 + 2*kq3 + kq4)*h/6;
        r[i+1] = r[i] + (kr1 + 2*kr2 + 2*kr3 + kr4)*h/6;
        theta[i+1] = theta[i] + (kt1 + 2*kt2 + 2*kt3 + kt4)*h/6;
        //cout << kt1 << " " << kt2 << ' ' << kt3 <<" " << kt4 << ' ' << endl;
        x[i+1] = r[i+1]*cos(theta[i+1]);
        y[i+1] = r[i+1]*sin(theta[i+1]);
        if(i == n/2)
        {
        cout <<"perihelion: "<<endl;
        cout <<"Angle: " << theta[i+1]<<endl;
        cout << "Radius: " << r[i+1] << endl;
        }

    }

    ofstream outxy;
    outxy.open("xy.txt",ios::app);;
    for(int i = 0; i < n; i++)
    {
        outxy << x[i] <<' ' << y[i] << endl;
    }
    return 0;
}

double FuncTheta(double t, double r, double theta)
{
    double Res = C1/pow(r,2);
    //cout << Res << endl;
    return Res;
}
double FuncR(double t, double r, double q)
{
    return q;
}
double FuncQ(double t, double r, double q)
{
    return pow(C1,2)/pow(r,3) - MG/pow(r,2);
}
