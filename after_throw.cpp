/*  ALGORITHM:
    ---> generate a random number between 2 and 12
    ---> assign it to throw_ variable of current player
    ---> append throw_ to current player's throws vector
    ---> current player's position = ( (position + throw_) % 36 )
    ---> add throw_ to the last element of positions vector and append that to positions vector. 
    ---> append ( (last element of positions vector) /36 ) to rounds vector
*/
    