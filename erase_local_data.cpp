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
    std::fstream visits("local_data/visits.csv",std::ios::out);
    visits.close();

    // //clearing the local IR_ratio.csv file
    // std::fstream IR_ratio("local_data/IR_ratio.csv",std::ios::out);
    // IR_ratio.close();
}