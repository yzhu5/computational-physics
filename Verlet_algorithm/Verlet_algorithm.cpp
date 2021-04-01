#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <fstream>
using namespace std;

//potential energy equation: V(rij) = factor1*e*e/(4*pi*factor2*rij) + factor3*V0*pow(e,-rij/r0);
//factor1 = -1 and factor3 = 1 if the particles are of opposite charges; otherwise, factor1 = 1and factor3 = 0
//derive Force by this equation: F = -dU/dr;
//r = pow((x1-x)(x1-x)+(y1-y)(y1-y)+(z1-z)(z1-z),0.5);
//Fx =  -factor1*e*e/(4*pi)*pow(r,-1.5)*(x1-x) - factor3*V0*pow(e,-rij/r0)/r0*pow(r,-0.5)(x1-x); the same for Fy and Fz
//Relationship between x, y, z and r:
//x=r*sinθ*cosφ y=r*sinθ*sinφ z=r*cosθ; r∈[0,+∞), φ∈[0, 2π], θ∈[0, π]
//Maxwell Distribution:f(v) = pow(m/2*pi*k*T, 1.5)*exp(-m*v*v/(2*k*T))

// This program didn't set the initial configuration as the equilibrium.
//Assign initial velocities from Maxwell distribution with Monte Carlo method.
//The Kinetic energy will increase and the potential energy will decrease as time goes on, the total energy is constant. Finally the Kinetic energy equal to total energy, and the potential energy is 0.
//For different energy, the Kinetic energy should equal to Total energy.


struct partical
{
    int sign;
    double x;
    double y;
    double z;
    double v;
    double vx;
    double vy;
    double vz;
    double Fx;
    double Fy;
    double Fz;
    double pFx;
    double pFy;
    double pFz;
    double KE;
    double TE;
};

int main()
{
    //constant
    const double V0 = 500;
    double factor1 = 0.1;
    double m = 1;//mass
    int gij,bij;
    const double e = 2.71828;
    const double q = 1;
    const double r0 = 1;
    const int Np = 3;
    const int Nn = 3;
    const int N = Np+Nn;
    const double kT = 1;
    const double Pi = 3.1415926;
    const double Deltat = 0.001;
    const int tMax = 300;
    vector<partical> pars(N);
    double r[N][N];
    for(int i = 0; i < N; i++)
    {
        pars[i].sign = 1;
        if(i>= Np)
        {
            pars[i].sign = -1;
        }
    }

    //set position
    pars[0].x = 20;pars[0].y = 20; pars[0].z = 20;
    pars[3].x = 20.5; pars[1].y = 20; pars[1].z = 20;
    pars[2].x = 20;pars[2].y = 20.5;pars[2].z = 20;
    pars[1].x = 20; pars[3].y = 20; pars[3].z = 20.5;
    pars[4].x = 19.5;pars[4].y = 20;pars[4].z = 20;
    pars[5].x = 20; pars[5].y = 19;pars[5].z = 20;

    //Initial velocity
    cout << "Initial velocity:" << endl;
    int conter = 0;
    while(conter < N)
    {
        double ranV = 100*((double)rand()/(RAND_MAX));
        double p = pow(m/(2*Pi*kT),1.5)*pow(e,(-m*ranV*ranV/(2*kT)));
        double juge = (double)rand()/(RAND_MAX);
        if(juge < p)
        {
            pars[conter].v = ranV;
            conter++;
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << pars[i].v << endl;
        double theta1 = Pi*((double)rand()/(RAND_MAX));
        double theta2 = 2*Pi*((double)rand()/(RAND_MAX));
        pars[i].vx = pars[i].v*sin(theta1)*cos(theta2);
        pars[i].vy = pars[i].v*sin(theta1)*sin(theta2);
        pars[i].vz = pars[i].v*cos(theta1);
    }

    for(int i = 0; i < N; i++)
    {
        pars[i].pFx = 0;
        pars[i].pFy = 0;
        pars[i].pFz = 0;
    }



    for(int t = 0; t < tMax; t++)
    {
        //cout << t << endl;
        //update positions
        for(int i = 0; i < N; i++)
        {
            pars[i].x = pars[i].x + Deltat * pars[i].vx + Deltat*Deltat*pars[i].Fx;
            pars[i].y = pars[i].y + Deltat * pars[i].vy + Deltat*Deltat*pars[i].Fy;
            pars[i].z = pars[i].z + Deltat * pars[i].vz + Deltat*Deltat*pars[i].Fz;
        }

        //update positions between 2 particles
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                r[i][j] = pow(pow((pars[i].x-pars[j].x),2) + pow((pars[i].y-pars[j].y),2) + pow((pars[i].z-pars[j].z),2),0.5);
                //r[j][i] = r[i][j];
                //cout << r[i][j] << endl;
            }
            pars[i].Fx = 0;
            pars[i].Fy = 0;
            pars[i].Fz = 0;
        }

        // update force and acceleration
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {

                if(i!=j)
                {
                    if(pars[i].sign*pars[j].sign < 0)
                    {
                        gij = -1;
                        bij = 1;
                    }else if(pars[i].sign*pars[j].sign > 0)
                    {
                        gij = 1;
                        bij = 0;
                    }
                    //get force based on position
                    pars[i].Fx += gij*q*q/(4*Pi)*pow(r[i][j],-3)*(pars[i].x-pars[j].x) + bij*V0*pow(e, -r[i][j]/r0)/(r0*r[i][j])*(pars[i].x-pars[j].x);
                    pars[i].Fy += gij*q*q/(4*Pi)*pow(r[i][j],-3)*(pars[i].y-pars[j].y) + bij*V0*pow(e, -r[i][j]/r0)/(r0*r[i][j])*(pars[i].y-pars[j].y);
                    pars[i].Fz += gij*q*q/(4*Pi)*pow(r[i][j],-3)*(pars[i].z-pars[j].z) + bij*V0*pow(e, -r[i][j]/r0)/(r0*r[i][j])*(pars[i].z-pars[j].z);
                    //cout << pars[i].Fx << ' ' << pars[i].Fy << ' ' << pars[i].Fy << endl;

                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            //calculate velocity
            pars[i].vx = pars[i].vx + Deltat *(pars[i].pFx + pars[i].Fx)/2;
            pars[i].vy = pars[i].vy + Deltat *(pars[i].pFy + pars[i].Fy)/2;
            pars[i].vz = pars[i].vz + Deltat *(pars[i].pFz + pars[i].Fz)/2;

            //update previous force and acceleration
            pars[i].pFx = pars[i].Fx;
            pars[i].pFy = pars[i].Fy;
            pars[i].pFz = pars[i].Fz;
        }


        ofstream outK,outP,outT,outPosition;
        if(t%2 == 0)
        {
        outPosition.open("position.xyz", ios::app);
        outPosition << N << endl;
        outPosition << "txt" << endl;
        for(int i = 0; i < N; i++)
        {
            if(pars[i].sign > 0)
            {
            outPosition << pars[i].sign << ' ' << pars[i].x << ' ' << pars[i].y << ' ' << pars[i].z << endl;
            }
            else if(pars[i].sign < 0)
            {
                outPosition << 2 << ' ' << pars[i].x << ' ' << pars[i].y << ' ' << pars[i].z << endl;
            }
        }
        }
        if(t != -1)
        {
            //Kinetic energy

            double KE = 0;
            double PE = 0;
            double TE = 0;
            for(int i = 0; i < N; i++)
            {
                pars[i].KE = 0.5*m*(pars[i].vx*pars[i].vx + pars[i].vy*pars[i].vy + pars[i].vz*pars[i].vz);
                KE += pars[i].KE;
            }
            //Potential energy
            for(int i = 0; i < N; i++)
            {
                for(int j = i+1; j < N; j++)
                {
                    if(pars[i].sign*pars[j].sign < 0)
                    {
                        gij = -1;
                        bij = 1;
                    }else if(pars[i].sign*pars[j].sign > 0)
                    {
                        gij = 1;
                        bij = 0;
                    }
                    PE += gij*q*q/(4*Pi*r[i][j]) + bij*V0*pow(e,(-r[i][j]/r0));
                }
            }
            TE = PE + KE;
         //cout << KE << ' ' << PE << endl;
         outK.open("Kinetic.txt",ios::app);
         outK << t << ' ' << KE << endl;
         outP.open("Potential.txt",ios::app);
         outP << t << ' ' << PE << endl;
         outT.open("Total.txt",ios::app);
         outT << t << ' ' << TE << endl;
        }
    }


return 0;
}
















