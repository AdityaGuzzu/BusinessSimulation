#include "class_definitions.h"
void UNO_class::UNO(player *players[], player *current_player, block *blocks[],int &number_of_players)
{
	blocks[current_player->position]->visits++;
    switch (current_player->throw_)
    {
        case 2:
            current_player->balance += (sizeof(players)/sizeof(int) - 1)*500;
            TRANSACTION((sizeof(players)/sizeof(int) - 1)*500);
            for(int i=0; i<(sizeof(players)/sizeof(int));i++)
            {
                if(i != current_player->player_number)
                {
                    players[i]->balance -= 500;
                    players[i]->transactions.push_back(-500);
                    mortgage(players[i], blocks,number_of_players);
                }
            }
            break;

        case 3:
            //paying 500
            current_player->balance -= 500;
            TRANSACTION(-500);
            
            //incrementing the jail visits    
             blocks[27]->visits++;

            //calling mortgage function
            mortgage(current_player, blocks, number_of_players);

            if(current_player->position == 4)       //if the player is in the first UNO
            {
                    //Moving the player to jail
                    current_player->blocks_covered += 23;
            }
            else                                     //IF he is in the second UNO
            {
                //Moving the player to jail
                    current_player->blocks_covered += 2;            
            }
            //updating the position 
            current_player->position = (current_player->blocks_covered%36);

            //updating the rounds
            current_player->rounds.push_back(current_player->blocks_covered/36); 
            break;

        case 4:     //2500 credit
                current_player->balance += 2500;
                TRANSACTION(2500);
                break;
            
        case 5:     //2500 debit
                current_player->balance -= 2500;
                TRANSACTION(-2500);
                break;

        case 6:
                current_player->balance += 2000;
                TRANSACTION(2000);
                break;
        
        case 7:
                if(rand_bool())
                {
                    current_player->balance -= 5000;
                    TRANSACTION(-5000);                 
                }
                else
                {
                    current_player->rent_elig = false;
                    current_player->last_time_at_uno = current_player->blocks_covered;
                }
                break;

        case 8:
                current_player->balance += (sizeof(players)/sizeof(int) - 1)*200;
                TRANSACTION((sizeof(players)/sizeof(int) - 1)*200);
                blocks[18]->visits++;

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
                        players[i]->transactions.push_back(-200);

                        //calling mortgage function
                        mortgage(players[i], blocks, number_of_players);
                    }
                }
                break;
        
        case 9:
                for(int i=0; i<current_player->position_of_tickets_owned.size();i++)
                {
                    if(blocks[current_player->position_of_tickets_owned[i]]->colour)
                    {
                        if(blocks[current_player->position_of_tickets_owned[i]]->number_of_houses < 4)
                        {
                            current_player->balance -= 50*blocks[current_player->position_of_tickets_owned[i]]->number_of_houses;
                            TRANSACTION((-50)*blocks[current_player->position_of_tickets_owned[i]]->number_of_houses);
                        }
                        else
                            current_player->balance -= 250;
                            TRANSACTION(-250);
                    }   
                }
                break;

        case 10:
                current_player->balance += 1500;
                TRANSACTION(1500);
                break;

        case 11:
                current_player->balance -= 1500;
                TRANSACTION(-1500);
                break;

        case 12:
                current_player->balance += 3000;
                TRANSACTION(3000);
                break;
    }

    //calling the mortgage function of current player
    mortgage(current_player, blocks, number_of_players);
}
