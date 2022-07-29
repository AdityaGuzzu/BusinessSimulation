/* This file will add 2000 to the balance of the player if he crossed start.
	ALGORITHM:
	---> Take the current player's reference as an argument
	---> In the 'rounds' vector which has the round number of the player after every throw,
		---> Check the last two elements. If they differ by one, credit 2000 to the balance.
	---> If the player is exactly on start, credit 2000 to the balance
*/
#include "class_defintions.h"
void start_class::transaction(player &current_player)
{
	if((current_player.position%36) == 0)
	{
		visits ++;
	}
	if(current_player.rounds.back() - current_player.rounds(rounds.size()-1) == 1)
	{
		current_player.balance += 2000;
	}
}
