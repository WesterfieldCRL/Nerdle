#include <iostream>
#include <sstream>
#include <time.h>
#include "equationManip.h"

using namespace std;

int main()
{
    srand(time(0));
    stringstream ss;
    generateEquation(ss);
    cout << ss.str() << endl;

    return 0;
}