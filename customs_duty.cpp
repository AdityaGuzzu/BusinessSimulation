#include "class_defintions.h"
void customs_duty_class::transaction(player *current_player)
{
		current_player.balance -= current_player.number_of_colour_tickets*100;
}
