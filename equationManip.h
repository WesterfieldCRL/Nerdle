//Author: Wesley Anastasi
//Assignment Title: Group Project
//Assignment Description: Nerdle
//Due Date: idk lol
//Date Created: 4/14/2022
//Date Last Modified: 4/14/2022

#ifndef EQUATIONMANIP_H_INCLUDED
#define EQUATIONMANIP_H_INCLUDED

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;


/*
 * description: clears the string stream, and
                generates a random equation of 8 characters that is valid
 * return: void
 * precondition: a stringstream exists, and rand has been seeded
 * postcondition: the stringstream has been modified with an equation
 *
*/

void generateEquation(stringstream&);

/*
 * description: returns true if the equation is valid, returns 
                false if invalid equation
 * return: boolean
 * precondition: a stringstream exists
 * postcondition: the stringstream is unmodified
 *
*/

bool isValidEquation(const stringstream&);

/*
 * description: compares the master equation to the user equation and
                modifies the array to correspond to the result
                a 0 means the character is not present at all
                int the master array. A 1 means it is present but in the wrong place,
                a 2 means that the character in the user array is an exact match for the
                character in the master array
 * return: void
 * precondition: two stringstream's exist, and an array of size 8 exists
 * postcondition: only the array has been changed
 *
*/

void compareEquations(const stringstream& master, const stringstream& user, int[]);


#endif // EQUATION_H_INCLUDED