#include "class_definitions.h"
void block::transaction(int amount)
{
    std::string filename = this->name + ".csv";
    std::fstream data_append("data/"+filename,std::ios::app);
    if(this->transactions.size() == 0)
    {
        data_append<<std::endl;
    }
    transaction_ID++;
    data_append<<std::endl<<transaction_ID<<','<<amount;
}