from BusinessBoard.listchecker import *
all_normal_tickets_rents_dict = {'England': [700, 1700, 3400, 5100, 6100],
                  'Iraq': [500, 1500, 3000, 4500, 5500],
                  'France': [300, 1300, 2600, 3900, 4900],
                  'Iran': [300, 1300, 2600, 3900, 4900],
                  'Egypt': [300, 1300, 2600, 3900, 4900],
                  'Canada': [400, 1400, 2800, 4200, 5200],
                  'Germany': [400, 1400, 2800, 4200, 5200],
                  'Switzerland': [700, 1400, 3400, 5100, 6100],
                  'Brazil': [300, 1300, 2600, 3900, 4900],
                  'Italy': [200, 1200, 2400, 3600, 4600],
                  'Japan': [250, 1250, 2500, 3750, 4750],
                  'USA': [1000, 2000, 4000, 6000, 8000],
                  'Mexico': [900, 1800, 3600, 5400, 6400],
                  'Hong Kong': [200, 1200, 2400, 3600, 4600],
                  'Australia': [400, 1400, 2800, 4200, 5200],
                  'India': [550, 1550, 3100, 4550, 5500],
                  'Saudi Arabia': [600, 1600, 3200, 4800, 5800],
                  'China': [450, 1450, 2900, 4350, 5350],
                  'Malaysia': [200, 1200, 2400, 3600, 4600],
                  'Singapore': [300, 1300, 2600, 3900, 4900]}
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
dict_of_white_double_rents = {"Waterways": 2200,
                              'Satellite': 1000,
                              'Roadways': 1500,
                              'Railways': 2500,
                              'Airways': 2500,
                              'Petroleum': 1000}
tickets = ["Start", "England", "Iraq", "Waterways", "UNO", "France", "Iran", "Satellite", "Egypt", "Resort", "Canada",
           "Germany", "Airways", "Customs duty", "Switzerland", "Brazil", "Chance", "Italy", "Party House", "Japan",
           "USA", "Travelling Duty", "Roadways", "Mexico", "Hong Kong", "UNO", "Australia", "Jail", "India", "Chance",
           "Saudi Arabia", "Petroleum", "China", "Railways", "Malaysia", "Singapore"]
red_tickets = ["England", "France", "Germany", "Switzerland", "Italy"]
blue_tickets = ["Japan", "Hong Kong", "China", "India", "Singapore"]
green_tickets = ["Iraq", "Iran", "Egypt", "Saudi Arabia", "Malaysia"]
yellow_tickets = ["Canada", "Brazil", "USA", "Mexico", "Australia"]
white_double_rent_pair = [['Waterways', 'Satellite'], ['Airways', 'Petroleum'], ['Railways', 'Roadways']]
def current_rent_of_all_tickets(lst, house_tickets, current_ticket_rents):
    for i in lst:
        if i != 'Airways' and i != 'Waterways' and i != 'Satellite' and i != 'Roadways' and i != 'Petroleum'\
                and i != 'Railways':
            current_ticket = all_normal_tickets_rents_dict[i]
            number_of_houses = house_tickets.count(i)
            selected_ticket = all_normal_tickets_rents_dict[i]
            if check(i,lst):
                current_ticket_rents[i] = selected_ticket[number_of_houses]
    emp_lst = []
    r = check_val(lst,red_tickets)
    if len(r) >= 3:
        for i in r:
            if not check(i, house_tickets):
                emp_lst.append(r)
    b = check_val(lst, blue_tickets)
    if len(b) >= 3:
        for i in b:
            if not check(i, house_tickets):
                emp_lst.append(b)
    g = check_val(lst, green_tickets)
    if len(g) >= 3:
        for i in g:
            if not check(i, house_tickets):
                emp_lst.append(g)
    y = check_val(lst, yellow_tickets)
    if len(y) >= 3:
        for i in y:
            if not check(i, house_tickets):
                emp_lst.append(y)
    for i in emp_lst:
        current_ticket_rents[i] = dict_of_double_rents[i]
    for i in white_double_rent_pair:
        if white_double_rent_checker(lst, i):
            for z in i:
                current_ticket_rents[z] = dict_of_white_double_rents[z]
    return current_ticket_rents



