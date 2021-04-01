#include <iostream>
using namespace std;


long double Probability(unsigned TotalNum, unsigned PicksNum)
{
    long double probability = 1.0;
    while(PicksNum>0)
    {
        probability *=1.0*PicksNum/TotalNum;
        --TotalNum;
        --PicksNum;
    }
    return probability;
}
int main()
{
    long double probability = Probability(47,5)*Probability(27,1);
    cout << "Your probability of winning this kind of lottery is: " << probability << endl;
    return 0;
}
