/*
    A function which returns a pointer to the player who has the
	highest assets
	------------------------------------------------------------
	PARAMETERS:
	---> A vector of pointers to players		(vector<player>)
	---> An array of pointers to tickets		(block*)
	------------------------------------------------------------
	RETURN VALUE:
	---> A pointer to the player containing highest assets
    ------------------------------------------------------------
    ALGORITHM:
    ---> int max_money = 0
    ---> player *max_money_player
    ---> int player_money = 0
    ---> for player in players:
        ---> for pos in position_of_tickets_owned:
            ---> player_money += mortgage value of ticket owned
        ---> player_money += player's balance
        ---> if player_money > max_money
            ---> max_money = player_money
            ---> max_money_player = this    (pointer to player)
    ---> return max_money_player
*/

#include "class_definitions.h"
player* highest_assets(std::vector<player*> players, block* blocks[])
{
    int max_money = 0;
    player *max_money_player = nullptr;
    for(auto player:players)
    {
        int player_money = 0;

        if(player->bankrupt)
        {
            continue;
        }
        
        for(int ticket: player->position_of_tickets_owned)
        {
            player_money += blocks[ticket]->mortgage_value;
        }

        player_money += player->balance;
        
        if(player_money>max_money)
        {
            max_money = player_money;
            max_money_player = player;
        }
    }
    return max_money_player;
}

