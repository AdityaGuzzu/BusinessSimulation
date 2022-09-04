/*
	The Rules of Chance:
	---> A player can arrive into chance by throwing any number from 2 to 12
	---> Every number has a different transaction rule
		---> 2:
			---> Debit $2000 from current player's balance
		---> 3:
			---> Credit $2500 to the current player's balance
		---> 4:
			---> Debit $1000 from current player's balance
		---> 5:
			---> Credit $1000 to the current player's balance
		---> 6:
			---> Debit $1500 from current player's balance
		---> 7:
			---> Collect $100 for every colour ticket the player owns from all other players
		---> 8:
			---> Debit $3000 from current player's balance
		---> 9:
			---> Credit $2000 to the current player's balance
		---> 10:
			---> Go to Jail
		---> 11:
			---> Credit $1500 to the current player's balance
		---> 12:
			---> Debit $200 from current player's balance
*/

#include "class_definitions.h"
void chance_class::transaction(vector<player *> players, player *current_player,int org_num_of_players ,int &number_of_players, block *blocks[])
{
		blocks[current_player->position]->visits ++;
		switch(current_player->throw_)
		{
			case 2:
				current_player->balance -= 2000;
				TRANSACTION(-2000);

				//Appending the respective csv file
				blocks[current_player->position]->transaction(2000);

				//Appending the transactions vector
				blocks[current_player->position]->transactions.push_back(2000);
				break;
			
			case 3:
				current_player->balance += 2500;
				TRANSACTION(2500);

				//Appending the CSV file
				blocks[current_player->position]->transaction(-2500);

				//Appending the transactions vector
				blocks[current_player->position]->transactions.push_back(-2500);
				break;

			case 4:
				current_player->balance -= 1000;
				TRANSACTION(-1000);

				//Appedning to the CSV file
				blocks[current_player->position]->transaction(1000);

				//Appending to the transactions vector
				blocks[current_player->position]->transactions.push_back(1000);
				break;

			case 5:
				current_player->balance += 1000;
				TRANSACTION(1000);

				//Appending to the CSV file
				blocks[current_player->position]->transaction(-1000);
				
				//Appending to the transactions vector
				blocks[current_player->position]->transactions.push_back(-1000);
				break;

			case 6:
				current_player->balance -= 1500;
				TRANSACTION(-1500);

				//Appending to the CSV file
				blocks[current_player->position]->transaction(1500);

				//Appending to the transactions vector
				blocks[current_player->position]->transactions.push_back(1500);
				break;

			case 7:
				current_player->balance += (current_player->number_of_colour_tickets)*number_of_players*100;
				TRANSACTION((current_player->number_of_colour_tickets)*number_of_players*100);
				for(int i=0;i<org_num_of_players;i++)
				{
					if(i != current_player->player_number && !players[i]->bankrupt)
					{
						players[i]->balance -= (current_player->number_of_colour_tickets)*100;
						players[i]->transactions.push_back((current_player->number_of_colour_tickets)*(-100));
						mortgage(players[i], blocks, number_of_players);
					}
				}
				break;

			case 8:
				current_player->balance -= 3000;
				TRANSACTION(-3500);
				break;

			case 9:
				current_player->balance += 2000;
				TRANSACTION(2000);
				break;

			case 10:
				current_player->balance -= 500;
				TRANSACTION(-500);
				if(current_player->position == 16)
				{
					current_player->blocks_covered += 11;
					current_player->rounds.push_back(current_player->blocks_covered / 36);
					current_player->round = current_player->rounds.back();
				}
				else
				{
					current_player->blocks_covered += 34;
					current_player->rounds.push_back(current_player->blocks_covered / 36);
					current_player->round = current_player->rounds.back();
					current_player->balance += 2000;

				}

				//Appending to the CSV file
				blocks[current_player->position]->transaction(500);

				//Appending to the transactions vector
				blocks[current_player->position]->transactions.push_back(500);

				current_player->position = 27;
				blocks[27]->visits++;
				break;
				
			case 11:
				current_player->balance += 1500;
				TRANSACTION(1500);

				//Appending to the CSV file
				blocks[current_player->position]->transaction(-1500);

				//Appending to the transactions vector
				blocks[current_player->position]->transactions.push_back(-1500);

				break;

			case 12:
				current_player->balance -= 200;
				TRANSACTION(-200);

				//Appending to the CSV file
				blocks[current_player->position]->transaction(200);

				//Appending to the transactions vector
				blocks[current_player->position]->transactions.push_back(200);
				break;
		}

	//Checking if the player has to sell something or if he is bankrupt.
	mortgage(current_player, blocks, number_of_players);
}