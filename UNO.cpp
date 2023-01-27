/*
    The Rules of UNO:
    ---> A player can arrive into UNO by throwing any number from 2 to 12
	---> Every number has a different transaction rule
        ---> 2:
            ---> Collect $500 from all other players
        ---> 3:
            ---> Go to Jail
        ---> 4:
            ---> Credit $2500 to the current player's balance
        ---> 5:
            ---> Debit $2500 from current player's balance
        ---> 6:
            ---> Credit $2000 to current player's balance
        ---> 7:
            ---> Either debit $5000 from current player's balance or current player
                wont recieve rent for 5 rounds
        ---> 8:
            ---> Go to Party House
        ---> 9:
            ---> Debit $50 for each house current player owns and $100 for each hotel from the
                current player's balance
        ---> 10:
            ---> Credit $1500 to the current player's balance
        ---> 11:
            ---> Debit $1500 from current player's balance
        ---> 12:
            ---> Credit $3000 to the current player's balance
*/

#include "class_definitions.h"
void UNO_class::UNO(vector<player *> players, player *current_player, block *blocks[],int org_num_of_players, int &number_of_players)
{
	blocks[current_player->position]->visits++;
    switch (current_player->throw_)
    {
        case 2:
            current_player->balance += number_of_players*500;
            TRANSACTION(number_of_players*500);
            for(int i=0; i<org_num_of_players;i++)
            {
                if(i != current_player->player_number && !players[i]->bankrupt)
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

            //Appending to the CSV file
            blocks[current_player->position]->transaction(500);

            //Appending to the transactions vector
            blocks[current_player->position]->transactions.push_back(500);
            
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

                 //appending -2500 to the UNO4.csv file
                    blocks[current_player->position]->transaction(-2500);

                 //appending -2500 to the transactions vector
                    blocks[current_player->position]->transactions.push_back(-2500);
                break;
            
        case 5:     
                current_player->balance -= 2500;
                TRANSACTION(-2500);

                //calling the mortgage function 
                mortgage(current_player, blocks, number_of_players);

                //Appending to the CSV file
                blocks[current_player->position]->transaction(2500);

                //Appending to the transactions vector
                blocks[current_player->position]->transactions.push_back(2500);
                break;

        case 6:
                current_player->balance += 2000;
                TRANSACTION(2000);
                
                //Appending to the CSV file
                blocks[current_player->position]->transaction(-2000);

                //Appending to the transactions vector
                blocks[current_player->position]->transactions.push_back(-2000);
                break;
        
        case 7:
                if(rand_bool(current_player->position) && (current_player->balance > 5000))
                {
                    current_player->balance -= 5000;
                    TRANSACTION(-5000);    

                    //Appending to the CSV file
                    blocks[current_player->position]->transaction(5000);

                    //Appending to the transactions vector
                    blocks[current_player->position]->transactions.push_back(5000);     
                }
                else
                {
                    current_player->rent_elig = false;
                    current_player->last_time_at_uno = current_player->blocks_covered;
                }

                //calling the mortgage function 
                mortgage(current_player, blocks, number_of_players);
                break;

        case 8:
                current_player->balance += (number_of_players-1)*200;
                TRANSACTION((number_of_players-1)*200);
                blocks[18]->visits++;

                //for first UNO
                if(current_player->position == 4)
                {
                    current_player->blocks_covered += 14;
                }

                //for second UNO
                else
                {
                    current_player->blocks_covered += 29;    
                    current_player->balance += 2000; //we know the player crossed start.
                }
                
                current_player->rounds.push_back(current_player->blocks_covered/36);
                current_player->round = current_player->rounds.back();
                current_player->position = (current_player->blocks_covered%36);
                
                for(int i=0; i<org_num_of_players; i++)
                {
                    if(i != current_player->player_number && !players[i]->bankrupt)
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

                //calling the mortgage function 
                mortgage(current_player, blocks, number_of_players);
                break;

        case 10:
                current_player->balance += 1500;
                TRANSACTION(1500);

                //Appending to CSV file
                blocks[current_player->position]->transaction(-1500);

                //Appending to transactions vector
                blocks[current_player->position]->transactions.push_back(-1500);
                break;

        case 11:
                current_player->balance -= 1500;
                TRANSACTION(-1500);

                //Appending to the CSV file
                blocks[current_player->position]->transaction(1500);

                //Appending to the transactions vector
                blocks[current_player->position]->transactions.push_back(1500);

                //calling the mortgage function 
                mortgage(current_player, blocks, number_of_players);
                break;

        case 12:
                current_player->balance += 3000;
                TRANSACTION(3000);

                //Appending to the CSV file
                blocks[current_player->position]->transaction(-3000);

                //Appending to the transactions vector
                blocks[current_player->position]->transactions.push_back(-3000);

                //calling the mortgage function 
                mortgage(current_player, blocks, number_of_players);
                break;
                
    }
                
}

    
