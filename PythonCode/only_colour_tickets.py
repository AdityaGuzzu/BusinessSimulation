"""We use this module to extract only the colour tickets. This is particularly useful in dealing with UNO, chance etc
    and also in constructing houses"""

def colour_tickets(white_tickets, current_player_tickets):
    #Current player tickets contain all tickets owned by the player.
    #White tickets is a list containing all the white tickets
    list_of_only_colour_tickets = []
    for i in current_player_tickets:
        checker = False
        for j in white_tickets:
            if i == j:
                checker = True
        #IF checker is true, it means one of the tickets is a white ticket. We do not need it.
        if not checker:
            list_of_only_colour_tickets.append(i)
    return list_of_only_colour_tickets