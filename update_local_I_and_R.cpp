#include "class_definitions.h"
void update_total_investment_and_return(block *blocks[])
{
    
    std::fstream investment_file(cwd+"/local_data/total_investment.csv",std::ios::out);
    std::fstream return_file(cwd+"/local_data/total_return.csv",std::ios::out);
    investment_file<<"Block Name,Total Investment";
    for(int iter=0; iter<36; iter++)
    {
        investment_file<<'\n'<<blocks[iter]->name<<','<<std::accumulate(blocks[iter]->house_wise_investment.begin(),blocks[iter]->house_wise_investment.end(),0);
    }
    return_file<<"Block Name,Total Return";
    for(int iter=0; iter<36; iter++)
    {
        return_file<<'\n'<<blocks[iter]->name<<','<<std::accumulate(blocks[iter]->house_wise_return.begin(),blocks[iter]->house_wise_return.end(),0);
    }
}
