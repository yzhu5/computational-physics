
//Based on boundary conditions, the solution for u"(x) = λu(x) is u(x) = A*sin(n*Pi*x/L) with associated λ = -(n*Pi)^2;
//A is a constant that can be any real or complex number, n is positive integer:1, 2.., L = xf - xi = 1;
//In my simulation, I tried 3 cases:
//n = 1, A = 0.0321253, λ = -9.8696, which is closed to -(1*Pi)^2 = -9.86960;
//n = 2, A = 0.0159135, λ = -39.4784, which is closed to -(2*Pi)^2 = -39.4784;
//n = 3, A = 0.0105983, λ = -88.8266, which is closed to -(3*Pi)^2 = -88.82643;



#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

double Lam;
double g1(double y1,double y2,double x);
double g2(double y1,double y2,double x);
int main()
{
    double err = 1e-6;
    double x,x2,y1,y2,f0,f1;
    double y[2][100];
    int n = 100;
    double d = 1;
    double xi = 0;
    double xf = 1;
    double h  = (xf-xi)/(n-1);
    double yi = 0;
    double yf = 0;
    double x0 = -50;
    double dx = 1;
    double x1 = x0+dx;
    y[0][0] = 0;
    y[1][0] = 0.1;

    //Shooting method
    while (fabs(d) > err)
    {

        Lam = x0;
        for (int i = 0; i < n-1; ++i)
        {
            x = xi+h*(i+1);
            y1 = y[0][i];
            y2 = y[1][i];
            double k11 = h*g1(y1,y2,x);
            double k21 = h*g2(y1,y2,x);
            double k12 = h*g1((y1+k11/2),(y2+k21/2),(x+h/2));
            double k22 = h*g2((y1+k11/2),(y2+k21/2),(x+h/2));
            double k13 = h*g1((y1+k12/2),(y2+k22/2),(x+h/2));
            double k23 = h*g2((y1+k12/2),(y2+k22/2),(x+h/2));
            double k14 = h*g1((y1+k13),(y2+k23),(x+h));
            double k24 = h*g2((y1+k13),(y2+k23),(x+h));
            y[0][i+1] = y[0][i]+(k11+2*(k12+k13)+k14)/6;
            y[1][i+1] = y[1][i]+(k21+2*(k22+k23)+k24)/6;
        }
        f0 = y[0][n-1]-0;

        Lam = x1;
        for (int i = 0; i < n-1; ++i)
        {
            x = xi+h*(i+1);
            y1 = y[0][i];
            y2 = y[1][i];
            double k11 = h*g1(y1,y2,x);
            double k21 = h*g2(y1,y2,x);
            double k12 = h*g1((y1+k11/2),(y2+k21/2),(x+h/2));
            double k22 = h*g2((y1+k11/2),(y2+k21/2),(x+h/2));
            double k13 = h*g1((y1+k12/2),(y2+k22/2),(x+h/2));
            double k23 = h*g2((y1+k12/2),(y2+k22/2),(x+h/2));
            double k14 = h*g1((y1+k13),(y2+k23),(x+h));
            double k24 = h*g2((y1+k13),(y2+k23),(x+h));
            y[0][i+1] = y[0][i]+(k11+2*(k12+k13)+k14)/6;
            y[1][i+1] = y[1][i]+(k21+2*(k22+k23)+k24)/6;
        }
        f1 = y[0][n-1]-0;
        d = f1-f0;
        x2 = x1-f1*(x1-x0)/d;
        x0 = x1;
        x1 = x2;
    }
    cout << "The eigenvalue: " << " "<< Lam << endl;
    ofstream outxy1;
    outxy1.open("xy1.txt", ios::app);
    for (int i = 0; i < n; ++i)
    {
        x = h*i;
        cout << x << " " <<y[0][i] << endl;
        outxy1 << x << " " << y[0][i] << endl;
    }

    //Really solution
    ofstream outxy2;
    outxy2.open("xy2.txt",ios::app);
    for(int i = 0; i < n; i++)
    {
        x = h*i;
        int n1 = 3;
        double a = 0.0105983;
        //a1 = 0.0321253;
        //a2 = 0.0159135;
        //a3 = 0.0105983;
        double z = a*sin(n1*3.14159*x);
        outxy2 << x << " " << z << endl;
    }

    return 0;
}

double g1(double y1,double y2,double x)
        {
            return y2;
        }
double g2(double y1,double y2,double x)
        {
            return (Lam*y1);
        }
