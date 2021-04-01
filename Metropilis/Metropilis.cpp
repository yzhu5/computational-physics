#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

//The integral function is: f(x) = e^(-r^2/2)(x*y*z)^2
//Use normal distribution as probability function: w(r) = (1/(2*Pi)^0.5)*e^((-r*r)/2), the range is from -infinity to +infinity, and the integration is 1
//Z = (2*Pi)^0.5 = 2.5066282533
//g(x) = f(x)/w(x) = Z*(x*y*z)^2
//when total points = 1000, S = 0.209215 +- 0.0124505
//when total points = 10000, S = 0.222655 +- 0.003842
//when total points = 100000, S = 0.217108 +- 0.00117517
//when total points = 1000000, S = 0.215174 +- 0.000370706
//The error bar decreased when total points increase

/*
static void metropolis()
{
    double rold = r;
    r = r + 2*h*(rand() - 0.5);
    double wnew = weight(r);
    if(wnew > w*(rand()/RAN_MAX))
    {
        w = wnew;
        ++iaccept;
    }
}
*/

double weight1(double r)
{
    return exp(-r*r/2);
}
double g(double x, double y, double z, double r)
{
    return pow(x*y*z,2);
}
int main()
{
    static int nsize = 100000;
    static int nskip = 15;
    static int ntotal = nsize*nskip;
    static int neq = 10000;
    static int iaccept = 0;
    static double r, w, h = 4.6, Fac = 2.5066282533;

    srand(12314);

    double x = 1*(2*double(rand())/double(RAND_MAX) - 1);
    double y = 1*(2*double(rand())/double(RAND_MAX) - 1);
    double z = 1*(2*double(rand())/double(RAND_MAX) - 1);
    r = sqrt(x*x+y*y+z*z);
    w = weight1(r);
    for(int i = 0; i < neq; ++i)
    {
        double rold = r;
        double xold = x;
        double yold = y;
        double zold = z;
        //cout << rand() << endl;
    x = x + h*(2*double(rand())/double(RAND_MAX) - 1);
    //cout << x << endl;
    y = y + h*(2*double(rand())/double(RAND_MAX) - 1);
    z = z + h*(2*double(rand())/double(RAND_MAX) - 1);
    r = sqrt(x*x+y*y+z*z);
    //cout  << r << endl;
    if(r > sqrt(3)*1) {r = rold;x = xold;y = yold; z = zold;}
    else{
    double wnew = weight1(r);
    if(wnew > w*(rand()/RAND_MAX))
    {
        w = wnew;
        ++iaccept;
    }else{
        r = rold;
        x = xold;
        y = yold;
        z = zold;
    }
    }
    }
    double s0 = 0;
    double ds = 0;
    for(int i = 0; i < ntotal; ++i)
    {
        double rold = r;
        double xold = x;
        double yold = y;
        double zold = z;
    x = x + h*(2*double(rand())/double (RAND_MAX) - 1);
    y = y + h*(2*double(rand())/double(RAND_MAX) - 1);
    z = z + h*(2*double(rand())/double(RAND_MAX) - 1);
    r = sqrt(x*x+y*y+z*z);
    //cout << r << endl;
    if(r > sqrt(3)*1) {r = rold;x = xold; y = yold; z = zold;}
    else{
    double wnew = weight1(r);
    //cout << wnew << endl;
    if(wnew > w*(rand()/RAND_MAX))
    {
        w = wnew;
        ++iaccept;
    }else{
    r = rold;
    x = xold;
    y = rold;
    z = zold;
    }
    }


    if(i%nskip == 0)
    {
        double f = g(x,y,z,r);
        s0 += f;
        ds += f*f;
    }
    }
    s0 /= nsize;
    ds /= nsize;
    ds = sqrt(abs(ds - s0*s0)/nsize);
    s0 *= Fac;
    ds *= Fac;
    double accept = 100.0*iaccept/(nsize);
    cout << "S = " << s0 << " +- "  << ds << endl;
    cout << "Accept rate = " << accept << "%" << endl;

return 0;

}
