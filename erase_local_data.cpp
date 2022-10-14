/*
This file cleans the local game data's CSV file to reduce the consumption of space.    
*/
#include "class_definitions.h"
void erase_local_data(block *blocks[])
{
    //opening the CSV file with write mode to erase the existing data
    for(int iter=0; iter<36; iter++)
    {
        std::string file_name = "local_data/"+blocks[iter]->name+".csv"; 
        std::fstream ClearFile(file_name,std::ios::out);
        ClearFile.close();
    }

    //clearing the visits.csv file from local data
    std::ofstream visits("local_data/visits.csv");
    visits.close();
}