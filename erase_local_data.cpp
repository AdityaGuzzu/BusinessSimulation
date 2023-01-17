/*
    To minimize the space consumption, delete all the local files.
    This function is executed after all the global data is updated
    -----------------------------------------------------------------------
    PARAMETERS:
    ---> An array of pointers to blocks     (block *blocks[])
    -----------------------------------------------------------------------
    RETURN VALUES:
    ---> NONE
    ------------------------------------------------------------------------
    ALGORITHM:
    ---> Create a file pointer
    ---> Point to to all the required files usign the read mode one by one.
    ---> close all of them.
*/

#include "class_definitions.h"
void erase_local_data(block *blocks[])
{
    //open the CSV file with write mode to erase the existing data
    for(int iter=0; iter<36; iter++)
    {
        std::string file_name = cwd + "/local_data/"+blocks[iter]->name+".csv"; 
        std::fstream ClearFile(file_name,std::ios::out);
        ClearFile.close();
    }

    //clear the visits.csv file from local data
    std::fstream visits(cwd + "/local_data/visits.csv",std::ios::out);
    visits.close();

    //clear the local IR_ratio.csv file
    // std::fstream IR_ratio("local_data/IR_ratio.csv",std::ios::out);
    // IR_ratio.close();

    //clear the transactions.txt file
    std::fstream transactions_file(cwd + "/transactions.txt",std::ios::out);
    transactions_file.close();

    //clear the colour_house_wise_IR csv file
    //std::fstream chwIR("local_data/house_wise_IR.csv");
    //chwIR.close();
}

