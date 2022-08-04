/*  ALGORITHM:
    ---> generate a random number between 2 and 12
    ---> assign it to throw_ variable of current player
    ---> append throw_ to current player's throws vector
    ---> current player's position = ( (position + throw_) % 36 )
    ---> add throw_ to the blocks_covered variable
    ---> append ( (positions) /36 ) to rounds vector
*/
#include<iostream>
#include "class_definitions.h"
void after_throw(player *current_player)
{
    current_player->blocks_covered += current_player->throw_;
    current_player->position = (current_player->blocks_covered % 36);
    current_player->round = (current_player->blocks_covered / 36);
    current_player->rounds.push_back(current_player->round);
}    