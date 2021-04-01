#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void DisplayBox(box box1)
{
    cout << "Maker: " << box1.maker << endl;
    cout << "Height: " << box1.height << endl;
    cout << "width: " << box1.width << endl;
    cout << "length: " << box1.length << endl;
    cout << " volume: " << box1.volume << endl;
}

float CalBoxVolume(box* pbox1)
{
    pbox1->volume = pbox1->height*pbox1->width*pbox1->length;
    return (pbox1->volume);
}


int main()
{
    box box1 = {"large", 1, 2, 3};
    box1.volume = CalBoxVolume(&box1);
    DisplayBox(box1);

    return 0;
}
