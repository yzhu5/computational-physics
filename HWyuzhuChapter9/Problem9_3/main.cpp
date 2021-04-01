#include <iostream>
#include <cstring>

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

char buf[1024];

int main()
{
    chaff* pChaff = new(buf) chaff[2];
    strcpy(pChaff[0].dross, "aaa");
    pChaff[0].slag = 2;

    strcpy(pChaff[1].dross, "bbb");
    pChaff[1].slag = 2;

    for(unsigned i = 0; i < 2; i++)
    {
        cout << pChaff[i].dross << '\t' << pChaff[i].slag << endl;
    }
    return 0;
}
