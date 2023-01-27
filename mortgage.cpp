/*  This file contains a function which is called when the balance goes to negative
    after a transaction.
    -------------------------------------------------------------------------------
    PARAMETERS:
    ---> A reference to current player
    ---> An integer representing the deficit
    ---> A pointer array of type blocks 
    -------------------------------------------------------------------------------
    RETURN TYPE:
    ---> NONE
    --------------------------------------------------------------------------------
    ALGORITHM:
    ---> Declare int money_raised 
    ---> money_raised = 0
    ---> WHILE (current balance) <= 0 AND number of tickets owned by the player > 0:
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
//open the check file to which knocked out players' output is flushed
std::fstream check("check.txt",std::ios::out);
void mortgage(player *current_player, block *blocks[], int &number_of_players)
{
    if(current_player->balance < 0)
    {
        while((current_player->balance < 0) && current_player->position_of_tickets_owned.size() > 0 )
        {
            int ticket_position;
            int mort_val;
            
            
            //choosing the ticket to be sold randomly
            ticket_position = randnum(current_player->position_of_tickets_owned.size()); 
            block *current_ticket = blocks[current_player->position_of_tickets_owned[ticket_position]];
            int number_of_houses = current_ticket->number_of_houses;

            mort_val = blocks[current_player->position_of_tickets_owned[ticket_position]]->mortgage_value;
            TRANSACTION(mort_val);
            current_player->balance += mort_val;

            //changing the owner number of the ticket to -1 which means its unowned.
            current_ticket->owner_num = -1;

            //appending to a vector which keeps track of sold tickets
            current_player->position_of_tickets_sold.push_back(ticket_position);

            //Appending the mortgage value to the CSV file
            current_ticket->transaction(mort_val);

            //Appending the mortgage value to the transactions vector
            current_ticket->transactions.push_back(mort_val);


            //Perform some operations unique to colour tickets
            if(current_ticket->colour)
            {
                //deduct 1 from the number of colour tickets owned
                current_player->number_of_colour_tickets -= 1;

                //update the IR ratio of the particular house
                current_ticket->house_wise_IR_ratio[number_of_houses] = (float)current_ticket->house_wise_return[number_of_houses]/current_ticket->house_wise_investment[number_of_houses];

                //change the number of houses to 0
                blocks[current_player->position_of_tickets_owned[ticket_position]]->number_of_houses = 0;

                //change the current rent to basic rent
                blocks[current_player->position_of_tickets_owned[ticket_position]]->current_rent = blocks[current_player->position_of_tickets_owned[ticket_position]]->basic_rent;

                //check for the double rent after the ticket was sold
                colour_double_rent(current_player,blocks);

                
            }
            else
            {
                blocks[current_player->position_of_tickets_owned[ticket_position]]->current_rent = blocks[current_player->position_of_tickets_owned[ticket_position]]->basic_rent;
                white_double_rent(blocks,current_player);
            }

             //erasing the position of the ticket from the vector of tickets owned.
             current_player->position_of_tickets_owned.erase(current_player->position_of_tickets_owned.begin() + ticket_position);

        }
        if((current_player->balance) < 0 )
        {
            
            current_player->bankrupt = true;
            //The player is bankrupt now. Number of players must be decremeneted
            number_of_players -= 1;
            check<<'\n'<<current_player->player_number<<"  is bankrupt";
            check<<'\n'<<transaction_ID;
        }
    }
}

