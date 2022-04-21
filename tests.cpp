#include <iostream>
//#include "arrayDraw.h"

using namespace std;

int main()
{

    int test[10][10];
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            test[x][y] = x+y;
        }
    }

    drawRectangleArray(0,0,5,5,test,1);

    return 0;
}