/*  This file contains a function which helps to search for an element in an integer vector
    PARAMETERS: int vector, int search_element
    --------------------------------------------------------------------------------------
    RETURN VALUE: 
                TRUE if the search_element is found
                FALSE if the search_element is not found
    --------------------------------------------------------------------------------------
    ALGORITHM:
    ---> create a loop variable i
    ---> create a boolean variable b_val
    ---> initialize i = 0
    ---> initialize b_val = false
    ---> WHILE i < vector.size()
        --->IF vector[i] == search_element
            ---> b_val = true
            ---> break
        ---> i++
    ---> return b_val

    -----------------------------------------------------------------------------------------
*/

#include<iostream>
#include "class_definitions.h"
using namespace std;
bool search(vector<int> tickets_position, int position)
{
    bool ret_val = false;
    for(int i = 0; i< tickets_position.size();i++)
    {
        if(tickets_position[i] == position)
        {
            ret_val = true;
            break;
        }
    }
    return ret_val;
}