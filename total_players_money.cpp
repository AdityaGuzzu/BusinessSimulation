#include "class_definitions.h"
int total_players_money(std::vector<player *> players)
{
    std::vector<player *>::iterator it;
    int sum = 0;
    for(auto it:players)
    {
        sum += it->balance;
    }
    return sum;
}