/*
    This file contains a function which creates the game wise Investment-Returns ratio
    of every block.
*/

#include "class_definitions.h"
void update_local_IR_ratio(block *blocks[])
{
    std::ofstream OutFile("local_data/IR_ratio.csv");
    OutFile<<"Block Name,IR ratio value"<<std::endl;
    for(int elem=0; elem<36; elem++)
    {
        int investment=0;
        int returns = 0;
        double IR_ratio = 0.00;
        for(int i = 0; i<blocks[elem]->transactions.size(); i++)
        {
            if(blocks[elem]->transactions[i] > 0)
            {
                returns += blocks[elem]->transactions[i];
            }
            else
            {
                investment -= blocks[elem]->transactions[i];
            }
        }
        if(investment != 0)
        {
            IR_ratio = (double)returns/investment;
        }

        OutFile<<blocks[elem]->name<<','<<IR_ratio<<std::endl;
    }
    OutFile.close();
}