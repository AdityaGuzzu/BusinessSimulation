#include "class_defintions.h"
#include "function_declarations.h"

void start_checker(player *p1, int player_num)
{
	int current_position = current_player->positions[positions.size()-1];
	int prev_position = current_player->positions[positions.size()-2];
		for(i=prev_position;i<=current_position;i++)
		{
			if(i%36 ==0)
			{
				start = true;
			}	
		}
		if(start)
		{
			current_balance += 2000;
		}	
}