//Author: Wesley Anastasi
//Assignment Title: Nerdle
//Assignment Description: create Nerdle w/ SDL plotter
//Due Date: 5/5/2022
//Date Created: 4/14/2022
//Date Last Modified: 4/15/2022

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
    int numOfOpers = 0;
    int nums[3];
    int numSum;
    int finalNum;
    char opers[3];
    int count = 0;
    bool isValid = true;

    //store equation from stringstream in variables
    master >> nums[0];
    master >> opers[0];
    master >> nums[1];
    master >> opers[1];
    //checks if three variables or two
    if (opers[1] != '=')
    {
        numOfOpers = 1;
        master >> nums[2];
        master >> opers[2];
    }
    master >> finalNum;

    //same logic as in generate equation, but modified slightly
    //instead of the switch depending on an integer it checks the character
    //then instead of dealing with the stringstream it just calculates the answer to the eqaution
    numSum = nums[0];
    for (int i = 0; i <= numOfOpers; i++)
    {
        switch (opers[i])
        {
            case '+':
                numSum += nums[i+1];
                break;
            case '-':
                numSum -= nums[i+1];
                break;
            case '*':
                numSum *= nums[i+1];
                if (i == 1)
                {
                    if (opers[0] == '+')
                    {
                        numSum = nums[0] + (static_cast<double>(nums[1]) * nums[2]);
                    }
                    else if (opers[0] == '-')
                    {
                        numSum = nums[0] - (static_cast<double>(nums[1]) * nums[2]);
                    }
                }
                break;
            case '/':
                numSum /= nums[i+1];
                if (i == 1)
                {
                    if (opers[0] == '+')
                    {
                        numSum = nums[0] + (static_cast<double>(nums[1]) / nums[2]);
                    }
                    else if (opers[0] == '-')
                    {
                        numSum = nums[0] - (static_cast<double>(nums[1]) / nums[2]);
                    }
                }
                break;
            default:
                //main difference is here, if user enters something stupid, the default case will activate
                isValid = false;
                break;
        }
    }

    //in the same vein as the default case, if stringstream goes into an error state,
    //isValid will be false
    if (master.fail())
    {
        isValid = false;
    }

    //checks if the calculated sum is equal to the inputted sum.
    //Doesnt need to check for more specific problems like in generateEquation, because the user 
    //may want to do certain things that wont be in the actual answer but are still valid equations.
    //For example: 01+2+1=4, whereas leading zeros will never be in a generated equation
    if (numSum != finalNum)
    {
        isValid = false;
    }

    return isValid;
}

void compareEquations(const stringstream& master, const stringstream& user, int results[])
{
    int resultSize = 8;
    char uniqueChars[resultSize];
    bool isUnique;
    int uniqueCharsCount = 0;
    string stringMaster, stringUser;

    //gets the stringstreams as strings, since we are just comparing the characters
    stringMaster = master.str();
    stringUser = user.str();

    //loops through stringMaster and generates a list of all unique characters
    for (int i = 0; i < resultSize; i++)
    {
        isUnique = true;
        for (int a = 0; a < uniqueCharsCount; a++)
        {
            if (uniqueChars[a] == stringMaster[i])
            {
                isUnique = false;
                a = uniqueCharsCount;
            }
        }
        if (isUnique)
        {
            uniqueChars[uniqueCharsCount] = stringMaster[i];
            uniqueCharsCount++;
        }
    }
    
    //loops through the user string and compares it to the master string.
    //if the characters are an exact match, the result array is assigned a 2
    //if they are not an exact match, the program then runs through the unique character list
    //to see if the charatcer is a match for any of those. If so, the result array is assigned a 1.
    //if the character is not present in the master string at all, the result array is assigned a 0.
    for (int i = 0; i < resultSize; i++)
    {
        if (stringUser[i] == stringMaster[i])
        {
            results[i] = 2;
        }
        else
        {
            isUnique = false;
            for (int a = 0; a < uniqueCharsCount; a++)
            {
                if (uniqueChars[a] == stringUser[i])
                {
                    results[i] = 1;
                    isUnique = true;
                    a = uniqueCharsCount;
                }
            }
            if (!isUnique)
            {
                results[i] = 0;
            }
        }
    }
}