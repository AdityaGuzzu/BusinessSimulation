#include "class_definitions.h"
#include "function_declarations.h"
void resort_transaction(player *pl,int player_num,int number_of_players)
	{
		current_player->balance -= (number_of_players - 1)*200;
		for(i=0; i<number_of_players && i != player_num; i++)
			{
				pl[i]->balance += 200;
			}
					
	}	