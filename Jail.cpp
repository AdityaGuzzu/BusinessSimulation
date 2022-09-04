/* 
   PARAMETERS:
   ---> A pointer to player                     (player *)
   ---> A pointer array of blocks               (block *[])
   ---> A reference to the number of players    (&int)
   ---------------------------------------------------------------------------------------
   RETURN VALUE:
   ---> NONE
   ---------------------------------------------------------------------------------------
   ALGORITHM:
   ---> Increment the visits variable by one
   ---> Debit 500 from the current player's balance
   ---> Call the mortgage function
*/

#include "class_definitions.h"
void jail_class::transaction(player *current_player, block *blocks[], int &number_of_players)
{
	blocks[current_player->position]->visits++;
	current_player->balance -= 500;
   TRANSACTION(-500);

   //This appends 500 to the Jail.csv file
   blocks[current_player->position]->transaction(500);

   //appends 500 to the transactions vector
   blocks[current_player->position]->transactions.push_back(500);


   //calling mortgage function
   mortgage(current_player,blocks,number_of_players);
}