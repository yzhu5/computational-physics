#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <random>

using namespace std;

struct Particle
{
    vector<double> x;//position
    vector<double> y;//position
    vector<double> Vx;
    vector<double> Vy;
    vector<double> Ax;
    vector<double> Ay;
    double m;//mass
    double q;//charges
};
double Dis(double x1, double y1, double x2, double y2);
int main()
{
    default_random_engine e;
    normal_distribution<double> dis(0,1);
    static int steps = 1000;
    vector<Particle> ptls(2);
    for(int j = 0; j < 2; j++)
    {
        ptls[j].x.resize(steps);
        ptls[j].y.resize(steps);
        ptls[j].Vx.resize(steps);
        ptls[j].Vy.resize(steps);
        ptls[j].Ax.resize(steps);
        ptls[j].Ay.resize(steps);
    }
    //Assign all the constants involved
    double E = 1;
    double B = 1;
    double k = 1;
    double dt = 0.1;
    double g = 9.8*0.1;
    double d = dt*dt/2;
    double Fac = 1;
    double RanF;
    ptls[0].m = 1;
    ptls[0].q = 1;
    ptls[1].q = 1;
    ptls[1].m = 1;
    //Assign the quantities for the two points
    ptls[0].x[0] = 1;
    ptls[0].y[0] = 1;
    ptls[0].Vx[0] = 1;
    ptls[0].Vy[0] = 1;
    ptls[1].x[0] = 2;
    ptls[1].y[0] = 2;
    ptls[1].Vx[0] = 3;
    ptls[1].Vy[0] = 1;
    //f = mg + Eq + qBv + kq1q2/rr
    RanF = Fac*dis(e);
    ptls[0].Ax[0] = (RanF+ptls[0].q*ptls[0].Vy[0]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[0],ptls[0].y[0],ptls[1].x[0],ptls[1].y[0]),3))*(ptls[1].x[0]-ptls[0].x[0]))/ptls[0].m;
    RanF = Fac*dis(e);
    ptls[0].Ay[0] = (RanF-ptls[0].m*g + E*ptls[0].q - ptls[0].q*ptls[0].Vx[0]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[0],ptls[0].y[0],ptls[1].x[0],ptls[1].y[0]),3))*(ptls[1].y[0]-ptls[0].y[0]))/ptls[0].m;
    RanF = Fac*dis(e);
    ptls[1].Ax[0] = (RanF+ptls[1].q*ptls[1].Vy[0]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[0],ptls[0].y[0],ptls[1].x[0],ptls[1].y[0]),3))*(ptls[0].x[0]-ptls[1].x[0]))/ptls[1].m;
    RanF = Fac*dis(e);
    ptls[1].Ay[0] = (RanF-ptls[1].m*g + E*ptls[1].q - ptls[1].q*ptls[1].Vx[0]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[0],ptls[0].y[0],ptls[1].x[0],ptls[1].y[0]),3))*(ptls[0].y[0]-ptls[1].y[0]))/ptls[1].m;

    ptls[0].x[1] = ptls[0].x[0] + dt*ptls[0].Vx[0] + d*ptls[0].Ax[0];
    ptls[0].y[1] = ptls[0].y[0] + dt*ptls[0].Vy[0] + d*ptls[0].Ay[0];
    ptls[1].x[1] = ptls[1].x[0] + dt*ptls[1].Vx[0] + d*ptls[1].Ax[0];
    ptls[1].y[1] = ptls[1].y[0] + dt*ptls[1].Vy[0] + d*ptls[1].Ay[0];
    ptls[0].Vx[1] = ptls[0].Vx[0] + dt*ptls[0].Ax[0] + d * B*ptls[0].q*ptls[0].Ax[0]/ptls[0].m;
    ptls[0].Vy[1] = ptls[0].Vy[0] + dt*ptls[0].Ay[0] + d * B*ptls[0].q*ptls[0].Ay[0]/ptls[0].m;
    ptls[1].Vx[1] = ptls[1].Vx[0] + dt*ptls[1].Ax[0] + d * B*ptls[1].q*ptls[1].Ax[0]/ptls[1].m;
    ptls[1].Vy[1] = ptls[1].Vy[0] + dt*ptls[1].Ay[0] + d * B*ptls[1].q*ptls[1].Ay[0]/ptls[1].m;

    RanF = Fac*dis(e);
    ptls[0].Ax[1] = (RanF+ptls[0].q*ptls[0].Vy[1]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[1],ptls[0].y[1],ptls[1].x[1],ptls[1].y[1]),3))*(ptls[1].x[1]-ptls[0].x[1]))/ptls[0].m;
    RanF = Fac*dis(e);
    ptls[0].Ay[1] = (RanF-ptls[0].m*g + E*ptls[0].q - ptls[0].q*ptls[0].Vx[1]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[1],ptls[0].y[1],ptls[1].x[1],ptls[1].y[1]),3))*(ptls[1].y[1]-ptls[0].y[1]))/ptls[0].m;
    RanF = Fac*dis(e);
    ptls[1].Ax[1] = (RanF+ptls[1].q*ptls[1].Vy[1]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[1],ptls[0].y[1],ptls[1].x[1],ptls[1].y[1]),3))*(ptls[0].x[1]-ptls[1].x[1]))/ptls[1].m;
    RanF = Fac*dis(e);
    ptls[1].Ay[1] = (RanF-ptls[1].m*g + E*ptls[1].q - ptls[1].q*ptls[1].Vx[1]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[1],ptls[0].y[1],ptls[1].x[1],ptls[1].y[1]),3))*(ptls[0].y[1]-ptls[1].y[1]))/ptls[1].m;

    //Calculate other position and velocity
    double d2 = 2*dt;
    double d3 = dt/3;
    for(int i = 0; i < steps-2; i++)
    {
        //Predict the next position and velocity
        ptls[0].x[i+2] = ptls[0].x[i] + d2*ptls[0].Vx[i+1];
        ptls[0].y[i+2] = ptls[0].y[i] + d2*ptls[0].Vy[i+1];
        ptls[1].x[i+2] = ptls[1].x[i] + d2*ptls[1].Vx[i+1];
        ptls[1].y[i+2] = ptls[1].y[i] + d2*ptls[1].Vy[i+1];
        ptls[0].Vx[i+2] = ptls[0].Vx[i] + d2*ptls[0].Ax[i+1];
        ptls[0].Vy[i+2] = ptls[0].Vy[i] + d2*ptls[0].Ay[i+1];
        ptls[1].Vx[i+2] = ptls[1].Vx[i] + d2*ptls[1].Ax[i+1];
        ptls[1].Vy[i+2] = ptls[1].Vy[i] + d2*ptls[1].Ay[i+1];
        RanF = Fac*dis(e);
        ptls[0].Ax[i+2] = (RanF+ptls[0].q*ptls[0].Vy[i+2]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[i+2],ptls[0].y[i+2],ptls[1].x[i+2],ptls[1].y[i+2]),3))*(ptls[1].x[i+2]-ptls[0].x[i+2]))/ptls[0].m;
        RanF = Fac*dis(e);
        ptls[0].Ay[i+2] = (RanF-ptls[0].m*g + E*ptls[0].q - ptls[0].q*ptls[0].Vx[i+2]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[i+2],ptls[0].y[i+2],ptls[1].x[i+2],ptls[1].y[i+2]),3))*(ptls[1].y[i+2]-ptls[0].y[i+2]))/ptls[0].m;
        RanF = Fac*dis(e);
        ptls[1].Ax[i+2] = (RanF+ptls[1].q*ptls[1].Vy[i+2]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[i+2],ptls[0].y[i+2],ptls[1].x[i+2],ptls[1].y[i+2]),3))*(ptls[0].x[i+2]-ptls[1].x[i+2]))/ptls[1].m;
        RanF = Fac*dis(e);
        ptls[1].Ay[i+2] = (RanF-ptls[1].m*g + E*ptls[1].q - ptls[1].q*ptls[1].Vx[i+2]*B + k*ptls[0].q*ptls[1].q/(pow(Dis(ptls[0].x[i+2],ptls[0].y[i+2],ptls[1].x[i+2],ptls[1].y[i+2]),3))*(ptls[0].y[i+2]-ptls[1].y[i+2]))/ptls[1].m;
        //Correct the new position and velocity
        ptls[0].x[i+2] = ptls[0].x[i] + d3*(ptls[0].Vx[i+2]+4*ptls[0].Vy[i+1]+ ptls[0].Vx[i]);
        ptls[0].y[i+2] = ptls[0].y[i] + d3*(ptls[0].Vy[i+2]+4*ptls[0].Vy[i+1]+ ptls[0].Vy[i]);
        ptls[1].x[i+2] = ptls[1].x[i] + d3*(ptls[1].Vx[i+2]+4*ptls[1].Vy[i+1]+ ptls[1].Vx[i]);
        ptls[1].y[i+2] = ptls[1].y[i] + d3*(ptls[1].Vy[i+2]+4*ptls[1].Vy[i+1]+ ptls[1].Vy[i]);
        ptls[0].Vx[i+2] = ptls[0].Vx[i] + d3*(ptls[0].Ax[i+2]+ 4*ptls[0].Ax[i+1]+ptls[0].Ax[i]);
        ptls[0].Vy[i+2] = ptls[0].Vy[i] + d3*(ptls[0].Ay[i+2]+ 4*ptls[0].Ay[i+1]+ptls[0].Ay[i]);
        ptls[1].Vx[i+2] = ptls[1].Vx[i] + d3*(ptls[1].Ax[i+2]+ 4*ptls[1].Ax[i+1]+ptls[1].Ax[i]);
        ptls[1].Vy[i+2] = ptls[1].Vy[i] + d3*(ptls[1].Ay[i+2]+ 4*ptls[1].Ay[i+1]+ptls[1].Ay[i]);

    }

    ofstream outfile;
    outfile.open("coor.txt",ios::app);
    for(int i = 0; i <steps; i++)
    {
        //cout << i << endl;
        //cout <<ptls[0].x[i]<<'\t'<<ptls[0].y[i]<<'\t'<<endl;
        //cout <<ptls[1].x[i]<<'\t'<<ptls[1].y[i]<<'\t'<<endl;
        outfile << ptls[0].x[i]<<'\t'<<ptls[0].y[i]<<'\t'<< ptls[1].x[i]<<'\t'<<ptls[1].y[i]<<'\t'<<endl;

        //outfile << 2 << endl;
        //outfile << "txt" << endl;
        //outfile <<1<<'\t'<<ptls[0].x[i]<<'\t'<<ptls[0].y[i]<<'\t'<<0.0<<endl;
        //outfile <<2<<'\t'<<ptls[1].x[i]<<'\t'<<ptls[1].y[i]<<'\t'<<0.0<<endl;
    }
    return 0;
}

double Dis(double x1, double y1, double x2, double y2)
{
    double D = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    return D;
}
