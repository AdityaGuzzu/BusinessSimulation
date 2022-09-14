/*
    This function just prints the number of visits of each block in a CSV file
    --------------------------------------------------------------------------
    PARAMETERS:
    ---> An array of blocks
    --------------------------------------------------------------------------
    RETURN VALUE:
    ---> NONE
*/

#include "class_definitions.h"
void visits_func(block *blocks[])
{
    std::fstream OutFile("data/visits.csv",std::ios::app);
    OutFile<<std::endl;
    for(int i=0; i<36; i++)
    {
        OutFile<<blocks[i]->name<<','<<blocks[i]->visits;
        OutFile<<std::endl;
    }
}