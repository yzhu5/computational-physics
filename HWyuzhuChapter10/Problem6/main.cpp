#include <iostream>

using namespace std;

class Move
{
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0);   // sets x, y to a, b
        void showmove() const;                   // shows current x, y values
        Move add(const Move & m) const;
        // this function adds x of m to x of invoking object to get new x,
        // adds y of m to y of invoking object to get new y, creates a new
        // move object initialized to new x, y values and returns it
        void reset(double a = 0, double b = 0);  // resets x,y to a, b
        };


Move::Move(double a, double b)
{
    x = a;
    y = b;
}
void Move::showmove() const
{
    cout << "( " << x << " , " << y << " )" << endl;
}

Move Move::add(const Move &m) const
{
    return (Move(x+m.x,y+m.y));
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}


int main()
{
    Move m1;
    m1.showmove();
    m1.reset(88,88);
    m1.showmove();
    Move m2 = Move(66,66);
    Move m3 = m2.add(m1);
    m3.showmove();
    return 0;
}
