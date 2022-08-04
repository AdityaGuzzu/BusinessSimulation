/*  This function debits 100*(number of colour tickets owned by the player)
	---------------------------------------------------------------------------------------
	ALGORITHM:
	---> Increment the visits of the customs duty block\
	---> Debit (number of colour ticketrs)*100 from the current player's balance
*/

#include "class_definitions.h"
void customs_duty_class::transaction(player *current_player, int &number_of_players, block *blocks[])
{
		blocks[current_player->position]->visits++;
		int amount = current_player->number_of_colour_tickets*100;
		current_player->balance -= amount;
		TRANSACTION(amount);

		//call the mortgage function
		mortgage(current_player, blocks, number_of_players);
}
