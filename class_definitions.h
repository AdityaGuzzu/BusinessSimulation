/*The class definitions the Business simulation. This file will define all required classes */
#pragma
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
typedef pl[player_num] = current_player;
typedef current_player->balance = current_balance;
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
};

class ticket: private block
{
	public:
	string ticket_name;
	int ticket_cost;
	int ticket_rent;
	int mortgage_value;
	int number_of_houses;
	int hotel = 0;
	int number_of_appears = 0;  //to keep track of the number of times anyone came into it
	int owner_num; //to know who owns the ticket
	int double_rent;
	int colour_code; // 1 if colour, -1 if white
	virtual void set_val(){}    //This function will set the values of variables required as per the type of ticket
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
	int current_rent;
	colour_ticket(string ticket_name,int ticket_cost,int ticket_rent, int house_cost, int mortgage_value, int house_rents[4], int double rent,int colour_code);	
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

/* 	The class UNO will have several member functions as well. They will take care of transactions whenever a player
	enters UNO


class UNO_class: private ticket
{		
};

class chance_class: private block
{
	private:
	int i;

	public:
	void chance_transaction(player *pl,int player_num,int number_of_players);
};

class resort_class: private block
{
	
};

class party_house_class: private block
{	
};

class jail_class: private block
{
};

class start_class: private block
{
};

class customs_duty_transactions: private blocks
{
};

class travelling_duty_transactions: private blocks
{
};


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
	std::vector<std::string> tickets;
	std::vector<std::string> colour_tickets;
	std::vector<std::string> white_tickets;
	//bool crossed_start(player &);   (see if i need this later)
	bool UNO_seven(player &);
	bool rent_elig;
	bool uno_5000_pay;
	bool house_constructor;
	int throw_;
	int position;
	int balance;
	int round;
	int last_time_at_uno;
	int deduct_5000;
};