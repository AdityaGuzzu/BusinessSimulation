/* We will use a function in this file to generate a random number between 0 and a given
    upper limit. This will be used to iterate over arrays and pick up elements at random
    to sell and construct houses
*/

#include "class_definitions.h"
#include<chrono>
#include<random>
int randnum(int upp_lim)
{
    using namespace std::chrono;

    //Initialise the seed value
    unsigned int seed = system_clock::now().time_since_epoch().count();

    //We are using Merienne Twister engine mt19937 engine
    std::mt19937 generator (seed);

    //If the upp_lim is 0, we will return 0 as dividing by 0 causes error.
    if(upp_lim == 0)
    {
        return 0;
    }

    //We wont be adding 1 because we use the random number to access array elements which range from [0,upp_lim)
    else
    {
        return generator() % upp_lim;    
    }    
}
