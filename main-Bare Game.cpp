#include <iostream>
#include "equationManip.h"
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

int main()
{
    stringstream equation, ss;
    string input;
    bool valid=false;
    bool correct=false;
    int placement[8];
    int win[8]={2,2,2,2,2,2,2,2};
    int count = 0;
    srand(time(0));


    generateEquation(equation);


    do{
        while(!valid){
        ss.str("");
        ss.clear();
        cin >> input;
        ss << input;
        valid=isValidEquation(ss);
        }

        compareEquations(equation,ss,placement);
        for(int i=0; i<8; i++){
            cout<< placement[i]<<" ";
        }
        cout<<endl;
        for(int j=0; j<8; j++){
            if(win[j]!= placement[j]){
                correct=false;
            }
            else{
                correct=true;
            }
        }
        valid=false;
        count++;

    }while((!correct) && (count<6));
    if((!correct)&&(count==6)){
        cout<<"out of turns"<<endl;
    }
    else{
        cout<<"You got it in "<<count
        <<" turns."<<endl;
    }




}
