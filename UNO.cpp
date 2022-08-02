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

        case 4:     //2500 credit
                current_player->balance += 2500;
            
        case 5:     //2500 debit
                current_player->balance -= 2500;
                //call mortgage function
        
        case 6:
                current_player->balance += 2000;
        
        case 7:
                if(rand_bool())
                {
                    current_player->balance -= 5000;
                    //call mortgage function
                }
                else
                {
                    current_player->rent_elig = false;
                    current_player->last_time_at_uno = current_player->blocks_covered;
                }

        case 8:
                current_player->balance += (sizeof(players)/sizeof(int) - 1)*200;

                //for first UNO
                if(current_player->position == 4)
                {
                    current_player->blocks_covered += 14;
                    current_player->position = (current_player->blocks_covered%36);
                    current_player->rounds.push_back(current_player->blocks_covered/36);
                }

                //for second UNO
                else
                {
                    current_player->blocks_covered += 29;
                    current_player->position = (current_player->blocks_covered%36);
                    current_player->rounds.push_back(current_player->blocks_covered/36);
                    current_player->balance += 2000; //we know the player crossed start.
                }

                for(int i=0; i<sizeof(players)/sizeof(int); i++)
                {
                    if(i != current_player->player_number)
                    {
                        players[i]->balance -= 200;

                        //call mortgage function
                    }
                }
        
        case 9:
                for(int i=0; i<current_player->position_of_tickets_owned.size();i++)
                {
                    if(blocks[current_player->position_of_tickets_owned[i]]->colour)
                    {
                        if(blocks[current_player->position_of_tickets_owned[i]]->number_of_houses < 4)
                        {
                            current_player->balance -= 50*blocks[current_player->position_of_tickets_owned[i]]->number_of_houses;
                        }
                        else
                            current_player->balance -= 250;
                    }   
                }
                //call mortgage function

        case 10:
                current_player->balance += 1500;

        case 11:
                current_player->balance -= 1500;
                //call mortgage function

        case 12:
                current_player->balance += 3000;
    }
   
}
