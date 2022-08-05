/*  This function generates a random boolean.
    ---------------------------------------------------------------------------
    ALGORITHM:
    ---> Generate a random integer using the merriene twister method of the random library
    ---> Divide the number by 2.
    ---> IF (reminder is 0):
        ---> return true
    ---> ELSE
        ---> return false
*/

#include<iostream>
#include<random>
#include<chrono>
bool rand_bool(int x)
{
    using namespace std::chrono;

    //Initialise the seed value using the system clock from the chrono header.
    unsigned seed = system_clock::now().time_since_epoch().count();

    //We are using the merienne twister mt19937 engine 
    std::mt19937 generator (seed);

    //if the generated number is even, return true. Else return false
    if((generator() % 2) == 0)
    return true;

    else
    return false;
}