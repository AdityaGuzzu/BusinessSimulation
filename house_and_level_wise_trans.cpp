/*
    This function appends the net house and level wise transactions into their respective CSV
    files.
    -----------------------------------------------------------------------------------------
    PARAMETERS:
    ---> An Array of blocks                                     (block *)
    -----------------------------------------------------------------------------------------
    RETURN VALUE:
    ---> NONE
*/
#include "class_definitions.h"

void house_and_level__wise_trans(block *blocks[])
{
    std::ofstream Colour_Out_File("local_data/colour_house_wise_data.csv");
    std::ofstream White_Out_File("local_data/white_level_wise_trans.csv");
    
        //Printing the Column names of both the files
        Colour_Out_File<<"Ticket Name"<<","<<"0 houses"<<","<<"1 house"<<","<<"2 houses"<<","<<"3 houses"<<","<<"hotel"<<std::endl;
        White_Out_File<<"Ticket Name"<<","<<"No Double Rent"<<","<<"Double Rent"<<std::endl;

        for(int iter=0; iter<36; iter++)
        {
            //First check if the block is a ticket
            if(blocks[iter]->block_type == "ticket")
            {
                //check for clour ticket
                if(blocks[iter]->colour)
                {
                    Colour_Out_File<<blocks[iter]->name;
                    for(int house_net_trans:blocks[iter]->house_wise_trans)
                    {
                        Colour_Out_File<<','<<house_net_trans;
                    }
                    Colour_Out_File<<std::endl;
                }

                //else its white
                else
                {
                    White_Out_File<<blocks[iter]->name;
                    for(int house_net_trans:blocks[iter]->house_wise_trans)
                    {
                        White_Out_File<<','<<house_net_trans;
                    }
                    White_Out_File<<std::endl;
                }
            }
        }
        Colour_Out_File.close();
        White_Out_File.close();
    
}
