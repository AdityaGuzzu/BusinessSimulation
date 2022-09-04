#include "class_definitions.h"
void block::transaction(int amount)
{
    std::string filename = this->name + ".csv";
    std::fstream data_append(filename,std::ios::app);
    if(this->visits == 0)
    {
        data_append<<std::endl;
    }
    data_append<<amount<<",";
}