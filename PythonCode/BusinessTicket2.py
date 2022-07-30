''''
First importing all the modules needed to simulate Business.
'''''
import random
from BusinessBoard.listchecker import *
from BusinessBoard.UNOandCHANCE import *
from BusinessBoard.only_colour_tickets import *
from BusinessBoard.Rent import *
from BusinessBoard.Rent import current_rent_of_all_tickets
import matplotlib.pyplot as plt
'''''
There are a set of lists which need to be present in order for us to create the program.
All the required lists are declared here
'''''

# A list of tickets
tickets = ["Start", "England", "Iraq", "Waterways", "UNO", "France", "Iran", "Satellite", "Egypt", "Resort", "Canada",
           "Germany", "Airways", "Customs duty", "Switzerland", "Brazil", "Chance", "Italy", "Party House", "Japan",
           "USA", "Travelling Duty", "Roadways", "Mexico", "Hong Kong", "UNO", "Australia", "Jail", "India", "Chance",
           "Saudi Arabia", "Petroleum", "China", "Railways", "Malaysia", "Singapore"]
current_rents = {}
ticket_prices = [0, 2500, 5000, 9500, 0, 2500, 2500, 2000, 3200, 0, 4000, 3500, 10500, 0, 3500, 2500, 0, 3500,
                 0, 2500, 8500, 0, 3500, 4000, 2000, 0, 3300, 0, 4500, 0, 5500, 5500, 4500, 9500, 1500, 3000]
original_ticket_rents = [0, 700, 500, 1400, 0, 300, 300, 500, 300, 0, 400, 400, 1500, 0, 700, 300, 0, 200, 0, 250, 1000,
                         0, 800, 900, 200, 0, 400, 0, 550, 0, 600, 500, 450, 1500, 200, 300]
current_ticket_rents = [0, 700, 500, 1400, 0, 300, 300, 500, 300, 0, 400, 400, 1500, 0, 700, 300, 0, 200, 0, 250, 1000,
                        0, 800, 900
    , 200, 0, 400, 0, 550, 0, 600, 500, 450, 1500, 200, 300]
double_rents = [0, 1400, 100, 2400, 0, 600, 600, 1000, 600, 0, 800, 800, 2500, 0, 1400, 600, 0, 400, 0, 500, 2000, 0,
                1500, 1800, 400, 0, 800, 0, 1100, 0, 1200, 1000, 900, 2500, 400, 600]
list_of_house_prices = [0, 7000, 5000, 0, 0, 2500, 2500, 0, 3200, 0, 4000, 3500, 0, 0, 6500, 2500, 0, 2000, 0, 2500,
                        8500,0, 0, 4000, 2500, 0, 3300, 0, 5500, 0, 5500, 0, 4500, 0, 1500, 3000]
# a dictionary of house prices
dict_of_house_prices = {'England': 7000,
                        'Iraq': 5000,
                        'France': 2500,
                        'Iran': 2500,
                        'Egypt': 3200,
                        'Canada': 4000,
                        'Germany': 3500,
                        'Switzerland': 6500,
                        'Brazil': 2500,
                        'Italy': 2000,
                        'Japan': 2500,
                        'USA': 8500,
                        'Mexico': 4000,
                        'Hong Kong': 2500,
                        'Australia': 3300,
                        'India': 5500,
                        'Saudi Arabia': 5500,
                        'China': 4500,
                        'Malaysia': 1500,
                        'Singapore': 3000}
# lists of house rents
first_house_rents = [0, 1700, 1500, 0, 0, 1300, 1300, 0, 1300, 0, 1400, 1400, 0, 0, 1700, 1300, 0, 1200, 0, 1250, 2000,
                     0, 0,
                     1800, 1200, 0, 1400, 0, 1550, 0, 1600, 0, 1450, 0, 1200, 1300]
second_house_rents = [0, 3400, 300, 0, 0, 2600, 2600, 0, 2600, 0, 2800, 2800, 0, 0, 3400, 2600, 0, 2400, 0, 2500, 4000,
                      0, 0, 3600, 2400, 0, 2800, 0, 3100, 0, 3200, 0, 2900, 0, 2400, 2600]
third_house_rents = [0, 5100, 4500, 0, 0, 3900, 3900, 0, 3900, 0, 4200, 4200, 0, 0, 5100, 3900, 0, 3600, 0, 3750, 6000,
                     0
    , 0, 5400, 3900, 0, 4200, 0, 4550, 0, 4800, 0, 4350, 0, 3600, 3900]
hotel_rents = [0, 6100, 5500, 0, 0, 4900, 4900, 0, 4900, 0, 5200, 5200, 0, 0, 6100, 4900, 0, 4600, 0, 4750, 8000,
               0, 0, 6400, 4900, 0, 5200, 0, 5500, 0, 5800, 0, 5350, 0, 4600, 4900]
# list of mortgage prices
list_of_mortgage_prices = [0, 3500, 2500, 2000, 1250, 1250, 1250, 1500, 0, 2000, 1750, 5500, 3300, 1300, 0, 1000, 0,
                           1250, 5000, 0, 1800, 2000, 1000, 0, 2000, 0, 2750, 0, 2800, 1300, 2250, 5000, 800, 1500]

''''A list where each index represents the number of houses in that ticket'''

list_of_number_of_houses = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

# dict of mortgage prices
dict_of_mortgage_prices = {'England': 3500,
                           'Iraq': 2500,
                           'France': 1250,
                           'Iran': 1250,
                           'Satellite': 1250,
                           'Egypt': 1500,
                           'Canada': 2000,
                           'Germany': 1750,
                           'Airways': 5500,
                           'Switzerland': 3300,
                           'Brazil': 1300,
                           'Italy': 1000,
                           'Japan': 1250,
                           'USA': 5000,
                           'Roadways': 1800,
                           'Mexico': 2000,
                           'Hong Kong': 1000,
                           'Australia': 2000,
                           'India': 2750,
                           'Saudi Arabia': 2800,
                           'Petroleum': 1300,
                           'China': 2250,
                           'Railways': 5000,
                           'Malaysia': 800,
                           'Singapore': 1300}

# This is a list of white tickets
list_of_while_tickets = ['Waterways', 'Satellite', 'Airways', 'Petroleum', 'Roadways', 'Railways']

# a list to count the rounds in case of UNO number seven
UNO_number_seven_counter = []


players = int(input("Enter the number of players: "))

''''Below is a list containing as many lists as the number of players. This is to keep track of the houses of players.
 If the name of a ticket occurs twice in a list, It means it has two houses.'''

list_of_houses_of_individual_players = []

''''' 
Below list keeps track of the round number of each player and adds money if the player crosses the round.
'''''
list_of_round_number = []

# This list keeps track of the previous round number which helps in adding money
list_of_previous_round_number = []

# This is a single list which contains all throws by all players in an order.
list_of_all_throws = []

# This list has lists within it, each containing the throws of a player.
list_of_individual_throws = []

# This list contains boolean which says if the player has rent or not
list_of_player_having_rents = []

# This is a list of booleans which is useful in random decision-making
list_of_booleans = [True, False]

# In this list, each element keeps track of a players position
list_of_individual_position = []

list_of_house_tickets = []

# This list keeps track of individual balance of a player
list_of_individual_balance = []

# This is a list which contains tickets which are sold. This is useful to prevent two players from buying the same ticket
list_of_all_tickets_sold = []

# This list contains lists which contain the names of tickets owned by a player
list_of_individual_tickets = []

'''We use a two dimensional array to store all the colour tickets a player has'''
list_of_colour_tickets = []

'''We will create an array to keep track of the number of colour tickets each player has.
    This will be useful to randomly pick a colour ticket and build houses.'''

len_of_colour_tickets = []

'''A list will be used to have the position numbers of all the colur tickets a player has bought.
    so, we can use that to map the ticket number to the rent lists directly.'''

list_of_positions_of_individual_tickets = []


'''''''''''
Given below are all the dicts that we will use in the program
 The following dict will be modified whenever there is a house 
 constructed/a double rent occurs or any other way in which they are used.
'''''

# the rent of a ticket can change
dict_of_current_rents = {'England': 700,
                         'Iraq': 500,
                         'France': 300,
                         'Iran': 300,
                         'Satellite': 500,
                         'Egypt': 300,
                         'Canada': 400,
                         'Germany': 400,
                         'switzerland': 700,
                         'Brazil': 300,
                         'Italy': 200,
                         'Japan': 250,
                         'USA': 1000,
                         'Mexico': 900,
                         'Australia': 400,
                         'India': 550,
                         'Saudi Arabia': 600,
                         'China': 450,
                         'Malaysia': 200,
                         'Singapore': 300}

dict_of_double_rents = {'England': 1400,
                        'Iraq': 1000,
                        'France': 600,
                        'Iran': 600,
                        'Egypt': 600,
                        'Canada': 800,
                        'Germany': 800,
                        'switzerland': 1400,
                        'Brazil': 600,
                        'Italy': 400,
                        'Japan': 500,
                        'USA': 2000,
                        'Mexico': 1800,
                        'Australia': 800,
                        'India': 1100,
                        'Saudi Arabia': 1200,
                        'China': 900,
                        'Malaysia': 400,
                        'Singapore': 600}

dict_of_all_ticket_rents = {'England': [700, 1700, 3400, 5100, 6100],
                            'Iraq': [500, 1500, 3000, 4500, 5500],
                            'France': [300, 1300, 2600, 3900, 4900],
                            'Iran': [300, 1300, 2600, 3900, 4900],
                            'Egypt': [300, 1300, 2600, 3900, 4900],
                            'Canada': [400, 1400, 2800, 4200, 5200],
                            'Germany': [400, 1400, 2800, 4200, 5200],
                            'switzerland': [700, 1400, 3400, 5100, 6100],
                            'Brazil': [300, 1300, 2600, 3900, 4900],
                            'Italy': [200, 1200, 2400, 3600, 4600],
                            'Japan': [250, 1250, 2500, 3750, 4750],
                            'USA': [1000, 2000, 4000, 6000, 8000],
                            'Mexico': [900, 1800, 3600, 5400, 6400],
                            'Australia': [400, 1400, 2800, 4200, 5200],
                            'India': [550, 1550, 3100, 4550, 5500],
                            'Saudi Arabia': [600, 1600, 3200, 4800, 5800],
                            'China': [450, 1450, 2900, 4350, 5350],
                            'Malaysia': [200, 1200, 2400, 3600, 4600],
                            'Singapore': [300, 1300, 2600, 3900, 4900]}

# This is a variable to decide if the player wants to build a house in a particular ticket.
house_choice_maker = True


'''''''''''

We can use this i and j inside the main function to append lists or modify them.

We take user input to know the number of players. Only then can we initialize the arrays


This is the section where we initialize all arrays. One variable suffices to initialize all the arrays required.

One important catch is that, wherever we append '0', it means its a single dimensional array. Wherever we append*/

 '[]' it means it is a two dimensional array
'''''

'''''''''
Here are some variables which we will need 
'''''

counter = 0
i = 0
j = 0
current_house_ticket = ""

'''The below variable will be used to randomly select the position of the ticket in which the player will ra
    -ndomly build a house'''

position_of_current_house_ticket = 0

while counter < players:
    list_of_houses_of_individual_players.append([])
    counter=counter+1

counter = 0

while counter < players:
    list_of_round_number.append(0)
    list_of_previous_round_number.append(0)
    counter += 1

counter = 0

while counter < players:
    UNO_number_seven_counter.append(0)
    counter += 1

counter = 0

while counter < players:
    list_of_player_having_rents.append(True)
    counter += 1

counter = 0

while counter < players:
    list_of_individual_throws.append([])
    counter += 1

counter = 0

while counter < players:
    list_of_individual_tickets.append([])
    counter += 1

counter = 0

while counter < players:
    list_of_individual_balance.append(round(100000 / players))  # Initializing the initial money
    counter += 1

counter = 0

while counter < players:
    list_of_individual_position.append(0)
    counter += 1

counter = 0

while counter < players:
    list_of_colour_tickets.append([])
    counter += 1

counter = 0

while counter < players:
    len_of_colour_tickets.append(0)
    counter += 1

counter = 0

while  counter < players:
    list_of_positions_of_individual_tickets.append([])
    counter +=1

counter = 0

''''The main program begins'''

while players > 1:
    while counter < players:
        # Player number Counter has to throw. We use the random function to generate random throws.
        throw = random.randint(2, 12)
        # list_of_individual_throws contains lists within it. Each list has all the throws of a player.
        #                                 The first list has the throws of the first player and so on
        list_of_individual_position[counter] = sum(list_of_individual_throws[counter])
        current_position = list_of_individual_position[counter]
        list_of_previous_round_number[counter] = int(current_position / 36)
        list_of_all_throws.append(throw)
        list_of_individual_throws[counter].append(throw)
        list_of_individual_position[counter] += throw
        current_position = list_of_individual_position[counter]
        # current_position keeps track of the total blocks covered till the current throw
        player_position = current_position % 36

        current_ticket = tickets[player_position]
        list_of_round_number[counter] = int(current_position / 36)

        #This is to give 2000 whenever the player crosses start
        if list_of_round_number[counter] - list_of_previous_round_number[counter] == 1:
            list_of_individual_balance[counter] += 2000
        if not list_of_player_having_rents[counter]:
            if current_position - UNO_number_seven_counter[counter] >= 36 * 5:
                list_of_player_having_rents[counter] = True
        # These are placed below because if throw = 3 or 8 and player lands in UNO, the player would end up paying twice
        #           if these were placed below UNO
        if player_position == 9:
            list_of_individual_balance[counter] -= (players - 1) * 200
            i=0
            while i < players:
                if i != counter:
                    list_of_individual_balance[i] += 200
                i = i + 1
            i = 0
        elif player_position == 18:
            list_of_individual_balance[counter] += (players - 1) * 200
            while i < players:
                if i != counter:
                    list_of_individual_balance[i] -= 200
                i = i + 1
            i = 0
        elif player_position == 27:
            list_of_individual_balance[counter] -= 500

        elif player_position == 13:
            list_of_individual_balance[counter] -= len(list_of_positions_of_individual_tickets[counter])

        if player_position != 0 and player_position != 4 and player_position != 9 and player_position != 13 \
                and player_position != 16 and player_position != 18 and player_position != 21 \
                and player_position != 25 and player_position != 27 and player_position != 29 \
                and not check(list_of_all_tickets_sold, current_ticket):

            '''We use the random module to make random decision to buy a ticket'''

            if random.choice(list_of_booleans):
                list_of_all_tickets_sold.append(current_ticket)
                list_of_individual_tickets[counter].append(current_ticket)
                list_of_individual_balance[counter] -= ticket_prices[player_position]
                if not check(list_of_while_tickets,current_ticket):
                        list_of_positions_of_individual_tickets[counter].append(current_position)

        elif player_position == 4 or 25:
            if throw != 7 and throw != 3 and throw != 8:
                list_of_individual_balance[counter] += jackpot_UNO(players, throw, list_of_house_tickets,
                                                                   list_of_individual_tickets[counter])
            elif throw == 7:
                if random.choice(list_of_booleans):
                    list_of_player_having_rents[counter] = True
                    list_of_individual_balance[counter] -= 5000
                else:
                    list_of_player_having_rents[counter] = False
                    UNO_number_seven_counter[counter] = current_position
            elif throw == 3:
                list_of_individual_balance[counter] -= 500
                current_position = list_of_round_number[counter] * 36 + 27
                player_position = 27
            elif throw == 8:
                list_of_individual_balance[counter] += (players - 1) * 200
                while i < players:
                    if i != counter:
                        list_of_individual_balance[i] -= 200
                    i = 1 + 1
                i = 0
        elif player_position == 16 or player_position == 29:
            list_of_individual_balance[counter] += jackpot_chance(list_of_individual_tickets[counter], players, throw)

        elif check(list_of_all_tickets_sold, current_ticket):
            while i < players:
                if i != counter and current_ticket != 'UNO' and current_ticket != 'Chance' and \
                        current_ticket != 'Customs duty' and current_ticket != 'Travelling Duty' and current_ticket != 'Jail'\
                        and current_ticket != 'Party House' and current_ticket != 'Resort' and current_ticket != 'Start':

                    if check(list_of_all_tickets_sold, current_ticket):
                        list_of_individual_balance[counter] -= dict_of_current_rents[current_ticket]
                        while j < players:
                            if check(list_of_individual_tickets[j],current_ticket):
                                list_of_individual_balance[j]+=dict_of_current_rents[current_ticket]
                            j = j + 1
                        j = 0
                i += 1
            i = 0
        list_of_colour_tickets[counter] = colour_tickets(list_of_while_tickets,list_of_individual_tickets[counter])
        len_of_colour_tickets[counter] = len(list_of_colour_tickets[counter])

        # SELL TICKETS IF BALANCE IS LESS THAN ZERO

        # time to build houses if balance is greater than zero
        house_choice_maker = random.choice(list_of_booleans)
    if len(list_of_individual_tickets[counter]) != 0:
        while house_choice_maker and list_of_individual_balance[counter] > 0 and len(list_of_individual_tickets[counter]) > 0:

            position_of_current_house_ticket = random.choice(list_of_positions_of_individual_tickets[counter])
            '''current_house_ticket = tickets[position_of_current_house_ticket]'''
            if list_of_number_of_houses[position_of_current_house_ticket] < 4 and (list_of_house_prices[position_of_current_house_ticket] - list_of_individual_balance[counter]) > 0:
                list_of_house_tickets.append(current_house_ticket)
                list_of_houses_of_individual_players[counter].append(current_house_ticket)
                list_of_individual_balance[counter] -= list_of_house_prices[position_of_current_house_ticket]
                list_of_number_of_houses[position_of_current_house_ticket] += 1
            house_choice_maker = random.choice(list_of_booleans)
        current_ticket_rents = current_rent_of_all_tickets(list_of_individual_tickets[counter], list_of_house_tickets,current_ticket_rents)

        if list_of_individual_balance[counter] < 0:
            while list_of_individual_balance[counter] < 0 and len(list_of_individual_tickets[counter]) > 0:
                sold_ticket = random.choice(list_of_individual_tickets[counter])
                list_of_individual_balance[counter] += dict_of_mortgage_prices[sold_ticket]
                while check(list_of_house_tickets, sold_ticket):
                    list_of_house_tickets.remove(sold_ticket)
                list_of_all_tickets_sold.remove(sold_ticket)
            if len(list_of_individual_tickets[counter]) == 0:
                players -= 1

        print(list_of_individual_balance[counter])
        print(tickets[player_position])
        print(current_position)
        print(list_of_individual_throws[counter])
        print(list_of_individual_tickets[counter])
        print('end')
        counter += 1
    counter = 0


# player_plot_list = []
# while counter2 < players:
# player_plot_list.append(counter2 + 1)
# counter += 1
# plt.plot(player_plot_list, list_of_individual_balance)
# plt.show()
