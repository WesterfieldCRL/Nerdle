//Author: Wesley Anastasi
//Assignment Title: Group Project
//Assignment Description: Nerdle
//Due Date: idk lol
//Date Created: 4/14/2022
//Date Last Modified: 4/14/2022

#include "equationManip.h"

void generateEquation(stringstream& master)
{
    int nums[3];
    char opers[2];
    double num4;
    int operNum;
    int numOfOpers;

    //determine if there will be 1 or two operators
    numOfOpers = rand()%2;

    //if three operators generate different numbers to have a greater chance of it being valid
    if (numOfOpers == 0)
    {
        nums[0] = rand()%1000;
        nums[1] = rand()%1000;
    }
    else
    {
        nums[0] = rand()%100;
        nums[1] = rand()%100;
        nums[2] = rand()%100;
    }

    //clear the string stream
    master.str("");
    master.clear();

    //input the first number to the string stream and set the resulting number to the first num
    master << nums[0];
    num4 = nums[0];

    //assign operators and calculate num4.
    //If numOfOpers is 1, an additional operator will be assigned along with a additional number
    //num4 is calculated in the loop so that the chance of being a correct equation is higher
    for (int i = 0; i <= numOfOpers; i++)
    {
        operNum = rand()%4;
        switch (operNum)
        {
            case 0:
                opers[i] = '+';
                master << '+';
                num4 += nums[i+1];
                break;
            case 1:
                opers[i] = '-';
                master << '-';
                num4 -= nums[i+1];
                break;
            case 2:
                opers[i] = '*';
                master << '*';
                num4 *= nums[i+1];
                //because of order of operations, if division or multiplication follows a + or -, num4 needs to be calculated differently
                if (i == 1)
                {
                    if (opers[0] == '+')
                    {
                        num4 = nums[0] + (static_cast<double>(nums[1]) * nums[2]);
                    }
                    else if (opers[0] == '-')
                    {
                        num4 = nums[0] - (static_cast<double>(nums[1]) * nums[2]);
                    }
                }
                break;
            case 3:
                opers[i] = '/';
                master << '/';
                num4 /= nums[i+1];
                //because of order of operations, if division or multiplication follows a + or -, num4 needs to be calculated differently
                if (i == 1)
                {
                    if (opers[0] == '+')
                    {
                        num4 = nums[0] + (static_cast<double>(nums[1]) / nums[2]);
                    }
                    else if (opers[0] == '-')
                    {
                        num4 = nums[0] - (static_cast<double>(nums[1]) / nums[2]);
                    }
                }
                break;
            default:
                cout << "something went wrong in generateEquation" << endl;
                break;
        }
        master << nums[i+1];
    }

    //finish assigning things to the stringstream
    master << '=';
    master << num4;

    //check if the equation is valid. If invalid, call generateEquation again.
    //this will continue calling generateEquation untill a valid equation is generated.
    //this also will work because the stringstream is cleared at the beginning of generateEquation

    //the if statement checks if num4 is a whole number, if the equation is 8 characters long, if num4 is negative,
    //and it checks if there are any lone zeros.
    //I got the criteria for this from the nerdle website.
    if (num4 != int(num4) || master.str().length() != 8 || num4 < 0 || nums[0] == 0 || nums[1] == 0 || nums[2] == 0)
    {
        generateEquation(master);
    }
}

bool isValidEquation(stringstream& master)
{
    int numOfOpers = 1;
    int nums[3];
    int num4;
    char opers[3];
    int count = 0;
    master >> nums[0];
    master >> opers[0];
    master >> nums[1];
    master >> opers[1];
    if (opers[1] != '=')
    {
        numOfOpers = 2;
        master >> nums[2];
        master >> opers[3];
    }
    
}