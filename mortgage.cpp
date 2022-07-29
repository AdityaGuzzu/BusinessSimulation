/*  This file contains a function which is called when the balance goes to negative
    after a transaction.
    -------------------------------------------------------------------------------
    PARAMETERS:
    ---> A reference to current player
    ---> An integer representing the deficit
    ---> A poionter array of type blocks 
    -------------------------------------------------------------------------------
    RETURN TYPE:
    ---> NONE
    --------------------------------------------------------------------------------
    ALGORITHM:
    ---> Declare int money_raised 
    ---> money_raised = 0
    ---> WHILE (deficit - money_raised) <= 0 AND number of tickets owned by the player > 0:
        ---> Initialise a variable ticket_position
        ---> Select the last element of positions of tickets owned vector
        ---> Initialise ticket_position with the lase element.
        ---> money_raised += (mortgage value of the last ticket in the vector)
        ---> add the ticket's position to positions of sold tickets vector
        ---> pop the ticket from positions of owned tickets
        ---> Now refer to this ticket as the last element of 'position of sold tickets' vector
            (since we popped it from owned tickets)
        ---> IF the ticket is colour:
            ---> set number of houses to 0
            ---> set the current rent to basic rent
            ---> set double rent checker to false
            ---> call colour double rent function (this will check double rent of remaining tickets of the player)
        ---> ELSE
            ---> set current rent to basic rent
            ---> call white double rent function
        ---> IF money_raised - deficit >0:
            ---> call the bankrupt function
    ---------------------------------------------------------------------------------
*/

#include<iostream>
#include "class_definitions.h"
void mortgage(player &current_player,int deficit, block *blocks[])
{
    int money_raised = 0;
    while(!(deficit + money_raised <= 0) && current_player.position_of_tickets_owned.size() > 0 )
    {
        int ticket_position;
        int mort_val;
        ticket_position = current_player.position_of_tickets_owned.back();      //last element of positions of tickets owned
        mort_val = blocks[ticket_position]->mortgage_value;
        current_player.transactions.push_back(mort_val);
        current_player.balance += mort_val;
        blocks[ticket_position]->owner_num = -1;
        current_player.position_of_tickets_sold.push_back(ticket_position);
        current_player.position_of_tickets_owned.pop_back();
        if(blocks[ticket_position]->colour_code == 1)
        {
            blocks[ticket_position]->number_of_houses = 0;
            blocks[ticket_position]->current_rent =blocks[ticket_position]->basic_rent;
            blocks[ticket_position]->double_rent_checker = false;
            //call double rent function
        }
        else
        {
            blocks[ticket_position]->current_rent = blocks[ticket_position]->basic_rent;
            white_double_rent(blocks,current_player);
        }

        if((money_raised - deficit) < 0 )
        {
            //call bankrupt function.
        }
    }
}


