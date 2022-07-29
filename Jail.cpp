/* ALGORITHM:
   ---> Increment the visits variable by one
   ---> Debit 500 from the current player's balance
*/

#include "class_definitions.h"
void jail_class::transaction(player &current_player)
{
	visits++;
	current_player.balance -= 500;
}