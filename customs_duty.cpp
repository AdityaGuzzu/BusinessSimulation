/*  This function debits 100*(number of colour tickets owned by the player)
	---------------------------------------------------------------------------------------
	ALGORITHM:
	---> Increment the visits of the customs duty block\
	---> Debit (number of colour ticketrs)*100 from the current player's balance
*/

#include "class_definitions.h"
void customs_duty_class::transaction(player *current_player, customs_duty_class &customs_duty)
{
		customs_duty.visits++;
		int amount = current_player->number_of_colour_tickets*100;
		current_player->balance -= amount;
		current_player->transactions.push_back(amount);
}
