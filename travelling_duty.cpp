#include "class_definitions.h"
void travelling_duty_class::transaction(player *current_player, travelling_duty_class &travelling_duty)
{
		travelling_duty.visits++;
		int amount = current_player->number_of_colour_tickets*50;
		current_player->balance -= amount;
		current_player->transactions.push_back(amount);
}
