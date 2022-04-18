#include <iostream>
#include <sstream>
#include <time.h>
#include "Line.h"
//#include "drawObject.h"

using namespace std;

int main()
{

    Point p1(1,0);
    Point p2(1,2);
    Point p3(3,-1);
    Point p4(3,0);
    Line line1(p1,p2);
    Line line2(p3,p4);


    return 0;
}