#include <iostream>
#include <sstream>
#include <time.h>
#include "equationManip.h"

using namespace std;

int main()
{
    srand(time(0));
    string input;
    int results[8];
    stringstream user;
    stringstream master;

    for (int i = 0; i < 8; i++)
    {
        results[i] = -1;
    }

    generateEquation(master);
    cout << master.str() << endl;

    cout << "please input a equation: ";
    cin >> input;
    user << input;

    
    cout << user.str() << endl;
    

    compareEquations(master, user, results);
    for (int i = 0; i < 8; i++)
    {
        cout << results[i];
    }
    cout << endl;

    return 0;
}