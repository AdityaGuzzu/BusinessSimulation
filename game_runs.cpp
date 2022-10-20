/*

This file contains a function that increments the number of times the game was run
by incrementing a number in visits.txt
-------------------------------------------------------------------------------------
PARAMETERS:
---> NONE
------------------------------------------------------------------------------------
RETURN VALUES:
---> NONE

*/
#include<fstream>
void increment_runs()
{
    std::fstream InFile("visits.txt");
    int visits;
    InFile>>visits;
    visits ++;
    InFile.close();
    std::fstream OutFile("visits.txt");
    OutFile<<visits;
    OutFile.close();
}
