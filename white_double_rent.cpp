/*  This file contains a function which deals with double rents of white tickets
    The function will only be called when a player buys or sells a white ticket
    ------------------------------------------------------------------------------
    PARAMETERS:
    1.) Pointer array of type block (of all the blocks)
    2.) A referance of the current player
    ------------------------------------------------------------------------------
    RETURN VALUE: NONE
    ------------------------------------------------------------------------------
    ALGORITHM:
        ---> IF current player owns block 3 and 7:
            ---> current rent of satellite = 1000
            ---> current rent of waterways = 2200
        ---> ELSE:
            --->IF current player owns block 3:
                ---> current rent of waterways = 1400
            --->IF current player owns block 7:
                ---> current rent of satellite = 500


        ---> IF current player owns block 33 and 22:
            ---> current rent of roadways = 1500
            ---> current rent of railways = 2500
        --->ELSE:
            ---> IF current player owns block 33:
                ---> current rent of railways = 1500
            ---> IF current player owns block 22:
                ---> current rent of roadways = 800


        ---> IF current player owns block 12 and block 31:
            ---> current rent of petroleum = 1000
            ---> current rent of airways = 2500
        ---> ELSE:
            ---> IF current player owns block 12:
                ---> current rent of airways = 1500
            ---> IF current player owns block 31:
                ---> current rent of petroleum = 1000
*/

#include<iostream>
#include "class_definitions.h"
#include "search.cpp"
using namespace std;
void white_double_rent(block *blc_arr[], player &current_player)
{
    if(search(current_player.position_of_tickets_owned,3) && search(current_player.position_of_tickets_owned,7))
    {
        blc_arr[7]->current_rent = 1000;
        blc_arr[3]->current_rent = 2200;
    }
    else
    {
        if(search(current_player.position_of_tickets_owned,3))
        {
            blc_arr[3]->current_rent = 1400;
        }

        if(search(current_player.position_of_tickets_owned,7))
        {
            blc_arr[7]->current_rent = 500;
        }
    }

    if(search(current_player.position_of_tickets_owned,33) && search(current_player.position_of_tickets_owned,22))
    {
        blc_arr[33]->current_rent = 2500;
        blc_arr[22]->current_rent = 1500;
    }
    else
    {
        if(search(current_player.position_of_tickets_owned,33))
        {
            blc_arr[33]->current_rent = 1500;
        }

        if(search(current_player.position_of_tickets_owned,7))
        {
            blc_arr[22]->current_rent = 800;
        }
    }

    if(search(current_player.position_of_tickets_owned,12) && search(current_player.position_of_tickets_owned,31))
    {
        blc_arr[31]->current_rent = 1000;
        blc_arr[12]->current_rent = 2500;
    }
    else
    {
        if(search(current_player.position_of_tickets_owned,31))
        {
            blc_arr[31]->current_rent = 500;
        }

        if(search(current_player.position_of_tickets_owned,12))
        {
            blc_arr[12]->current_rent = 1500;
        }
    }
}

