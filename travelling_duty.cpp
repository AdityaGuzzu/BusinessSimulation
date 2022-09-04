#include "class_definitions.h"
void travelling_duty_class::transaction(player *current_player, int &number_of_players, block *blocks[])
{
		blocks[current_player->position]->visits++;
		int amount = current_player->number_of_colour_tickets*50;
		current_player->balance -= amount;
		TRANSACTION(-amount);

		//appending the amount to the Travelling Duty.csv file
		blocks[current_player->position]->transaction(amount);

		//Appending the amount to the transactions vector.
		blocks[current_player->position]->transactions.push_back(amount);

		//calling the mortgage function
		mortgage(current_player,blocks,number_of_players);

}
