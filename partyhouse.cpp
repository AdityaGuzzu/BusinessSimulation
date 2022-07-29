/*  This function debits 200*(number_of_players -1) from
	the current player's account and credits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: A  pointer array of type player, Current player's pointer, number of players
	----------------------------------------------------------------------------
	RETURN VALUE: NONE
*/
#include "class_definitions.h"
void resort_transaction(player *player_array[],player *current_player,int number_of_players, party_house_class &party_house)
	{
		party_house.visits++;
		current_player->balance += (number_of_players - 1)*200;
		for(int i=0; i<number_of_players && i != current_player->player_number; i++)
			{
				player_array[i]->balance -= 200;
			}		
	}	