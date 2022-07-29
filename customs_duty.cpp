#include "class_definitions.h"
void customs_duty_class::transaction(player &current_player)
{
		visits++;
		int amount = current_player.number_of_colour_tickets*100;
		current_player.balance -= amount;
		current_player.transactions.push_back(amount);
}
