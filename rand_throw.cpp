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
#include<random>
#include<chrono>
int rand_throw(int x)
{
    using namespace std::chrono;
    int dice1;
    int dice2;

    //Initialise the seed value using the system clock from the chrono header.
    unsigned seed = system_clock::now().time_since_epoch().count();

    //We are using the merienne twister mt19937 engine 
    std::mt19937 generator (seed);

    //first dice
    dice1 = (generator()%6) + 1;

    //second dice
    dice2 = (generator()%6) + 1;

    //We are goung ton generate a random number between 1 and 6
    return dice1 + dice2; 
}