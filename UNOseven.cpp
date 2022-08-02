/*  In this function, we declare a function which checks if a person completed his tenure of 
    five rounds after entering UNO by throwing a 7 and not paying 5000.

    This function must be called after updating all throw related variables, arrays
    ----------------------------------------------------------------------------------------
    ALGORITHM:
    ---> IF (current player is not eligible for rent)
        ---> IF ((current player's blocks covered - last time at UNO) > 180)
            ---> current player is then eligible for rent
*/
#include "class_definitions.h"
#include<iostream>
using namespace std;
void UNO_seven(player *current_player)
{
    if(!(current_player->rent_elig))
    {
        if((current_player->blocks_covered - current_player->last_time_at_uno) >= 180)
        {
            current_player->rent_elig = true;
        }
    }
}