/*  
	----------------------------------------------------------------------------
	ARGUMENTS:
	---> Player pointer vector 					(vector<player *>)
	---> Current player's pointer				(*player)	
	---> refernce to number of players			(&int)
	---> A pointer array of type block 			(*block[])
	----------------------------------------------------------------------------
	RETURN VALUE: NONE
	----------------------------------------------------------------------------
	ALGORITHM:
	---> credit 200*(number_of_players -1) to the current player's bank account
	---> debit 200 from all the players bank account
		---> check for the player's bankruptcy
*/
#include "class_definitions.h"
void party_house_class::transaction(vector<player *> players,player *current_player,int &number_of_players, block *blocks[])
	{
		blocks[current_player->position]->visits++;
		current_player->balance += (number_of_players - 1)*200;
		TRANSACTION((number_of_players - 1)*200);
		for(int i=0; i<number_of_players; i++)
			{
				if(i == current_player->player_number)
				{
					continue;
				}
				players[i]->balance -= 200;
				players[i]->transactions.push_back(-200);
				
				//check mortgage for the player
				mortgage(players[i], blocks, number_of_players);
			}	
	}	