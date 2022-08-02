/*   In this function, we will generate random throws with two dice.
    -----------------------------------------------------------------------------------
    PARAMETERS:
    ---> NONE
    ------------------------------------------------------------------------------------
    RETURN VALUE:
    ---> NONE
    -------------------------------------------------------------------------------------
    ALGORITHM:
    ---> Create two integer varibales;
    ---> Assign a random integer between 1 and 6 to each variable created
    ---> Return the sum of both variables
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "class_definitions.h"
int rand_throw()
{
    srand(time(0));
    int dice1;
    int dice2;
    dice1 = (1 + (rand() % 6));
    dice2 = (1 + (rand() % 6));
    return dice1 + dice2;
}