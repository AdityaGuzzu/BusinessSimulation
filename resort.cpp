/*  
	ARGUMENTS: 
	---> A  pointer vector of type player					(vector<player *>)
	---> Current player's pointer							(player)
	---> a reference to the number of players				(&int)
	---> A pointer array of type block						(*block[])
	----------------------------------------------------------------------------
	RETURN VALUE: NONE
	----------------------------------------------------------------------------
	ALGORITHM:
	---> Debit 200*(number_of_players -1) from the current player's account
	---> Add 200 to all other players
	---> Check for the bankruptcy of the current player
	----------------------------------------------------------------------------
*/
#include "class_definitions.h"
void resort_class::transaction(vector<player *> players, player *current_player,int org_num_of_players,int &number_of_players, block *blocks[])
	{
		blocks[current_player->position]->visits++;
		current_player->balance -= (number_of_players - 1)*200;
		TRANSACTION((number_of_players - 1)*(-200));
		
		for(int i=0; i<org_num_of_players; i++)
			{
				if(i==current_player->player_number || players[i]->bankrupt)
				{
					continue;
				}
				players[i]->balance += 200;
				players[i]->transactions.push_back(200);
			}

		//call mortgage function
		mortgage(current_player,blocks,number_of_players);
				
	}	