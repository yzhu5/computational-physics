#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

// H = -J*Sum(Si*Sj)
//p = exp(-DeltaH/kb*T), DeltaH is the energy difference cased by the reversal of spin
//if p >= w,accept new configuration, w is random number in the region [0,1]
//kb*T = 1, change T to find critical temperature


int main()
{
  const int GridSize = 32;
  const int tMax = 10000;
  vector<vector<double>> grid(GridSize);
  for(int i = 0; i < GridSize; i++)
  {
      grid[i].resize(GridSize);
  }

 //Initialization
        for(int i = 0; i < GridSize; i++)
        {
          for(int j = 0; j < GridSize; j++)
            {
             grid[i][j] = 1;
        }
        }

  for(double kbT = 0; kbT < 5;kbT+=0.1)
  {

        double pE = 0;
        double E;
      for(int t = 0; t < tMax; t++)
      {
          //pick up lattice randomly
          int Idex = int (rand())%GridSize;
          int Jdex = int (rand())%GridSize;
          grid[Idex][Jdex] = -1*grid[Idex][Jdex];
          int l,r,u, d;

          //Calculate energy
                E = 0;
                /*
                  d = Idex - 1;
                  u = Idex + 1;
                  r = Jdex + 1;
                  l = Jdex - 1;
                  //periodic boundary condition
                  if(Jdex == 0)
                  {
                      l = GridSize-1;
                  }
                  if(Jdex == GridSize -1)
                  {
                      r = 0;
                  }
                  if(Idex == 0)
                  {
                      d = GridSize -1;
                  }
                  if(Idex == GridSize -1)
                  {
                     u = 0;
                  }
                  double deltaE = -2*grid[Idex][Jdex]*(grid[Idex][l]+grid[Idex][r]+grid[d][Jdex]+grid[u][Jdex]);
*/
          for(int i = 0; i< GridSize; i++)
          {
              for(int j = 0; j < GridSize; j++)
              {

                  d = i + 1;
                  u = i - 1;
                  r = j + 1;
                  l = j - 1;
                  //periodic boundary condition

                  if(j == 0)
                  {
                      l = GridSize-1;
                  }
                  if(j == GridSize -1)
                  {
                      r = 0;
                  }
                  if(i == 0)
                  {
                      u = GridSize -1;
                  }
                  if(i == GridSize -1)
                  {
                     d = 0;
                  }
                  double lE = grid[i][j]*grid[i][l];
                  double rE = grid[i][j]*grid[i][r];
                  double uE = grid[i][j]*grid[u][j];
                  double dE = grid[i][j]*grid[d][j];
                  E += 0.5*(lE + rE + uE + dE);

                  //cout << E << endl;
              }
          }

          //compare
          double deltaE = E - pE;

            if(exp(-(deltaE*kbT))>=1)
          {
              pE = E;
          }else
          {
              double ran = double(rand())/RAND_MAX;
              if(exp(-(deltaE*kbT))>=ran)
              {
                  pE = E;
              }else{
                grid[Idex][Jdex] = -grid[Idex][Jdex];
              }
          }
      }

      cout << kbT << ' ' << E << endl;
  }

  for(int i = 0; i < GridSize; i++)
  {
      for(int j = 0; j < GridSize; j++)
      {
          cout << grid[i][j] << "  ";
      }
      cout << endl;
  }
  return 0;
}
