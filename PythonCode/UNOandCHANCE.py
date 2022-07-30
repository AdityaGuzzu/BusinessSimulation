from BusinessBoard.Uno_number_nine import *
def jackpot_chance(lst,players,throw):
    def only_colour_tickets(lst):
        counter = 0
        for i in lst:
            if i == 'Waterways' or i == 'Satellite' or i == 'Airways' or i == 'Roadways' or i == 'Petroleum' or i == 'Railways':
                counter += 1
        return len(lst) - counter
    chance = [0, 0, -2000, +2500, -1000, +1000, -1500, + (players - 1)*only_colour_tickets(lst)*100, -3000, +2000, -500, +1500, -200]
    return chance[throw]
def jackpot_UNO(players,throw, house_list, ticket_list_of_the_player):
    UNO = [0, 0, +(players - 1)*500, -500, +2500, -2500, +2000, -5000, +(players - 1)*200,
           UNOnumber9(ticket_list_of_the_player, house_list), +1500, -1500, 3000]
    return UNO[throw]
