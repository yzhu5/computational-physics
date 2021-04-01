#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

// Find the minimum of f(x,y,z) = y*sin(4*Pi*x) + 2*x*cos(8*Pi*y) in the region of x,y in [-1,1]
// use Tournament Selection: Every time we compare 2 pairs of x and y; choose the smaller one(value of f(x,y,z)) as parents. From this method, we can always find the better chromosome, until we find the minimum value of f(x,y,z)
// region [-1,1], take this region into 2*10^6 parts;
//1048576 = 2^(20) < 2*10^6 < 2^21 < 2097152
//compare this method with random points method, we can find this algorithm is much faster

//loops      x                 y                   min
//random points method
//1000   0.887326          0.891293              -2.50855
//100000  -0.8905           -0.999817            -2.76189
//genetic algorithm
//100     -0.886719            -1                -2.76261
//1000    -0.886719            -1                -2.76261


int chrsize = 100;
static int genesize = 21;
static int dgenesize = genesize*2;
struct Chromosome
{
    int gene[42];
    double x;
    double y;
    double cost;
    double p;

};
vector<Chromosome> chr(chrsize);
vector<Chromosome> tempchr(chrsize);
Chromosome tempch;

void encode()
{
    for(int i = 0; i < chrsize; i++)
    {
        double tempX = (chr[i].x + 1.0)*0.5;
        double tempY = (chr[i].y + 1.0)*0.5;
        double d = 0.5;
        for(int j = 0; j < genesize; j++)
        {
            chr[i].gene[j] = 0;
            if(tempX > d)
            {
                chr[i].gene[j] = 1;
                tempX -= d;
            }
            d *= 0.5;
        }
        d = 0.5;
        for(int j = genesize; j < dgenesize; j++)
        {
            chr[i].gene[j] = 0;
            if(tempY > d)
            {
                chr[i].gene[j] = 1;
                tempY -= d;
            }
            d *= 0.5;
        }
    }
}

void decode()
{
    for(int i = 0; i < chrsize; i++)
    {
        double Xsum = 0,Ysum = 0;
        double d = 0.5;
        for(int j = 0; j < genesize; j++)
        {
            Xsum += chr[i].gene[j]*d;
            d *=0.5;
        }
        d = 0.5;
        for(int j = genesize; j < dgenesize; j++)
        {
            Ysum += chr[i].gene[j]*d;
            d *= 0.5;
        }
        chr[i].x = 2.0*Xsum - 1.0;
        chr[i].y = 2.0*Ysum - 1.0;
    }
}

void cost()
{
    for(int i = 0; i < chrsize; i++)
    {
        //cout << chr[i].x << chr[i].y << endl;
        double f = chr[i].y*sin(4*3.1415926*chr[i].x) + 2*chr[i].x*cos(8*3.1415926*chr[i].y);
        chr[i].cost = f;
        //cout << chr[40].cost << endl;
    }
}

void sortChr() // from low to high base on f(x,y,z)
{
    for(int i = 0; i < chrsize; i++)
    {
        for(int j = i+1; j < chrsize; j++)
        {
            if(chr[i].cost > chr[j].cost)
            {
                //cout << "in1" << endl;
                tempch = chr[i];
                //cout << "in2" << endl;
                chr[i] = chr[j];
                chr[j] = tempch;
            }
        }
    }

}

void shuffle()
{
    for(int i = 0; i < chrsize; i++)
    {
        int j = rand()%chrsize;
        if(i != j)
        {
            //Chromosome tempch;
            tempch = chr[i];
            chr[i] = chr[j];
            chr[j] = tempch;
        }
    }
}

void select()//Tournament Selection
{

    sortChr();
    //cout << "in1" << endl;
    //cout << "in2" << endl;
    tempchr[0] = chr[0]; // keep the best chromosome
    shuffle();
    for(int i = 1; i < chrsize;i++)
    {
        int r1 = rand()%chrsize;
        int r2 = rand()%chrsize;
        //cout << r1 << ' ' << r2 << endl;
        if(chr[r1].cost <= chr[r2].cost)
        {
            tempchr[i] = chr[r1];
        }
        else{
            tempchr[i] = chr[r2];
        }
    }
    for(int i = 0; i < chrsize; i++)
    {
        chr[i] = tempchr[i];
    }
}

void Crossover()
{
    for(int i = 0; i < chrsize-1; i+=2)
    {
        double r1 = double(rand())/double(RAND_MAX);
        if(r1 < 0.8)
        {
            int r2 = rand()%dgenesize;
            for(int j = 0; j < r2; j++)
            {
                int aa;
                aa = chr[i].gene[j];
                chr[i].gene[j] = chr[i+1].gene[j];
                chr[i+1].gene[j] = aa;
            }
        }
    }
}

void mutate()
{
    sortChr();
    for(int i = 1; i < chrsize; i++)
    {
        double r1 = double(rand())/double(RAND_MAX);
        if(r1 < 0.1)
        {
            int r2 = rand()%dgenesize;
            if(chr[i].gene[r2] == 1)
            {
                chr[i].gene[r2] = 0;
             }else
             {
                 chr[i].gene[r2] = 1;
             }
        }
    }
}






int main()
{

    //Initialize
    for(int i = 0; i < chrsize; i++)
    {
        chr[i].x = 2*(double(rand())/double(RAND_MAX)) - 1.0;
        chr[i].y = 2*(double(rand())/double(RAND_MAX)) - 1.0;
        //cout << chr[i].x << " " << chr[i].y << endl;
    }
        encode();
        cost();

   for(int n = 0; n < 1000; n++)
    {
        cout << n << endl;
        //cout << "test8" << endl;
        select();
        //cout << "test1" << endl;
        Crossover();
        //cout << "test2" << endl;
        decode();
        //cout << "test3" << endl;
        cost();
        //cout << "test4" << endl;
        mutate();
        //cout << "test5" << endl;
        decode();
        //cout << "test6" << endl;
        cost();
        //cout << "test7" << endl;
    }

    sortChr();
    cout<< "Genetic algorithm: " << chr[0].x << ' ' << chr[0].y << ' ' << chr[0].cost << endl;


   //Random points method
    double m = 0,rx,ry;
    for(int i = 0; i < 100000; i++)
    {
        double r1 = 2.0*(double(rand())/double(RAND_MAX)) - 1.0;
        double r2 = 2.0*(double(rand())/double(RAND_MAX)) - 1.0;
        double g = r2*sin(4*3.1415926*r1) + 2*r1*cos(8*3.1415926*r2);
        if(g < m)
        {
            m = g;
            rx = r1;
            ry = r2;
        }
    }
    cout << "Random point method: " << rx << " " << ry << " " << m << endl;



    return 0;
}
