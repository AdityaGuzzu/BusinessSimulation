#include "class_definitions.h"
#include "function_declarations.h"
void uno_transaction(player *pl,int player_num,int number_of_players, ticket *array)
{
	typedef pl[player_num] = current_player;
	typedef current_player->balance = current_balance;
	int i;
	void uno_transaction(player *pl,int player_num,int number_of_players, ticket *array);
	{
		int house_counter = 0;
		int hotel_counter = 0;
		switch(current_player.throw)
		{
		case 2:
			current_balance = (number_of_players - 1)*500; 
			for(int i=0;i<number_of_players && i != player_num;i++)
			{
				pl[i]->balance -= 500;
			}

		case 3:
			current_balance -= 500;
			current_player->position = 27;
			current_player->positions.push_back(27);

		case 4:
			current_balance += 2500;
		case 5:
			current_balance -= 2500;
		case 6:
			current_balance += 2000;
		case 7:

			last_uno_num = current_player->at_uno;
			if(current_player->deduct_5000 == 0 && current_player-> uno_5000_pay)
			{
				
				
				current_balance -= 5000;
			}
			else
			{
				if(current_player->positions.end() - last_uno_num >= 180)
				{
					current_player->rent_elig = true;
					deduct_5000 = 0;
				}
				else
				{
					current_player->rent_elig = false;
				}
			}
		case 8:
			current_balance = (number_of_players - 1)*200; 
			for(i=0; i<number_of_players && i != player_num; i++)
			{
				pl[i]->balance -= 200;
			}
			current_player->position = 18;
			current_player->positions.push_back(36*(current_player->rounds) + 18);
		case 9:
			for(i=0;i<36;i++)
			{
				house_counter += array[i]->number_of_houses;
			}
			for(i=0;i<36;i++)
			{
				hotel_counter += array[i]->hotel;
			}
			current_balance -= (house_counter)*50 + (hotel_counter)*100;

		case 10:
			current_balance += 1500;
		
		case 11:
			current_balance -= 1500;

		case 12:
			current_balance += 3000;		
			
		}
	}
}