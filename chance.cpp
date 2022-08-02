#include "class_definitions.h"
#define TRANSACTION current_player->transactions.push_back
void chance_class::transaction(player *players[], player *current_player, chance_class &chance, int number_of_players, jail_class &jail, start_class &start)
{
		chance.visits ++;
		switch(current_player->throw_)
	{
		case 2:
			current_player->balance -= 2000;
			TRANSACTION(-2000);
		
		case 3:
			current_player->balance += 2500;
			TRANSACTION(2500);

		case 4:
			current_player->balance -= 1000;
			TRANSACTION(-1000);

		case 5:
			current_player->balance += 1000;
			TRANSACTION(1000);

		case 6:
			current_player->balance -= 1500;
			TRANSACTION(-1500);

		case 7:
			current_player->balance += (current_player->number_of_colour_tickets)*number_of_players*100;
			TRANSACTION((current_player->number_of_colour_tickets)*number_of_players*100);
			for(int i=0;i<number_of_players;i++)
			{
				if(i != current_player->player_number)
				{
					players[i]->balance -= (current_player->number_of_colour_tickets)*100;
					players[i]->transactions.push_back((current_player->number_of_colour_tickets)*(-100));
				}
			}
		case 8:
			current_player->balance -= 3000;
			TRANSACTION(-3500);

		case 9:
			current_player->balance += 2000;
			TRANSACTION(2000);

		case 10:
			current_player->balance -= 500;
			TRANSACTION(-500);
			if(current_player->position == 16)
			{
				current_player->blocks_covered += 9;
				current_player->rounds.push_back(current_player->blocks_covered / 36);
				current_player->round = current_player->rounds.back();
			}
			else
			{
				current_player->blocks_covered += 34;
				current_player->rounds.push_back(current_player->blocks_covered / 36);
				current_player->round = current_player->rounds.back();
				start.transaction(current_player, start);

			}
			current_player->position = 27;
			jail.visits++;
			
		case 11:
			current_player->balance += 1500;
			TRANSACTION(1500);

		case 12:
			current_player->balance -= 200;
			TRANSACTION(-200);
	}
}