/*  ALGORITHM:
    ---> Create a multi dimensional array of size (number of colours)*(number of tickets per colour) call it colour_grouping 
	---> FOR every row in the colour tickets array:
		---> create an array of size 'number of tickets per colour' call it player's colour tickets
		---> FOR every ticket owned by current player:
            ---> FOR every column in the current row
                ---> IF ticket is colour:
                    ---> search for the ticket
                    ---> IF the ticket is found:
                        ---> Add its position to the player's colour tickets
        ---> IF the length of player's colour tickets > 3:
            ---> FOR every ticket in player's colour tickets:
                ---> IF number of houses in that ticket == 0:
                    ---> current rent = 2*basic rent
*/

#include<iostream>
#include "class_definitions.h"
#define PLAYER_TICKETS current_player->position_of_tickets_owned
void colour_double_rent(player *current_player, block *blocks[])
{
    //First row: red. Second row: green. Third row: yellow. Fourth row: Blue
    int colour_grouping[4][5]= { {1,5,11,14,17}, {2,6,8,30,34}, {10,15,20,23,26}, {19,24,28,32,35} };
    for(int i=0; i<4; i++)      //loop over the rows of colour_grouping 
    {
        vector<int> pl_colour_grouping;
        for(j=0;j<PLAYER_TICKETS.size(); j++)    //to loop over the player tickets
        {
            for(int k=0;k<5;k++)                //to loop over the columns of the ith row of colour_grouping
            {
                if(PLAYER_TICKETS[j] == colour_grouping[i][k])
                {
                    pl_colour_grouping.push_back(colour_grouping[i][k]);
                }
            }   
        }
        pl_colour_grouping.shrink_to_fit();     //For memory conservation
            if(pl_colour_grouping.size() >= 3)
            {
                for(int l=0;l<pl_colour_grouping.size();l++)
                {
                    if(blocks[pl_colour_grouping[l]]->number_of_houses == 0)
                    {
                        blocks[pl_colour_grouping[l]]->current_rent = 2*blocks[pl_colour_grouping[l]]->basic_rent;
                    }
                }
            }
    }

}