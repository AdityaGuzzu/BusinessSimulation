/*
    OBJECTIVE OF THIS FILE:
    ---> Append the net transaction value of each ticket/block into the 'one_game_data.csv' file in the data folder
    ---------------------------------------------------------------------------------------------------------------
    ALGORITHM:
    ---> Append the ticket name and the net transaction value of every block into the CSV file.
*/

#include "class_definitions.h"
void net_trans_into_CSV(block *blocks[])
{
    //opening the CSV file
    std::fstream out("local_data/one_game_net_trans.csv",std::ios::out);
    out<<"Block Name"<<','<<"Net Transaction Value"<<std::endl;
    for(int i=0; i<36; i++)
    {
        //calling the net_transaction function to calculate 
        blocks[i]->net_transaction();
        
        //Finally, appending the data into the CSV
        out<<blocks[i]->name<<','<<blocks[i]->net_trans_val<<std::endl;
    }
}