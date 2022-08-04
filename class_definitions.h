	/*The class definitions the Business simulation. This file will declare all required classes. 
	The member functions will be defined in separate files */
#pragma once
#define TRANSACTION current_player->transactions.push_back
#include<iostream>
#include<vector>
using namespace std;

/* The class block is the base class of all tickets, general blocks.
	-------------------------------------------------------------------------------
	MEMBER VARIABLES:
	---> name of the block												(string)
	---> number of visits made to the block {by all players}			(int)
	---> type of block													(string)
	---> ticket cost													(int)
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

	//Default constructor for general blocks

	block()
	{
		block_type = "general";
		owner_num = -1;			//A geenral ticket is not owned by anyone.
	}

	//This is for colour tickets.

	block(string name, int ticket_cost, int basic_rent, int mortgage_value, bool colour, int house_costs, int house_rents[])
	{
		this->block_type = "ticket";
		this->name = name;
		this->ticket_cost = ticket_cost;
		this->basic_rent = basic_rent;
		this->current_rent = basic_rent;
		this->mortgage_value = mortgage_value;
		this->owner_num = -1;		//when a ticket is created, its not owned by anyone.
		this->colour = colour;
		this->house_cost = house_cost;
		this->number_of_houses = 0;
		for(int i=0; i<4; i++)
		{
			this->house_rents[i] = house_rents[i];
		}
	}

	//This is for white tickets. (Constructor overloading)
	block(string name, int ticket_cost, int basic_rent, int mortgage_value, bool colour)
	{
		this->name = name;
		this->ticket_cost = ticket_cost;
		this->basic_rent = basic_rent;
		this->mortgage_value = mortgage_value;
		this->colour = colour;
		this->owner_num = -1;		//when a ticket is created, its not owned by anyone.
		this->current_rent = basic_rent;
	}
};


/*The class UNO will have several member functions as well. 
  They will take care of transactions whenever a player enters UNO 
  ---------------------------------------------------------------------------------------
  PARAMETERS:
  ---> Player pointer vector							(vector<player *>)
  ---> A pointer to current player						(player *)
  ---> A reference to the number of players				(&int)
  ---> Pointer array of blocks							(block *[])
  ---------------------------------------------------------------------------------------
  RETURN VALUE:
  ---> NONE
*/


class UNO_class: public block
{	
	public:
	void UNO(vector<player *> players, player *current_player, block *arr[], int &number_of_players);
};


/*
	The class chance has a member function which carries out necessary tasks when a player
	eneter the chance block.
	------------------------------------------------------------------------------------------
	PARAMETERS:
	---> Pointer array of type players							(player *[])
	---> A pointer to current player							(playerr *)				
	---> A reference to Number of players 						(&int)
	---> An array of blocks										(block *[])
	------------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/


class chance_class: public block
{
	public:
	void transaction(player *pl[], player *current_player, int &number_of_players, block *blocks[], start_class &start);
};

/* the resort class contains a member function which debits 200*(number_of_players -1) from
	the current player's account and credits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: 
	---> A player pointer vector					(vector<player *>)
	---> Current player's pointer					(player *[])
	---> A reference to number of players			(&int)
	---> An array of blocks 						(block *[])
	----------------------------------------------------------------------------
	RETURN VALUE: 
	--->NONE
*/

class resort_class: public block
{
	public:
	void transaction(vector<player *> players,player *current_player,int &number_of_players, block *blocks[]);
};

/* the party house class contains a member function which credits 200*(number_of_players -1) from
	the current player's account and debits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: 
	---> A player pointer vector									(vector<player *>)
	---> Current player's pointer									(player *[])
	---> A reference to number of players							(&int)
	---> A pointer array of type block.								(block *[])
	----------------------------------------------------------------------------
	RETURN VALUE: 
	--->NONE
*/

class party_house_class: public block
{
	public:
	void transaction(vector<player *> players, player *current_player,int &number_of_players, block *blocks[]);
};

/* The jail class contains a member function which just debits 500 when the player enters 
	jail
	-------------------------------------------------------------------------------------
	PARAMETERS:
   ---> A pointer to player                     (player *)
   ---> A pointer array of blocks               (block *[])
   ---> A reference to the number of players    (&int)
   ---------------------------------------------------------------------------------------
   RETURN VALUE:
   ---> NONE
*/

class jail_class: public block
{
	public:
	void transaction(player *current_player, block *blocks[], int &number_of_players);
};


/* The start class checks if the player crossed the START and credits 2000 if he did.
	-----------------------------------------------------------------------------------
	PARAMETERS:
	---> pointer to the current player						(player *)
	---> Pointer of type block to the start object			(block *)
	-----------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

class start_class: public block
{
	public:
	void transaction(player *current_player, block *start);
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
	void transaction(player *current_player, int &number_of_players, block *blocks);
};

/*  The customs duty class contains a member function which deducts 50*(number of colour
	tickets owned by the player).
	--------------------------------------------------------------------------------------
	PARAMETERS:
	---> a pointer to the current player			(player *)
	---> A reference to the number of players.		(int &)
	---> An array of blocks 						(block *[])
	--------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/

class travelling_duty_class: public block
{
	public:
	void transaction(player *current_player, int &number_of_players, block *blocks[]);
};


				
   /*	PLAYER CLASS ATTRIBUTES
   ----------------------------------------------------------------------------------------

    MEMBER VARIABLES:
	1.) A vector of throws which will be appended everytime he/she throws.		(int vector)
	2.) A vector which keeps track of all his transactions						(int vector)
	3.) A variable which contains the number of blocks he covered 				(int)
	5.) A member variable which 
	8.) Balance of the player													(int)
	9.) Position of the player													(int)
	10.) A variable which contains the number of colour tickets					(int)							
	12.) A vector to keep track of the rounds player is in						(int vector)
	13.) Name of the player 													(string)
	14.) A variable which tells if a player is bankrupt 						(boolean)
	15.) A variable which tells the number of the player						(int)
	---------------------------------------------------------------------------------------
	MEMBER FUNCTIONS:
	
	1.) A parameterised constructor
		-----------------------------
		PARAMETERS:
		---> player number 		(int)
		---> initial balance	(int)
  
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
	int player_number;
	bool rent_elig;
	bool bankrupt;
	int throw_;
	int position;
	int balance;
	int round;
	int last_time_at_uno;
	int blocks_covered;
	std::string name;
	player(int player_number, int balance)
	{
		this->balance = balance;
		this->player_number = player_number;
		this->position = 0;
		this->round = 1;
		this->rent_elig = true;
		this->bankrupt = false;
		this->blocks_covered = 0;
		this->number_of_colour_tickets = 0;
	}
};

/*	The following function is called whenever a player buys or sells a white ticket.
	What is about?
	It is a function which checks and assigns double rents to white tickets
	-----------------------------------------------------------------------
	ARGUMENTS:
	--->A pointer array of blocks 		(block *[])
	--->A pointer to current player		(player *)
	-----------------------------------------------------------------------
	RETURN VALUE:
	--->NONE
*/

void white_double_rent(block *arr[], player *current_player);


/* 	The following function is an implementation of linear search algorithm
	-------------------------------------------------------------------------
	PARAMETERS: 
	---> A vector 							(vector<int>)
	---> integer search element				(int)
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
	---> A pointer to player					(player *)						
	---> A pointer array of type blocks			(player *[])
	---> A reference to the number of players	(&int)
	---------------------------------------------------------------------------------------
	RETURN VALUE:
	--->NONE
*/

void mortgage(player *current_player, block *blocks[], int &number_of_players);


/* The after_throw function updates the player position, rounds etc 
	---------------------------------------------------------------------------
	PARAMETERS:
	---> A pointer of type player*						(player)
	---> A pointer array of type blocks					(blocks)
	---> A reference to the number of players			(int)
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


/* 	The random boolean generator returns random booleans 
	------------------------------------------------------
	PARAMETERS:
	---> NONE
	------------------------------------------------------
	RETURN VALUE:
	---> A randomly generated boolean
*/


bool rand_bool();


/* 	The UNO_checker function will check if the player completed his 7 rounds after getting into 
	UNO and throwing 7
	--------------------------------------------------------------------------------------------
	PARAMETERS:
	---> A pointer to the current player
	--------------------------------------------------------------------------------------------
	RETURN VALUE:
	---> NONE
*/


void UNO_seven(player *current_player);


/* The rand throw function will generate two random dice throws and return their sum 
	----------------------------------------------------------------------------------
	PARAMETERS:
	---> NONE
	----------------------------------------------------------------------------------
	RETURN VALUE:
	---> INT
*/


int rand_throw();



	





