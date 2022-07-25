#include "class_definitions.h"
void jail_transaction(player current_player)
{
	visits++;
	current_player.balance -= 500;
}