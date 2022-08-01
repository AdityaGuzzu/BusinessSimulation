	/*The class definitions the Business simulation. This file will declare all required classes. 
	The member functions will be defined in separate files */
#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/* The class block is the base class of all tickets, general blocks.
	-------------------------------------------------------------------------------
	MEMBER VARIABLES:
	---> name of the block												(string)
	---> number of visits made to the block {by all players}			(int)
	---> type of block													(string)
	--->ticket cost														(int)
	---> basic rent {one without any houses or double rent}				(int)
	---> current rent {one which describes the current rent.}			(int)
	---> mortgage value													(int)
	---> owner number {contains the number of the player who owns it}	(int)
	---> colour code {describes white or colour}						(int)
	---> number of houses												(int)
	---> array of house rents											(int)
	---> house cost														(int)
	--------------------------------------------------------------------------------
	MEMBER FUNCTIONS:
	---> NONE
*/


class block
{
	public:
	string name;
	int visits;
	string block_type;
	//tickets attributes:
	int ticket_cost;
	int basic_rent;
	int current_rent;
	int mortgage_value;
	int owner_num; 				
	bool colour;		//colour ticket if true, white if false
	int number_of_houses;
	int house_rents[4];
	int house_cost;
	void white_ticket(string ticket_name, int ticket_cost, int ticket_rent, int double_rent);
	//colour tickets attributes:


};


/*The class UNO will have several member functions as well. 
  They will take care of transactions whenever a player enters UNO 
  ---------------------------------------------------------------------------------------
  PARAMETERS:
  ---> Pointer array of type player
  ---> A reference to current player
  ---> Pointer array of type blocks
  ---> A reference to UNO object 
  ---------------------------------------------------------------------------------------
  RETURN VALUE:
  ---> NONE
*/


class UNO_class: public block
{	
	public:
	void UNO(player *pl_arr[], player &current_player, block *arr[], UNO_class &UNO);
};


/*
	The class chance has a member function which carries out necessary tasks when a player
	eneter the chance block.
	------------------------------------------------------------------------------------------
	PARAMETERS:
	---> Pointer array of type players
	---> A reference to current player
	---> Number of players 						(int)
	---> A reference to the CHANCE object
	------------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/


class chance_class: public block
{
	public:
	void transaction(player *pl[], player *current_player, chance_class &chance, int number_of_players, jail_class &jail, start_class &start);
};

/* the resort class contains a member function which debits 200*(number_of_players -1) from
	the current player's account and credits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: 
	--->A player pointer array
	---> Current player's pointer
	---> number of players			(int)
	---> A reference to the resort object
	----------------------------------------------------------------------------
	RETURN VALUE: 
	--->NONE
*/

class resort_class: public block
{
	public:
	void transaction(player *pl_arr[],player *current_player,int number_of_players, resort_class &resort);
};

/* the party house class contains a member function which credits 200*(number_of_players -1) from
	the current player's account and debits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: 
	---> A player pointer array
	---> Current player's pointer
	---> number of players			(int)
	---> A reference to the party house object.
	----------------------------------------------------------------------------
	RETURN VALUE: 
	--->NONE
*/

class party_house_class: public block
{
	public:
	void transaction(player *pl_arr[],player *current_player,int number_of_players, party_house_class &party_house);
};

/* The jail class contains a member function which just debits 500 when the player enters 
	jail
	-------------------------------------------------------------------------------------
	PARAMETERS: 
	---> A pointer to the current player 
	---> A referance to the Jail object
	-------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

class jail_class: public block
{
	public:
	void transaction(player *current_player, jail_class &jail);
};


/* The start class checks if the player crossed the START and credits 2000 if he did.
	-----------------------------------------------------------------------------------
	PARAMETERS:
	---> Reference to the current player
	---> Reference to the start object
	-----------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

class start_class: public block
{
	public:
	void transaction(player *current_player, start_class &start);
};

/*  The customs duty class contains a member function which deducts 100*(number of colour
	tickets owned by the player).
	--------------------------------------------------------------------------------------
	PARAMETERS:
	---> A pointer to the current player
	---> A reference to the customs duty object
	--------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

class customs_duty_class: public block
{
	public:
	void transaction(player *current_player, customs_duty_class &customs_duty);
};

/*  The customs duty class contains a member function which deducts 50*(number of colour
	tickets owned by the player).
	--------------------------------------------------------------------------------------
	PARAMETERS:
	---> a reference to the current player
	---> A reference to travelling duty class.
	--------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

class travelling_duty_class: public block
{
	public:
	void transaction(player *current_player, travelling_duty_class &travelling_duty);
};


				//PLAYER CLASS ATTRIBUTES
   /*	A player will have certain member functions and variables:
	1.) A vector of throws which will be appended everytime he/she throws.
	2.) A vector which keeps track of all his transactions
	3.) A vector which keeps track of all his positions (The ticket in which he is present)
	4.) A member function which always tells if the player crossed start or not. It'll return a boolean
	5.) A member function which returns a boolean if a person enters into UNO by throwing 7
	6.) A member variable which randomly decides to construct a house
	7.) A member variable which randomly generates numbers between 2 and 12 which acts as dice
	8.) Balance in the account of the player
	9.) Position of the player
	10.) Also a member function which only has colour tickets
	11.) A member function which has only white tickets 
	12.) A member variable which counts the number of rounds player crossed
	13.) A member variable which is true if the player has rent, false if he doesn't;
  
*/
class player
{
	public:
	std::vector<int> throws;
	std::vector<int> transactions;
	std::vector<int> rounds;
	std::vector<int> position_of_tickets_owned;
	std::vector<int> position_of_tickets_sold;
	int number_of_colour_tickets;
	int number_of_white_tickets;
	int player_number;
	bool UNO_seven(player &);
	bool rent_elig;
	bool uno_5000_pay;
	bool house_constructor;
	bool bankurupt;
	int throw_;
	int position;
	int balance;
	int round;
	int last_time_at_uno;
	int deduct_5000;
	int blocks_covered;
	std::string name;
};

/*	The following function is called whenever a player buys or sells a white ticket.
	What is about?
	It is a function which checks and assigns double rents to white tickets
	-----------------------------------------------------------------------
	ARGUMENTS:
	--->A pointer array of type blocks (all our blocks on the board)
	--->A pointer to current player
	-----------------------------------------------------------------------
	RETURN VALUE:
	--->NONE
*/

void white_double_rent(block *arr[], player *current_player);


/* 	The following function is an implementation of linear search algorithm
	-------------------------------------------------------------------------
	PARAMETERS: integer vector	(vector of positions of tickets owned by a player)
				integer search element
	-------------------------------------------------------------------------
	RETURN VALUE: 
	--->TRUE if the search element is found
	--->FALSE if the search element is not found
*/

bool search(vector<int>,int);


/* 	The following is the mortgage function which is called whenever the balance drops negative
	following a transaction.
	--------------------------------------------------------------------------------------
	PARAMETERS: 
	---> A reference to player
	---> The deficit amount
	---> A pointer array of type blocks
	---------------------------------------------------------------------------------------
	RETURN VALUE:
	--->NONE
*/

void mortgage(player *current_player,int deficit, block *blocks[]);


/* The after_throw function updates the player position, rounds etc 
	---------------------------------------------------------------------------
	PARAMETERS:
	---> A pointer of type player*
	---------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/
void after_throw(player *current_player);


/* 	The colour double rent function to set the double rents of the colour tickets:
	--------------------------------------------------------------------------------
	PARAMETERS:
	---> A pointer to the current player
	---> A pointer array of type blocks.
	--------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

void colour_double_rent(player *current_player, block *blocks[]);





