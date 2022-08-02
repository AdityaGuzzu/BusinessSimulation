#include "class_definitions.h"
void UNO(player *players[], player *current_player, block *blocks[], UNO_class &UNO)
{
	UNO.visits++;
    switch (current_player->throw_)
    {
        case 2:
        current_player->balance += (sizeof(players)/sizeof(int) - 1)*500;
        for(int i=0; i<(sizeof(players)/sizeof(int));i++)
        {
            if(i != current_player->player_number)
            {
                players[i]->balance -= 500;
                //call mortgage function 
            }
        }

        case 3:
        if(current_player->position == 4)       //if the player is in the first UNO
        {
                 //Moving the player to jail
                current_player->blocks_covered += 23;

                //incrementing the jail visits    
                blocks[27]->visits++;

                //updating the position 
                current_player->position = (current_player->blocks_covered%36);

                //updating the rounds
                current_player->rounds.push_back(current_player->blocks_covered/36);

                //paying 500
                current_player->balance -= 500;

                //call mortgage function
        }
        else                                            //IF he is in the second UNO
        {
               //Moving the player to jail
                current_player->blocks_covered += 2;

                //incrementing the jail visits    
                blocks[27]->visits++;

                //updating the position 
                current_player->position = (current_player->blocks_covered%36);

                //updating the rounds
                current_player->rounds.push_back(current_player->blocks_covered/36);

                //paying 500
                current_player->balance -= 500;

                //call mortgage function
        }

        case 4:
                current_player->balance += 2500;
            
        case 5:
                current_player->balance -= 2500;
                //call mortgage function
        
        case 6:
                current_player->balance += 2000;
        
        case 7:

        
    }
   
}
