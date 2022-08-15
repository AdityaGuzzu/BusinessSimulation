/*The main file where actual simulation takes place */
#include "class_definitions.h"
#include "after_throw.cpp"
#include "chance.cpp"
#include "colour_double_rent.cpp"
#include "customs_duty.cpp"
#include "jail.cpp"
#include "mortgage.cpp"
#include "partyhouse.cpp"
#include "rand_throw.cpp"
#include "randbool.cpp"
#include "resort.cpp"
#include "start.cpp"
#include "travelling_duty.cpp"
#include "UNO.cpp"
#include "UNOseven.cpp"
#include "white_double_rent.cpp"
#include "randnum.cpp"
#include<cstdlib>
#include<ctime>
#define POSITION current_player->position
#define OWNER_NUMBER blocks[current_player->position]->owner_num
#define CURRENT_TICKET blocks[current_player->position]
/*      The steps required are broadly categorised into:
	1.) Get the number of players (maximum 8. Minimum 2)
	2.) Create all the blocks.
	3.) Create those many player objects through DMA.
	4.) Throw
	5.) Check if the player crossed start
	6.) Check if the player is in a ticket
			a.) If he is, check is its already bought or if he can buy
				aa) If it isn't bought, generate random boolean to buy the ticket or not
				ab) else, pay the rent
			b.) If he isn't, do the required transaction.
*/
int main()
{
	//Lets create the general blocks

	start_class start;
	UNO_class uno_4;
	resort_class resort;
	customs_duty_class customs_duty;
	chance_class chance_16;
	party_house_class party_house;
	travelling_duty_class travelling_duty;
	UNO_class uno_25;
	jail_class jail;
	chance_class chance_29;

	//Now lets create a pointer array of type blocks 			
	block *blocks[36];

	/* 	NOTE: I cannot initialise blocks using this method:
		block *blocks[] = {
			new block(....),
			new block(....)
		};

		This is because one of our parameters is an integer array. 
		So create objects one by one. Each time, write into a temp array the house rents
		of that particular ticket and pass it to the constructor as an argument.
	*/

	

	//Passing the address of start object as the first element
	blocks[0] = &start;
	start.name = "Start";

	//ENGLAND
	{
		//A temp array to store the house rents of tickets. 	(int arr)
		int house_rents[4] = {1700, 3400, 5100, 6100};
		blocks[1] = new block("England", 2500, 700, 3500, true, 7000, house_rents);
	}

	//IRAQ
	{
		int house_rents[4] = {1500, 3000, 4500, 5500};
		blocks[2] = new block("Iraq", 5000, 500, 2500, true, 5000, house_rents);
	}

	//WATERWAYS
	blocks[3] = new block("Waterways", 9500, 1400, 2000, false);

	//UNO_4
	blocks[4] = &uno_4;
	uno_4.name = "UNO";

	//FRANCE
	{
		int house_rents[4] = {1300, 2600, 3900, 4900};
		blocks[5] = new block("France", 2500, 300, 1250, true, 2500, house_rents);
	}
	
	//IRAN
	{
		int house_rents[6] = {1300, 2600, 3900, 4900};
		blocks[6] = new block("Iran", 2500, 300, 1250, true, 2500, house_rents);
	}

	//SATELLITE
	blocks[7] = new block("Satellite", 2000, 500, 1250, false);

	//EGYPT
	{
		int house_rents[4] = {1300, 2600, 3900, 4900};
		blocks[8] = new block("Egypt", 3200, 300, 1500, true, 3200, house_rents);
	}

	//RESORT
	blocks[9] = &resort;

	//CANADA
	{
		int house_rents[4] = {1400, 2800, 4200, 5200};
		blocks[10] = new block("Canada", 4000, 400, 2000, true, 4000, house_rents);
	}

	//GERMANY
	{
		int house_rents[4] = { 1400, 2800, 4200, 5200};
		blocks[11] = new block("Germany", 3500, 400, 1750, true, 3500, house_rents);
	}

	//AIRWAYS
	blocks[12] = new block("Airways", 10500, 1500, 5500, false);

	//CUSTOMS DUTY
	blocks[13] = &customs_duty;
	customs_duty.name = "Customs Duty";

	//SWITZERLAND
	{
		int house_rents[4] = {1700, 3400, 5100, 6100};
		blocks[14] = new block("Switzerland", 3500, 700, 3300, true, 6500, house_rents);
	}
	
	//BRAZIL
	{
		int house_rents[4] = {1300, 2600, 3900, 4900};
		blocks[15] = new block("Brazil", 2500, 300, 1250, true, 2500, house_rents);
	}

	//CHANCE
	blocks[16] = &chance_16;
	chance_16.name = "Chance";

	//ITALY
	{
		int house_rents[4] = {1200, 2400, 3600, 4600};
		blocks[17] = new block("Italy", 3500, 200, 1000, true, 2000, house_rents);
	}

	//PARTY HOUSE
	blocks[18] = &party_house;
	party_house.name = "Party House";

	//JAPAN
	{
		int house_rents[4] = {1250, 2500, 3750, 4750};
		blocks[19] = new block("Japan", 2500, 250, 1250, true, 2500, house_rents);
	}

	//USA
	{
		int house_rents[4] = {2000, 4000, 6000, 7000};
		blocks[20] = new block("USA", 8500, 1000, 5000, true, 8500, house_rents);
	}

	//TRAVELLING DUTY
	blocks[21] = &travelling_duty;
	travelling_duty.name = "Travelling Duty";

	//ROADWAYS
	blocks[22] = new block("Roadways", 3500, 800, 1800, false);

	//MEXCIO
	{
		int house_rents[4] = {1800, 3600, 5400, 6400};
		blocks[23] = new block("Mexico", 4000, 900, 2000, true, 4000, house_rents);
	}

	//HONG KONG
	{
		int house_rents[4] = {1200, 2400, 3600, 4600};
		blocks[24] = new block("Hong Kong", 2000, 200, 1000, true, 2500, house_rents);
	}

	//UNO
	blocks[25] = &uno_25;
	uno_25.name = "UNO";

	//AUSTRALIA
	{
		int house_rents[4] = {1400, 2800, 4200, 5200};
		blocks[26] = new block("Australia", 3300, 400, 2000, true, 3300, house_rents);
	}

	//JAIL
	blocks[27] = &jail;
	jail.name = "Jail";

	//INDIA
	{
		int house_rents[4] = {1550, 3100, 4650, 5650};
		blocks[28] = new block("India", 4500, 550, 2750, true, 5500, house_rents);
	}

	//CHANCE
	blocks[29] = &chance_29;
	chance_29.name = "Chance";

	//SAUDI ARABIA
	{
		int house_rents[4] = {1600, 3200, 4800, 5800};
		blocks[30] = new block("Saudi Arabia", 5500, 600, 2800, true, 5500, house_rents);
	}

	//PETROLEUM
	blocks[31] = new block("Petroleum", 5500, 500, 1300, false);

	//CHINA
	{
		int house_rents[4] = {1450, 2900, 4350, 5350};
		blocks[32] = new block("China", 4500, 450, 2250, true, 4500, house_rents);
	}

	//RAILWAYS
	blocks[32] = new block("Railways", 9500, 1500, 5000, false);
	
	//MALAYSIA
	{
		int house_rents[4] = {1200, 2400, 3600, 4800};
		blocks[34] = new block("Malaysia", 1500, 200, 800, true, 1500, house_rents);
	}

	//SINGAPORE
	{
		int house_rents[4] = {1300, 2600, 3900, 4900};
		blocks[35] = new block("Singapore", 3000, 300, 1500, true, 3000, house_rents);
	}

	//A variable to stor the number of players
	int num_of_players;

	//original number of players
	int org_num_of_players;

	//lets create a reference to number of players 
	int &num_of_players_ref = num_of_players;

	//Get the number of players
	std::cout<<"Enter the number of players";

	get_players:
	try
	{
		std::cin>>num_of_players;
		if(num_of_players > 8 || num_of_players <2)
		{
			throw num_of_players;
		}
		org_num_of_players = num_of_players;
	}

	catch(int)
	{
		cerr<<"\nEnter correct number of players. The maximum limit of players is 8 and the minimum is 2.";
		goto get_players;
	}
	
	//Create a pointer array of size 'number of players'
	std::vector<player *> players;

	for(int i=0; i<num_of_players; i++)
	{
		//Players will divide among themselves $100000
		players.push_back(new player(i,(100000/num_of_players)));
	} 

	//space enhancement
	players.shrink_to_fit();
	
	//Simulation starts.
	//int j=0;
	while(num_of_players > 1)
	{
		for(int this_player =0; this_player<org_num_of_players; this_player++)
		{
			//to make the program more readable
			player *current_player = players[this_player];
			std::cout<<std::endl<<"-------------------------------------------------------------------";
			std::cout<<std::endl<<"Player number: "<<this_player+1;
			

			//If the player is bankrupt
			if(current_player->bankrupt)
			{
				//move to the next iteration
				continue;
			}

			//throw
			current_player->throw_ = rand_throw(current_player->blocks_covered);

			//Update all throw related variables and vectors
			after_throw(current_player);
			std::cout<<std::endl<<"Player is in :"<<blocks[current_player->position]->name;
			std::cout<<"\n\nBlocks Covered = "<<current_player->blocks_covered;
			std::cout<<endl<<"Throw: "<<current_player->throw_;

			//Call the start function
			start.transaction(current_player,blocks[0]);

			//if player is not eligible for rent
			if(!current_player->rent_elig)
			{
				UNO_seven(current_player);
			}

		
			//For general blocks
			if(blocks[current_player->position]->block_type == "general")
			{
				//We don't need to call the start transcation function as its called immediately after the throw of dice.

				//if position is UNO_4
				if(POSITION == 4)
				{
					uno_4.UNO(players,current_player,blocks,num_of_players_ref);
				}

				//If position is resort
				if(POSITION == 9)
				{
					resort.transaction(players, current_player, num_of_players_ref, blocks);
				}

				//If position is customs duty
				if(POSITION == 13)
				{
					customs_duty.transaction(current_player,num_of_players_ref, blocks);
				}

				//If position is chance
				if(POSITION == 16)
				{
					chance_16.transaction(players,current_player,num_of_players_ref,blocks);
				}

				//If position is party house
				if(POSITION == 18)
				{
					party_house.transaction(players,current_player,num_of_players_ref,blocks);
				}

				//If position is Travelling Duty
				if(POSITION == 21)
				{
					travelling_duty.transaction(current_player,num_of_players_ref,blocks);
				}

				//if position is UNO25
				if(POSITION == 25)
				{
					uno_25.UNO(players,current_player, blocks, num_of_players_ref);
				}

				//If position is JAIL
				if(POSITION == 27)
				{
					jail.transaction(current_player,blocks,num_of_players_ref);
				}

				//If positon is Chance29
				if(POSITION == 29)
				{
					chance_29.transaction(players,current_player,num_of_players_ref,blocks);
				}
			}

			//for tickets
			else
			{
				//check if the ticket is bought by someone else
				if(OWNER_NUMBER != -1 && OWNER_NUMBER != current_player->player_number)
				{
					//debit the money from current player
					current_player->balance -= CURRENT_TICKET->current_rent;
					std::cout<<std::endl<<"Paid "<<CURRENT_TICKET->current_rent<<" to player number "<<OWNER_NUMBER+1;
					TRANSACTION((-1)*CURRENT_TICKET->current_rent);
					mortgage(current_player, blocks, num_of_players_ref);

					//credit the money to the respective player
					players[CURRENT_TICKET->owner_num]->balance += CURRENT_TICKET->current_rent;
					players[CURRENT_TICKET->owner_num]->transactions.push_back(CURRENT_TICKET->current_rent);
				}

				//If no one owns the ticket, the player can buy it
				else
				{
					//If the player has enough money, the decision is taken randomly
				
					if(rand_bool(current_player->blocks_covered) && ((current_player->balance) > (blocks[POSITION]->ticket_cost)) && OWNER_NUMBER != current_player->player_number)
					{
						std::cout<<std::endl<<"Current player's position is "<<current_player->position;
						//debit the ticket price from the player's balance
						current_player->balance -= blocks[POSITION]->ticket_cost;

	

						//setting the owner number of the ticket to the player number
						blocks[POSITION]->owner_num = current_player->player_number;

						//Adding the position to the position of tickets owned by the player
						current_player->position_of_tickets_owned.push_back(POSITION);

						//if the ticket bought is a colour one:
						if(blocks[POSITION]->colour)
						{
							colour_double_rent(current_player,blocks);
							current_player->number_of_colour_tickets ++;
						}

						//else, the ticket is white
						else
						{
							white_double_rent(blocks, current_player);
						}

					}
				}

				//Time to construct houses:
				#define TICKET_ITER blocks[current_player->position_of_tickets_owned[j]]

				//rand bool has an integer as an argument so we just pass a random integer like blocks covered which has no relevance to the program
				while(rand_bool(current_player->blocks_covered) && (current_player->number_of_colour_tickets > 0))
				{
						
						//We will generate a random number between [0,number of tickets owned by the player)
						int j = randnum(current_player->position_of_tickets_owned.size());

						if(!(TICKET_ITER->colour) || TICKET_ITER->number_of_houses == 4 || current_player->balance < TICKET_ITER->house_cost)
						{
							continue;
						}
						
						else
						{
						current_player->balance -= TICKET_ITER->house_cost;
						std::cout<<std::endl<<"House constructed in "<<TICKET_ITER->name;
						TICKET_ITER->number_of_houses ++;
						TICKET_ITER->current_rent =TICKET_ITER->house_rents[TICKET_ITER->number_of_houses - 1];
						}
								
						
				}
				
			}

			
			std::cout<<endl<<"Balance: "<<current_player->balance;
			std::cout<<endl<<"Tickets Owned:\n ";
			for(int k=0;k<current_player->position_of_tickets_owned.size(); k++)
			{
				std::cout<<"\t"<<blocks[current_player->position_of_tickets_owned[k]]->name;
			}	
		}	
	}
	
	std::cout<<"---------------------------------------------------------------------------"<<std::endl<<"GAME ENDED";
	//deleting pointers
	for(int i=0; i<36; i++)
	{
		delete blocks[i];
	}

	for(int i=0; i<players.size(); i++)
	{
		delete players[i];
	}
	
}