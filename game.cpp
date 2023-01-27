/*The main file where actual simulation takes place */
#include "transaction_ID.cpp"
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
#include "block_transactions.cpp"
#include "ticket_visits.cpp"
#include "net_transaction.cpp"
#include "net_transaction_into_CSV.cpp"
#include "erase_local_data.cpp"
#include "house_and_level_wise_trans.cpp"
#include "update_local_IR_ratio.cpp"
#include "game_runs.cpp"
#include "total_players_money.cpp"
#include "highest_assets.cpp"
#include "update_local_house_wise_IR.cpp"
#include "update_house_wise_inv_ret.cpp"
#include "update_local_I_and_R.cpp"
#include<cstdlib>
#include<fstream>
#include<ctime>
#define POSITION current_player->position
#define OWNER_NUMBER blocks[current_player->position]->owner_num
#define CURRENT_TICKET blocks[current_player->position]
const int total_bank_money = 166500;

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
	//Number of times the user wants to simulate
	int number_of_simulations;

	std::cout<<"How many times do you want to simulate? ";
	std::cin>>number_of_simulations;
	//A variable to store the number of players
	int num_of_players;

	//Get the number of players
	cout<<"Enter the number of players";

	//original number of players
	int org_num_of_players;

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

	for(int sim_var=0;sim_var<number_of_simulations;sim_var++)
	{
	num_of_players = org_num_of_players;
	
	//open the output file
	std::fstream out("output.txt",std::ios::out);

	//a reference to number of players 
	int &num_of_players_ref = num_of_players;

/*
	Simulating multiple times
*/

	//Lets create the general blocks

	start_class *start = new start_class;
	UNO_class *uno_4 = new UNO_class;
	resort_class *resort = new resort_class;
	customs_duty_class *customs_duty = new customs_duty_class;
	chance_class *chance_16 = new chance_class;
	party_house_class *party_house =  new party_house_class;
	travelling_duty_class *travelling_duty =  new travelling_duty_class;
	UNO_class *uno_25 = new UNO_class;
	jail_class *jail = new jail_class;
	chance_class *chance_29 = new chance_class;

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
	blocks[0] = start;
	start->name = "Start";

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
	blocks[4] = uno_4;
	uno_4->name = "UNO4";

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
	blocks[9] = resort;
	resort->name = "Resort";

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
	blocks[13] = customs_duty;
	customs_duty->name = "Customs Duty";

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
	blocks[16] = chance_16;
	chance_16->name = "Chance16";

	//ITALY
	{
		int house_rents[4] = {1200, 2400, 3600, 4600};
		blocks[17] = new block("Italy", 3500, 200, 1000, true, 2000, house_rents);
	}

	//PARTY HOUSE
	blocks[18] = party_house;
	party_house->name = "Party House";

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
	blocks[21] = travelling_duty;
	travelling_duty->name = "Travelling Duty";

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
	blocks[25] = uno_25;
	uno_25->name = "UNO25";

	//AUSTRALIA
	{
		int house_rents[4] = {1400, 2800, 4200, 5200};
		blocks[26] = new block("Australia", 3300, 400, 2000, true, 3300, house_rents);
	}

	//JAIL
	blocks[27] = jail;
	jail->name = "Jail";

	//INDIA
	{
		int house_rents[4] = {1550, 3100, 4650, 5650};
		blocks[28] = new block("India", 4500, 550, 2750, true, 5500, house_rents);
	}

	//CHANCE
	blocks[29] = chance_29;
	chance_29->name = "Chance29";

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
	blocks[33] = new block("Railways", 9500, 1500, 5000, false);
	
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
	

	//Create a pointer array of size 'number of players'
	std::vector<player *> players;

	for(int i=0; i<num_of_players; i++)
	{
		//Players will divide among themselves $100000
		players.push_back(new player(i,(100000/num_of_players)));
	} 

	//space enhancement
	players.shrink_to_fit();

	//Total Money of all the players. Shouldn't exceed the total amount the bank has
	
	//Simulation starts.
	//int j=0;
	while(num_of_players > 1  && total_players_money(players) < total_bank_money)
	{
		for(int this_player =0; this_player<org_num_of_players && num_of_players > 1; this_player++)
		{
			//to make the program more readable
			player *current_player = players[this_player];
			out<<'\n'<<"-------------------------------------------------------------------";
			out<<'\n'<<"Player number: "<<this_player+1;
			

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
			out<<'\n'<<"Throw: "<<current_player->throw_;
			out<<'\n'<<"Player is in : "<<blocks[current_player->position]->name;
			out<<'\n'<<"Blocks Covered = "<<current_player->blocks_covered;
			cout.flush();
			

			//Increment the visits of the block
			blocks[current_player->position]->visits++;
			
			//Call the start function
			start->transaction(current_player,blocks[0]);

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
					uno_4->UNO(players,current_player,blocks,org_num_of_players,num_of_players_ref);
				}

				//If position is resort
				if(POSITION == 9)
				{
					resort->transaction(players, current_player, org_num_of_players,num_of_players_ref, blocks);
				}

				//If position is customs duty
				if(POSITION == 13)
				{
					customs_duty->transaction(current_player,num_of_players_ref, blocks);
				}

				//If position is chance
				if(POSITION == 16)
				{
					chance_16->transaction(players,current_player,org_num_of_players,num_of_players_ref,blocks);
				}

				//If position is party house
				if(POSITION == 18)
				{
					party_house->transaction(players,current_player,org_num_of_players,num_of_players_ref,blocks);
				}

				//If position is Travelling Duty
				if(POSITION == 21)
				{
					travelling_duty->transaction(current_player,num_of_players_ref,blocks);
				}

				//if position is UNO25
				if(POSITION == 25)
				{
					uno_25->UNO(players,current_player, blocks,org_num_of_players,num_of_players_ref);
				}

				//If position is JAIL
				if(POSITION == 27)
				{
					jail->transaction(current_player,blocks,num_of_players_ref);
				}

				//If positon is Chance29
				if(POSITION == 29)
				{
					chance_29->transaction(players,current_player,org_num_of_players,num_of_players_ref,blocks);
				}
			}

			
			//for buying tickets/paying rents
			else
			{
				//check if the ticket is bought by someone else
				if(OWNER_NUMBER != -1 && OWNER_NUMBER != current_player->player_number)
				{
					
					//debit the money from current player
					current_player->balance -= CURRENT_TICKET->current_rent;
					
					out<<std::endl<<"Paid "<<CURRENT_TICKET->current_rent<<" to player number "<<OWNER_NUMBER+1<<std::endl;
					
					//appending the rent to the CSV file of the respective ticket
					CURRENT_TICKET->transaction(CURRENT_TICKET->current_rent);

					//Appending the rent to the transactions vector
					CURRENT_TICKET->transactions.push_back(CURRENT_TICKET->current_rent);

					//append the transaction to the house wise trans 
					CURRENT_TICKET->house_wise_return[CURRENT_TICKET->number_of_houses] += CURRENT_TICKET->current_rent;

					//Adding the amount to the ticket wise net trans based on wheather the ticket is white or colour
					if(CURRENT_TICKET->colour)
					{
						CURRENT_TICKET->house_wise_net_trans[CURRENT_TICKET->number_of_houses] += CURRENT_TICKET->current_rent;
					} 

					else
					{

						if(CURRENT_TICKET->current_rent == CURRENT_TICKET->basic_rent)
						{
							CURRENT_TICKET->house_wise_net_trans[0] += CURRENT_TICKET->current_rent;
						}
						
						else
						{
							CURRENT_TICKET->house_wise_net_trans[1] += CURRENT_TICKET->current_rent;
						}
					}

					
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
						out<<std::endl<<"CHECK----"<<std::endl;
						
						//debit the ticket price from the player's balance
						current_player->balance -= blocks[POSITION]->ticket_cost;


						//setting the owner number of the ticket to the player number
						CURRENT_TICKET->owner_num = current_player->player_number;

						//Adding the position to the position of tickets owned by the player
						current_player->position_of_tickets_owned.push_back(POSITION);

						//Appending the cost to the CSV file of the particular ticket
						CURRENT_TICKET->transaction(-CURRENT_TICKET->ticket_cost);

						//Appending the cost to the transactions vector
						CURRENT_TICKET->transactions.push_back(-CURRENT_TICKET->ticket_cost);

						//Appending the cost to the house wise transactions vector
						CURRENT_TICKET->house_wise_investment[CURRENT_TICKET->number_of_houses] += blocks[POSITION]->ticket_cost;

						//Appending the cost to house wise net transaction array
						CURRENT_TICKET->house_wise_net_trans[0] -= CURRENT_TICKET->ticket_cost;

						//if the ticket bought is a colour one:
						if(CURRENT_TICKET->colour)
						{
							
							colour_double_rent(current_player,blocks);
							current_player->number_of_colour_tickets ++;
						}

						//else,if the ticket is white
						else
						{
							white_double_rent(blocks, current_player);
						}

					}
				}

				//Time to construct houses:
				#define TICKET_ITER blocks[current_player->position_of_tickets_owned[randpos]]

				//rand bool has an integer as an argument so we just pass a random integer like blocks covered which has no relevance to the program
				while(rand_bool(current_player->blocks_covered) && (current_player->number_of_colour_tickets > 0) && !current_player->bankrupt)
				{
						
						//We will generate a random number between [0,number of tickets owned by the player)
						int randpos = randnum(current_player->position_of_tickets_owned.size());

						if(!(TICKET_ITER->colour) || TICKET_ITER->number_of_houses == 4 || current_player->balance < TICKET_ITER->house_cost)
						{
							continue;
						}
						
						else
						{
						current_player->balance -= TICKET_ITER->house_cost;
						out<<std::endl<<"House constructed in "<<TICKET_ITER->name;

						/*
							House constructed,update the house_wise_IR ratio 
						*/

						TICKET_ITER->house_wise_IR_ratio[TICKET_ITER->number_of_houses] = (float)(TICKET_ITER->house_wise_return[TICKET_ITER->number_of_houses]-TICKET_ITER->house_wise_investment[TICKET_ITER->number_of_houses])/TICKET_ITER->house_wise_investment[TICKET_ITER->number_of_houses];

						//Updating the number of houses
						TICKET_ITER->number_of_houses ++;

						//Updating it in the house wise investment vector
						TICKET_ITER->house_wise_investment[TICKET_ITER->number_of_houses] += TICKET_ITER->house_cost;

						//Updating the current rent
						TICKET_ITER->current_rent =TICKET_ITER->house_rents[TICKET_ITER->number_of_houses - 1];

						//Appending the house cost to  the CSV file of the ticket
						TICKET_ITER->transaction(-TICKET_ITER->house_cost);

						//Appending the house cost to the transanctions vector
						TICKET_ITER->transactions.push_back(-TICKET_ITER->house_cost);

						//Appending the house cost to the ticket wise net transaction array
						TICKET_ITER->house_wise_net_trans[TICKET_ITER->number_of_houses] -= TICKET_ITER->house_cost;
						
						}						
				}	
			}

			if(current_player->bankrupt)
			{
				out<<"\nPlayer number "<<current_player->player_number + 1<<" is bankrupt";
			}
			
			out<<std::endl<<"Balance: "<<current_player->balance;
			out<<std::endl<<"Number of throws = "<<current_player->throws.size()<<std::endl;
			out<<std::endl<<"Tickets Owned:\n ";
			for(int k=0;k<current_player->position_of_tickets_owned.size(); k++)
			{
				out<<"\t"<<blocks[current_player->position_of_tickets_owned[k]]->name;
			}	
			out<<std::endl<<"Transaction Number: "<<transaction_ID;
		}	
	}

	/*We need to calculate the total assets of the players to declare 
	 the winner when the total money among the players exceeds the set limit
	*/
	out<<'\n'<<"---------------------------------------------------------------------------"<<std::endl<<"GAME ENDED";
	out<<'\n'<<highest_assets(players,blocks)->player_number +1<<" is the winner";

	/* 	The IR ratios of ticets are updated only after bankurupcy and 
		constructing a house. So we need to update them now.
	*/
	for(int iter = 0; iter<36; iter++)
	{
		block *current_block = blocks[iter];
		int number_of_houses = blocks[iter]->number_of_houses;
		if(current_block->colour)
		{
			current_block->house_wise_IR_ratio[number_of_houses] = (float)(current_block->house_wise_return[number_of_houses]-current_block->house_wise_investment[number_of_houses])/current_block->house_wise_investment[number_of_houses];
		}
	}


	//Incrementing the number of times game was run
	increment_runs();

	
	//Appending the number of visits of each blocks to the CSV file
	visits_func(blocks);
	
	
	//Appending the net transaction values to the CSV file
	net_trans_into_CSV(blocks);


	//Appending the net house and level wise transactions
	house_and_level__wise_trans(blocks);
	
	//Update the local IR ratio
	update_local_IR_ratio(blocks);
	
	//update Local House Wise IR
	update_local_colour_wise_IR(blocks);

	//update Local house_wise_investment and house_wise_return ratio
	update_house_wise_investment_and_return(blocks);

	//update the total local investment and returns
	update_total_investment_and_return(blocks);

	//Update the global data
	system("python global_data_ops/update_global_data.py");
	
	//check the transaction vector of all tickets 
	for(int i=0; i<36;i++)
	{
		std::fstream OutFile("transactions.txt",std::ios::app);
		int sum=0;
		for(int trans:blocks[i]->transactions)
		{
			sum+=trans;
		}
		OutFile<<blocks[i]->name<<','<<sum<<'\n';
	}

	//deleting the local data to save space
	erase_local_data(blocks);

	 //deleting pointers
	for(int i=0; i<36; i++)
	{
		delete blocks[i];
	} 
	

	players.erase(players.begin(),players.end());

	}

	return 0;
} 

