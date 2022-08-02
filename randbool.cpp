/*  This function generates a random boolean.
    ---------------------------------------------------------------------------
    ALGORITHM:
    ---> Generate a random integer using the rand() of the cstdlib library
    ---> Divide the number by 2.
    ---> IF (reminder is 0):
        ---> return true
    ---> ELSE
        ---> return false
*/

#include<iostream>
#include "class_definitions.h"
bool rand_bool()
{
    int decider;
    decider = rand() % 2;   //This generates random numbers. We divide those numbers by 2. If the number is odd, return false. else return true

    if(decider == 0)
    return true;

    else
    return false;
}