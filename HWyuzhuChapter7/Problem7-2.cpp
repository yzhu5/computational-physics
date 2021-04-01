#include <iostream>

using namespace std;

double InputGolfScores(double arr[], unsigned ScoreSize)
{
    double temp;
    unsigned ScoreCounter = 0;
    while(ScoreCounter < ScoreSize && cin >> temp && temp != -1)
    {
        arr[ScoreCounter++] = temp;
    }
    return (*arr);
}

void DisplyScores(double arr[],unsigned ScoreSize)
{
    for(unsigned i = 0; i < ScoreSize; i++)
    {
        cout << arr[i] << ' ' ;
    }
}
double CalAverage(double arr[], unsigned ScoreSize)
{
    double sum = 0;
    for(unsigned i = 0; i < ScoreSize; i++)
    {
        sum += arr[i];
    }
    return(sum/ScoreSize);
}


int main()
{
    const unsigned ScoreSize = 10;
    double GolfScores[ScoreSize];
    cout << "Please enter " << ScoreSize  << " golf scores(-1 to exit):";
    unsigned Scores = InputGolfScores(GolfScores, ScoreSize);
    cout << "Here are all scores: ";
    DisplyScores(GolfScores, ScoreSize);
    cout << endl;
    cout << "Here is the mean of scores: " << CalAverage(GolfScores, ScoreSize) << endl;
    return 0;
}
