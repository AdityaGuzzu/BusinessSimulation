#include "class_definitions.h"
void chance_class::chance_transaction(player *pl,int player_num,int number_of_players)
{
		switch(current_player->throw)
	{
		case 2:
			current_balance -= 2000;
		
		case 3:
			current_balance += 2500;

		case 4:
			current_balance -= 1000;

		case 5:
			current_balance += 1000;

		case 6:
			current_balance -= 2000;

		case 7:
			current_balance += (current_player->colour_tickets.length())*(number_of_players)*100;
			for(int i=0; i<number_of_players && i != player_num; i++)
			{
				pl[i]->balance -= current_player->colour_tickets.length()*100;
			}
				
		case 8:
			current_balance -= 3000;

		case 9:
			current_balance += 2000;

		case 10:
			current_balance -= 500;
			current_player->position = 27;
			current_player->positions.push_back(36*(current_player->rounds) + 27);
	
		case 11:
			current_balance += 1500;

		case 12:
			current_balance -= 200;
	}
}