	/*The class definitions the Business simulation. This file will define all required classes. The member functions
	will be defined in separate files */
#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
/* We will use the concepts of OOP. All the tickets will be objects of the ticket class. We will furthur have child
   classes as colour tickets and white tickets. 
	Member variables and functions of the parent class include:
	1.) Ticket name  
	2.) Ticket Rent  
	3.) House cost
	4.) Mortgage value
	5.) A static variable to keep track of the number of times anyone came into it
	6.) A variable to know who owns the ticket (i.e the player number)
	7.) A variable to know how much rent was paid to the owner of the ticket. This helps to analyse the 
	   best ticket
	8.) Number of hosues
	9.) A colour code to determine if its a colour or white ticket
*/

class block
{
	public:
	string name;
	int visits;
	string block_type;
};

class ticket: public block
{
	public:
	int ticket_cost;
	int basic_rent;
	int current_rent;
	int mortgage_value;
	int owner_num; 				//to know who owns the ticket
	int colour_code; 			// 1 if colour, -1 if white
	virtual void set_val();     //This function will set the values of variables required as per the type of ticket
};

//Ticket class has attributes which are common to both colour and white tickets

class colour_ticket: public ticket
{
	private:
	enum ticket_colour {red,green,blue,yellow};
	public:
	bool colour = true;
	bool double_rent_checker;
	ticket_colour colour;
	int number_of_houses;
	int house_rents[4];
	int house_cost;
	colour_ticket(string ticket_name, int ticket_cost, int ticket_rent, int house_cost, int mortgage_value, int house_rents[4], int double rent,int colour_code);	
};

class white_ticket: public ticket
{
	private:
	enum white_ticket_pair {SW,AP,RR};
	public:
	bool colour = false;
	white_ticket_pair pair;
	white_ticket(string ticket_name, int ticket_cost, int ticket_rent, int double_rent);
};

/*The class UNO will have several member functions as well. 
  They will take care of transactions whenever a player enters UNO */


class UNO_class: public block
{	
	public:
	/*NOTE: We can omit the throw parameter if we call the function after updating throw in the player class */
	void UNO(player *pl_arr[], player *current_player,int throw__, block *arr[]);
};

class chance_class: public block
{
	public:
	void chance_transaction(player *pl,int number_of_players);
};

/* the resort class contains a member function which debits 200*(number_of_players -1) from
	the current player's account and credits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: A player pointer array, Current player's pointer, number of players
	----------------------------------------------------------------------------
	RETURN VALUE: NONE
*/

class resort_class: public block
{
	public:
	void transaction(player *pl_arr[],player *current_player,int number_of_players);
};

/* the party house class contains a member function which credits 200*(number_of_players -1) from
	the current player's account and debits 200 in all other accounts 
	----------------------------------------------------------------------------
	ARGUMENTS: A player pointer array, Current player's pointer, number of players
	----------------------------------------------------------------------------
	RETURN VALUE: NONE
*/

class party_house_class: public block
{
	public:
	void transaction(player *pl_arr[],player *current_player,int number_of_players);
};

/* The jail class contains a member function which just debits 500 when the player enters 
	jail */

class jail_class: public block
{
	public:
	void transaction(player &x);
};


/* The start function checks if the player crossed start. If he did, it credits 2000
	--------------------------------------------------------------------------------
	ARGUMENTS: A reference of current player 
	--------------------------------------------------------------------------------
	RETURN VALUE: NONE
*/


class start_class: public block
{
	public:
	void transaction(player &current_player);
};

class customs_duty_class: public block
{
	public:
	void transaction(player *current_player);
};

class travelling_duty_class: public block
{
	public:
	void transaction(player *current_player);
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
	std::vector<int> positions;
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
	std::string name;
	void after_throw(player &x, int throw__);
	
};

/*	The following function is called whenever a player buys or sells a white ticket.
	What is about?
	It is a function which checks and assigns double rents to white tickets
	-----------------------------------------------------------------------
	ARGUMENTS:
	1.) A pointer array of type blocks (all our blocks on the board)
	2.) A refernace to current player
	-----------------------------------------------------------------------
	RETURN VALUE:
	NONE
*/

void white_double_rent(block *arr[], player &current_player);


/* 	The following function is an implementation of linear search algorithm
	-------------------------------------------------------------------------
	PARAMETERS: integer vector	(vector of positions of tickets owned by a player)
				integer search element
	-------------------------------------------------------------------------
	RETURN VALUE: 
		TRUE if the search element is found
		FALSE if the search element is not found
*/

bool search(vector<int>,int);

