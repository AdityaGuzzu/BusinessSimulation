/*
    ABOUT:
    ---> A function to create a member function of blocks which sets the net transaction value
        of the block.
    -------------------------------------------------------------------------------------------
    PARAMETERS:
    ---> NONE
    -------------------------------------------------------------------------------------------
    RETURN VALUE:
    ---> NONE
*/

#include "class_definitions.h"

void block::net_transaction()
{
    int net_amount = 0;

    //using a range based for loop to iterate over the transactions vector
    for(int transaction: this->transactions)
    {
        net_amount += transaction;
    }
    this->net_trans_val = net_amount;
}