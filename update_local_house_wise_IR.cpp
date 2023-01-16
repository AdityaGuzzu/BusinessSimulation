/*
    A function to update the local IR ratio to the CSV file
    ----------------------------------------------------------------------
    PARAMETERS:
    ---> An array of pointers to blocks             (block *[])
    ----------------------------------------------------------------------
    RETURN VALUE:
    ---> NONE
    ----------------------------------------------------------------------
    ALGORITHM:
    ---> Open a file 
    ---> read the house_wise_IR_ratio vector and append the details to a CSV file
*/
#include "class_definitions.h"

void update_local_colour_wise_IR(block *blocks[])
{
    
    std::fstream OutFile("local_data/house_wise_IR.csv",std::ios::out);
    OutFile<<"Ticket Name, "<<"0 Houses, "<<"1 House, "<<"2 Houses, "<<"3 Houses, "<<"Hotel"<<std::endl;
    for(int i=0;i<36;i++)
    {
        if(blocks[i]->colour)
        {
            OutFile<<blocks[i]->name+", ";
            for(auto IR:blocks[i]->house_wise_IR_ratio)
            {
                OutFile<<IR<<", ";
            }
            OutFile<<std::endl;
        }
    }
}