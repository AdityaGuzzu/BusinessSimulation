/*
    Updates house wise Investment and House wise returns in the 
    local data.
*/

#include "class_definitions.h"
void update_house_wise_investment_and_return(block *blocks[])
{
    std::fstream investment_file("C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation/local_data/house_wise_investment.csv",std::ios::out);
    std::fstream return_file("C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation/local_data/house_wise_return.csv",std::ios::out);
    investment_file<<"Ticket Name"<<", 0 Houses"<<", 1 House"<<", 2 Houses"<<", 3 Houses"<<", Hotel";
    return_file<<"Ticket Name"<<", 0 Houses"<<", 1 House"<<", 2 Houses"<<", 3 Houses"<<", Hotel";
    for(int iter=0; iter<36; iter++)
    {
        block *current_block = blocks[iter];
        if(current_block->colour)
        {
            investment_file<<std::endl<<current_block->name;
            return_file<<std::endl<<current_block->name;
            for(auto inv_amt:current_block->house_wise_investment)
            {
                investment_file<<","<<inv_amt;
            }
            for(auto ret_amt:current_block->house_wise_return)
            {
                return_file<<","<<ret_amt;
            }
        }
    }
}